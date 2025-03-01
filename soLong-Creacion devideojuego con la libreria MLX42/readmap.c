#include "so_long.h"

static int	handle_error(const char *msg, char **map, int rows, int fd)
{
	int	i;

	if (fd >= 0)
		close(fd);
	if (map)
	{
		for (i = 0; i < rows; i++)
			free(map[i]);
		free(map);
	}
	perror(msg);
	return (0);
}

static char	**allocate_map(void)
{
	char	**map;

	map = malloc(MAX_ROWS * sizeof(char *));
	if (!map)
		perror("Error al asignar memoria para el mapa");
	return (map);
}

static int	read_file(const char *path, char *buffer)
{
	int	fd;
	int	bytes_read;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (-1);
	}
	bytes_read = read(fd, buffer, 1023);
	if (bytes_read <= 0)
	{
		close(fd);
		perror("Error al leer el archivo");
		return (-1);
	}
	buffer[bytes_read] = '\0';
	close(fd);
	return (0);
}

static int	fill_map(char **map, char *buffer)
{
	char	*line;
	int		row;

	row = 0;
	line = strtok(buffer, "\n");
	while (line != NULL)
	{
		map[row] = strdup(line);
		if (!map[row])
			return (handle_error("Error al duplicar línea del mapa", map, row, -1));
		row++;
		line = strtok(NULL, "\n");
	}
	map[row] = NULL;
	return (1);
}

char	**read_map(const char *path)
{
	char	buffer[1024];
	char	**map;

	if (read_file(path, buffer) == -1)
		return (NULL);
	map = allocate_map();
	if (!map)
		return (NULL);
	if (!fill_map(map, buffer))
		return (NULL);
	return (map);
}
