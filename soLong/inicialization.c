#include "so_long.h"

static bool load_images(t_game_data *game_data)
{
    game_data->wall_img = load_image(game_data->mlx, "./wall.png");
    game_data->floor_img = load_image(game_data->mlx, "./floor.png");
    game_data->player_img = load_image(game_data->mlx, "./player.png");
    game_data->coll_img = load_image(game_data->mlx, "./coll.png");
    game_data->exit_img = load_image(game_data->mlx, "./exit.png");
    return (game_data->wall_img && game_data->floor_img && game_data->player_img &&
            game_data->coll_img && game_data->exit_img);
}

bool    initialize_game(t_game_data *game_data, const char *map_path)
{
    ft_memset(game_data, 0, sizeof(t_game_data));
    game_data->map = read_map(map_path);
    if (!game_data->map)
    {
        printf("Error al leer el mapa.\n");
        return (false);
    }
    if (!valid_map(game_data))
    {
        free_resources(game_data);
        return (false);
    }
    game_data->mlx = mlx_init(512, 512, "map.ber", true);
    if (!game_data->mlx)
    {
        free_resources(game_data);
        return (false);
    }
    if (!load_images(game_data))
    {
        printf("Error al cargar las imágenes.\n");
        cleanup_game(game_data);
        return (false);
    }
    initialize_player_position(game_data);
    return (true);
}
