#include "so_long.h"

static int	handle_up(t_game *game);
static int	handle_down(t_game *game);
static int	handle_left(t_game *game);
static int	handle_right(t_game *game);

int	handle_movement(t_game *game, int key_code)
{
	switch (key_code)
	{
		case XK_W:
			return (handle_up(game));
		case XK_S:
			return (handle_down(game));
		case XK_A:
			return (handle_left(game));
		case XK_D:
			return (handle_right(game));
		default:
			return (1);
	}
}

static int	handle_up(t_game *game)
{
	t_matrix	*m;
	t_player	*p;
	char	tile_type;

	m = game->map;
	p = &game->player;
	tile_type = ((char *) m->values[p->row - 1])[p->column];
	if (tile_type == WALL)
		return (1);
	if (tile_type == COLLECTIBLE)
		game->collectibles--;
	((char *) m->values[p->row--])[p->column] = EMPTY;
	((char *) m->values[p->row])[p->column] = PLAYER;
	p->moves++;
	return (0);
}

static int	handle_down(t_game *game)
{
	t_matrix	*m;
	t_player	*p;
	char	tile_type;

	m = game->map;
	p = &game->player;
	tile_type = ((char *) m->values[p->row + 1])[p->column];
	if (tile_type == WALL)
		return (1);
	if (tile_type == COLLECTIBLE)
		game->collectibles--;
	((char *) m->values[p->row++])[p->column] = EMPTY;
	((char *) m->values[p->row])[p->column] = PLAYER;
	p->moves++;
	return (0);
}

static int	handle_left(t_game *game)
{
	t_matrix	*m;
	t_player	*p;
	char	tile_type;

	m = game->map;
	p = &game->player;
	tile_type = ((char *) m->values[p->row])[p->column - 1];
	if (tile_type == WALL)
		return (1);
	if (tile_type == COLLECTIBLE)
		game->collectibles--;
	((char *) m->values[p->row])[p->column--] = EMPTY;
	((char *) m->values[p->row])[p->column] = PLAYER;
	p->moves++;
	return (0);
}

static int	handle_right(t_game *game)
{
	t_matrix	*m;
	t_player	*p;
	char	tile_type;

	m = game->map;
	p = &game->player;
	tile_type = ((char *) m->values[p->row])[p->column + 1];
	if (tile_type == WALL)
		return (1);
	if (tile_type == COLLECTIBLE)
		game->collectibles--;
	((char *) m->values[p->row])[p->column++] = EMPTY;
	((char *) m->values[p->row])[p->column] = PLAYER;
	p->moves++;
	return (0);
}
