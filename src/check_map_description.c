#include "so_long.h"

static void	check_walls(t_error *error, t_matrix *md);
static void	check_other_components(t_error *error, t_matrix *md);

void	check_map_description(t_matrix *md)
{
	t_error	error;

	check_walls(&error, md);
	check_other_components(&error, md);
}

static void	check_walls(t_error *error, t_matrix *md)
{
	int	is_valid;
	size_t	r;
	size_t	c;

	is_valid = 1;
	r = -1;
	while (++r < md->rows && is_valid)
	{
		if (r == 0 || r == md->rows - 1)
		{
			c = 0;
			while (c < md->columns && is_valid)
				is_valid = md->values[r][c++] == WALL;
		}
		else
			is_valid = md->values[r][0] == WALL
				&& md->values[r][md->columns - 1] == WALL;
	}
	if (is_valid)
		return ;
	errno = EINVAL;
	error->message = ft_strdup("Map description is not surrounded by walls");
	error->matrix = md;
	exit_with_error(error);
}

size_t	get_component_index(char c);
char	*get_component_information(size_t idx);

static void	check_other_components(t_error *error, t_matrix *md)
{
	size_t	r;
	size_t	c;
	size_t	*components;

	r = 0;
	components = ft_calloc(5, sizeof(size_t));
	while (++r < md->rows - 1)
	{
		c = 0;
		while (++c < md->columns - 1)
			components[get_component_index(md->values[r][c])]++;
	}
	c = 1;
	while (++c < 5)
		if (!components[c])
			break ;
	free(components);
	if (c == 5)
		return ;
	errno = EINVAL;
	error->message = ft_strjoin("Map description lacks at least one component of type ", get_component_information(c));
	error->matrix = md;
	exit_with_error(error);
}

size_t	get_component_index(char c)
{
	return (ft_strchr(MAP_COMPONENTS, c) - MAP_COMPONENTS);
}

char	*get_component_information(size_t idx)
{
	switch (idx)
	{
		case 0:
			return ("0 (EMPTY)");
		case 1:
			return ("1 (WALL)");
		case 2:
			return ("C (COLLECTIBLE)");
		case 3:
			return ("E (EXIT)");
		case 4:
			return ("P (PLAYER)");
		default:
			return (NULL);
	}
}
