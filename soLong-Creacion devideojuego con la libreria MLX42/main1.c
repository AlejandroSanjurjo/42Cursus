#include "so_long.h"

// Función para duplicar una cadena
char    *ft_strdup(const char *s)
{
    char    *dup;
    size_t  len;
    
    len = strlen(s) + 1;
    dup = (char *)malloc(len);
    if (!dup)
        return NULL;
    memcpy(dup, s, len);
    return dup;
}
// Función para cargar una imagen
mlx_image_t*    load_image(mlx_t* mlx, const char* path)
{
    mlx_texture_t*  texture;
     mlx_image_t* image;
    texture = mlx_load_png(path);
    if (!texture)
    {
        printf("Error al cargar la textura: %s\n", path);
        return NULL;
    }
    image = mlx_texture_to_image(mlx, texture);
    if (!image)
    {
        printf("Error al convertir la textura en imagen: %s\n", path);
        mlx_delete_texture(texture);
        return NULL;
    }
    mlx_delete_texture(texture);
    return image;
}
// Función de callback para manejar los eventos del teclado
void    handle_key(mlx_key_data_t keydata, void *param)
{
    t_game_data *game_data;
    game_data = (t_game_data *)param;

    if (keydata.action == MLX_PRESS)
    {
        move_player(keydata.key, game_data);
        draw_map(game_data);
    }
}
//ber si es .ber
bool is_ber(char *file)
{
    bool flag;
    while(*file && *file != '.')
        file++;
    if (!(*file == '.'))
       return false;
    flag = true;
    file++;
    if (*file == 'b' && *(file + 1) == 'e' && *(file + 2) == 'r'
        && *(file + 3) == '\0')
        return true;
    return false;
}

int main(int argc. char **argv)
{
    t_game_data game_data;

    if(!is_ber(argv[1]))
    {
        write(1, "Error\nEl archivo no es un archivo .ber\n", 39);
        return (1);
    }
    if (!initialize_game(&game_data, argv[1]))
        return (1);
    draw_map(&game_data);
    mlx_key_hook(game_data.mlx, handle_key, &game_data);
    mlx_loop(game_data.mlx);
    cleanup_game(&game_data);
    return (0);
}



