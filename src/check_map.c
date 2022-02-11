#include "so_long.h"

static void	check_walls(t_game *game);
static void	check_other_components(t_game *game);

void	check_map(t_game *game)
{
	check_walls(game);
	check_other_components(game);
}

static void	check_walls(t_game *game)
{
	int	is_valid;
	size_t	r;
	size_t	c;
	char	*map_row;

	is_valid = 1;
	r = -1;
	while (++r < game->map->rows && is_valid)
	{
		map_row = (char *) game->map->values[r];
		if (r == 0 || r == game->map->rows - 1)
		{
			c = 0;
			while (c < game->map->columns && is_valid)
				is_valid = map_row[c++] == WALL;
		}
		else
			is_valid = map_row[0] == WALL
				&& map_row[game->map->columns - 1] == WALL;
	}
	if (is_valid)
		return ;
	errno = EINVAL;
	game->error = ft_strdup("Map description is not surrounded by walls");
	exit_with_error(game);
}

static size_t	get_component_index(char c);
static char	*get_component_information(size_t idx);

static void	check_other_components(t_game *game)
{
	size_t	r;
	size_t	c;
	size_t	*components;
	char	*row;

	r = 0;
	components = ft_calloc(5, sizeof(*components));
	while (++r < game->map->rows - 1)
	{
		row = (char *) game->map->values[r];
		c = 0;
		while (++c < game->map->columns - 1)
			components[get_component_index(row[c])]++;
	}
	c = 1;
	while (++c < 5)
		if (!components[c])
			break ;
	free(components);
	if (c == 5)
		return ;
	errno = EINVAL;
	game->error = ft_strjoin("Map description lacks at least one component of type ", get_component_information(c));
	exit_with_error(game);
}

static size_t	get_component_index(char c)
{
	return (ft_strchr(MAP_COMPONENTS, c) - MAP_COMPONENTS);
}

static char	*get_component_information(size_t idx)
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
