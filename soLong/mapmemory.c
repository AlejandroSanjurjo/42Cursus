#include "so_long.h"

void    freememorie(bool **visited, int rows)
{
    int i;

    i = 0;
    while (i < rows)
    {
        free(visited[i]);
        i++;
    }
    free(visited);
}

bool    **visit(int rows, int cols)
{
    bool **visited;
    int i;

    visited = malloc(rows * sizeof(bool *));
    if (!visited)
        return (NULL);
    i = 0;
    while (i < rows)
    {
        visited[i] = calloc(cols, sizeof(bool));
        if (!visited[i])
        {
            while (--i >= 0)
                free(visited[i]);
            free(visited);
            return (NULL);
        }
        i++;
    }
    return (visited);
}

bool    setup_map_data(t_game_data *game_data, t_map_data *map_data)
{
    int rows = 0;

    while (game_data->map[rows])
        rows++;
    map_data->rows = rows;
    map_data->cols = strlen(game_data->map[0]);
    map_data->visited = visit(rows, map_data->cols);
    if (!map_data->visited)
        return (false);
    map_data->map = game_data->map;
    return (true);
}