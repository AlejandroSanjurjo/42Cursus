/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprimir_mapa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanjurj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:40:37 by asanjurj          #+#    #+#             */
/*   Updated: 2024/10/21 13:49:30 by asanjurj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char *ft_strdup(const char *s)
{
    char *dup;
    size_t len = strlen(s) + 1;

    dup = (char *)malloc(len);
    if (!dup)
        return NULL;
    memcpy(dup, s, len);
    return dup;
}

char **read_map(const char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return NULL;
    }

    char buffer[1024];
    int bytes_read = read(fd, buffer, 1024);
    if (bytes_read <= 0)
    {
        perror("Error al leer el archivo");
        close(fd);
        return NULL;
    }
    buffer[bytes_read] = '\0';

    char **map = malloc(100 * sizeof(char *));
    int row = 0;
    char *line = strtok(buffer, "\n");
    while (line != NULL)
    {
        map[row++] = ft_strdup(line);
        line = strtok(NULL, "\n");
    }
    map[row] = NULL;
    close(fd);
    return map;
}

mlx_image_t* load_image(mlx_t* mlx, char* path)
{
    mlx_texture_t* texture = mlx_load_png(path);
    if (!texture)
    {
        printf("Error al cargar la textura: %s\n", path);
        return NULL;
    }
    mlx_image_t* image = mlx_texture_to_image(mlx, texture);
    return image;
}

void draw_map(mlx_t *mlx, mlx_image_t* wall_img, mlx_image_t* floor_img, mlx_image_t* player_img, mlx_image_t* coll_img , mlx_image_t* exit_img, char **map)
{
    int x, y;

    for (int row = 0; map[row] != NULL; row++)
    {
        for (int col = 0; map[row][col] != '\0'; col++)
        {
            x = col * 64;
            y = row * 64;

        	if (map[row][col] == '1' && wall_img)
        	        mlx_image_to_window(mlx, wall_img, x, y);
        	else
        	{
                	mlx_image_to_window(mlx, floor_img, x, y);
			if (map[row][col] == 'P' && player_img)
                		mlx_image_to_window(mlx, player_img, x, y);
                	else if (map[row][col] == 'C' && coll_img)
                		mlx_image_to_window(mlx, coll_img, x, y);
                	else if (map[row][col] == 'E' && exit_img)
                		mlx_image_to_window(mlx, exit_img, x, y);
                }
        }
    }
}

int main(void)
{
    char **map = read_map("map.ber");
    if (!map)
    {
        printf("Error al leer el mapa.\n");
        return (1);
    }
    mlx_t *mlx = mlx_init(512, 512, "map.ber", true);
    if (!mlx)
        return (1);

    mlx_image_t *wall_img = load_image(mlx, "./wall.png");
    mlx_image_t *floor_img = load_image(mlx, "./floor.png");
    mlx_image_t *player_img = load_image(mlx, "./player.png");
    mlx_image_t *coll_img = load_image(mlx, "./coll.png");
    mlx_image_t *exit_img = load_image(mlx, "./exit.png");

   

    draw_map(mlx, wall_img, floor_img, player_img,coll_img,exit_img, map);

    mlx_loop(mlx);

    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    mlx_terminate(mlx);

    return (0);
}

