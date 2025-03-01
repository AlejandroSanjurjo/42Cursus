#include "so_long.h"

void    free_resources(t_game_data *game_data)
{
    if (game_data->map)
    {
        int i = 0;
        while (game_data->map[i])
            free(game_data->map[i++]);
        free(game_data->map);
    }
}

void    cleanup_game(t_game_data *game_data)
{
    free_resources(game_data);
    if (game_data->mlx)
    {
        mlx_terminate(game_data->mlx);
        game_data->mlx = NULL;
    }
}
