#include "so_long.h"

static void	draw_tile(t_game_data *game_data, int row, int col, int x, int y)
{
	if (game_data->map[row][col] == '1' && game_data->wall_img)
		mlx_image_to_window(game_data->mlx, game_data->wall_img, x, y);
	else
	{
		mlx_image_to_window(game_data->mlx, game_data->floor_img, x, y);
		if (game_data->map[row][col] == 'C' && game_data->coll_img)
			mlx_image_to_window(game_data->mlx, game_data->coll_img, x, y);
		else if (game_data->map[row][col] == 'E' && game_data->exit_img)
			mlx_image_to_window(game_data->mlx, game_data->exit_img, x, y);
	}
}

static void	draw_map_tiles(t_game_data *game_data)
{
	int	row;
	int	col;
	int	x;
	int	y;

	row = 0;
	while (game_data->map[row])
	{
		col = 0;
		while (game_data->map[row][col])
		{
			x = col * TILE_SIZE;
			y = row * TILE_SIZE;
			draw_tile(game_data, row, col, x, y);
			col++;
		}
		row++;
	}
}

static void	draw_player(t_game_data *game_data)
{
	int	x;
	int	y;

	x = game_data->player_x * TILE_SIZE;
	y = game_data->player_y * TILE_SIZE;
	mlx_image_to_window(game_data->mlx, game_data->player_img, x, y);
}

void	draw_map(t_game_data *game_data)
{
	draw_map_tiles(game_data);
	draw_player(game_data);
}