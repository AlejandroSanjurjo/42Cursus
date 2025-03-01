#include "so_long.h"

//funcion coleccioanbles
void    collect_item(t_game_data *game_data)
{
    int player_x;
    int player_y;

    player_x = game_data->player_x;
    player_y = game_data->player_y;

    // Verifica si el jugador está en una celda con un coleccionable
    if (game_data->map[player_y][player_x] == 'C')
    {
        // Incrementa el contador de coleccionables recogidos
        game_data->collected++;

        // Marca la celda como vacía
        game_data->map[player_y][player_x] = '0';
        // Comprueba si se han recogido todos los coleccionables
        if (game_data->collected == game_data->total_collectibles)
            printf("¡Todos los coleccionables han sido recogidos!\n");//exitavalible=true
    }
}

//inicializar player
void    initialize_player_position(t_game_data *game_data)
{
int row;
int col;

row =0;

    while ( game_data->map[row] != NULL)
    {
        col=0;
        while (game_data->map[row][col] != '\0')
        {
            if (game_data->map[row][col] == 'P')
            {
                game_data->player_x = col;
                game_data->player_y = row;
                return; // Salir después de encontrar la primera 'P'
            }
            col++;
        }
        row++
    }
}


// Función para mover al jugador
void move_player(int keycode, t_game_data *game_data)
{
    int newx;
    int newy;
    
    newx=game_data->player_x;
    newy=game_data->player_y;
    if (keycode == MLX_KEY_W )
       newy--;
    else if (keycode == MLX_KEY_S)
        newy++;
    else if (keycode == MLX_KEY_A)
        newx--;
    else if (keycode == MLX_KEY_D)
        newx++;
     if (game_data->map[newy][newx] != '1')
    {
        game_data->player_x = newx;
        game_data->player_y = newy;
        collect_item(game_data);
        draw_map(game_data);
    }
}
