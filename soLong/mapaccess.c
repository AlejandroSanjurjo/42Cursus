#include "so_long.h"

void    dfs(t_map_data *map_data, int x, int y)
{
    if (x < 0 || y < 0 || x >= map_data->cols || y >= map_data->rows ||
        map_data->map[y][x] == '1' || map_data->visited[y][x])
        return;

    map_data->visited[y][x] = true;

    dfs(map_data, x + 1, y);
    dfs(map_data, x - 1, y);
    dfs(map_data, x, y + 1);
    dfs(map_data, x, y - 1);
}

bool    check_accessible(t_game_data *game_data, bool **visited)
{
    int row;
    int col;

    row = 0;
    while (game_data->map[row])
    {
        col = 0;
        while (game_data->map[row][col])
        {
            if ((game_data->map[row][col] == 'C' || game_data->map[row][col] == 'E') &&
                !visited[row][col])
            {
                printf("Error: No todos los coleccionables o la salida son accesibles.\n");
                return (false);
            }
            col++;
        }
        row++;
    }
    return (true);
}