#include "so_long.h"

bool    validate_borders(char tile, int row, int col, int rows, int cols)
{
    if ((row == 0 || col == 0 || row == rows - 1 || col == cols - 1) && tile != '1')
    {
        printf("Error: El mapa debe estar rodeado de paredes.\n");
        return (false);
    }
    return (true);
}

bool    count_elements(t_game_data *game_data, t_map_data *map_data, int *exit_count, int *player_count)
{
    int row, col;

    row = 0;
    while (game_data->map[row])
    {
        col = 0;
        while (game_data->map[row][col])
        {
            char tile = game_data->map[row][col];
            if (tile == 'E')
                (*exit_count)++;
            else if (tile == 'P')
            {
                (*player_count)++;
                game_data->player_x = col;
                game_data->player_y = row;
            }
            else if (tile == 'C')
                game_data->total_collectibles++;
            if (!validate_borders(tile, row, col, map_data->rows, map_data->cols))
                return (false);
            col++;
        }
        row++;
    }
    return (true);
}

bool    validate_elements(t_game_data *game_data, t_map_data *map_data, int *exit_count, int *player_count)
{
    if (!count_elements(game_data, map_data, exit_count, player_count))
        return (false);
    if (*exit_count != 1 || *player_count != 1 || game_data->total_collectibles < 1)
    {
        printf("Error: Elementos inválidos en el mapa.\n");
        return (false);
    }
    return (true);
}