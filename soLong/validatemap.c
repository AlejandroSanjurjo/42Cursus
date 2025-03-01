#include "so_long.h"

int valid_map(t_game_data *game_data)
{
    t_map_data map_data;
    int exit_count;
    int player_count;

    exit_count = 0;
    player_count = 0;
    game_data->total_collectibles = 0;

    if (!setup_map_data(game_data, &map_data))
        return (0);

    if (!validate_elements(game_data, &map_data, &exit_count, &player_count))
    {
        freememorie(map_data.visited, map_data.rows);
        return (0);
    }

    dfs(&map_data, game_data->player_x, game_data->player_y);
    if (!check_accessible(game_data, map_data.visited))
    {
        freememorie(map_data.visited, map_data.rows);
        return (0);
    }

    freememorie(map_data.visited, map_data.rows);
    return (1);
}