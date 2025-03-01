#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

# ifndef MAX_ROWS
#  define MAX_ROWS 100
# endif

# ifndef MAX_COLS
#  define MAX_COLS 100
# endif

# include "MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

typedef struct s_game_data
{
    mlx_t *mlx;
    char **map;
    mlx_image_t *wall_img;
    mlx_image_t *floor_img;
    mlx_image_t *player_img;
    mlx_image_t *coll_img;
    mlx_image_t *exit_img;
    int player_x;
    int player_y;
    int coleccionable;
    int colected;
} t_game_data;

typedef struct s_map
{
    char **map;
    int rows;
    int cols;
    int total_collectibles;
    int exit_x;
    int exit_y;
} t_map;

void	draw_map(t_game_data *game_data);
bool    validate_borders(char tile, int row, int col, int rows, int cols);
bool    count_elements(t_game_data *game_data, t_map_data *map_data, int *exit_count, int *player_count);
bool    validate_elements(t_game_data *game_data, t_map_data *map_data, int *exit_count, int *player_count);
void    freememorie(bool **visited, int rows);
bool    **visit(int rows, int cols);
bool    setup_map_data(t_game_data *game_data, t_map_data *map_data);
void    dfs(t_map_data *map_data, int x, int y);
bool    check_accessible(t_game_data *game_data, bool **visited);
bool    initialize_game(t_game_data *game_data, const char *map_path)
void    ft_memset(void *b, int c, size_t len);
int valid_map(t_game_data *game_data);
void    free_resources(t_game_data *game_data);
void    cleanup_game(t_game_data *game_data);
void    collect_item(t_game_data *game_data);
void    initialize_player_position(t_game_data *game_data);
void move_player(int keycode, t_game_data *game_data);
char	**read_map(const char *path);
char    *ft_strdup(const char *s);
mlx_image_t*    load_image(mlx_t* mlx, const char* path);
void    handle_key(mlx_key_data_t keydata, void *param);
#endif