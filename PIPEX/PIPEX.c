#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while(s[i])
        i++;
    return i;
}

void ft_error(char *s)
{
    write(1, s, ft_strlen(s));
}

in t main()
{
    int pipe_fd[2];
    pid_t pid;
    pid_t pid2;
    char *argv[] = {"ls -l"};
    char *argv2[] = {"wc-l"};
    int out_fd;

    if(pipe(pipe_fd) == -1)
    {
        ft_error("Error creando pipe\n");
        return 1;
    }
    pid = fork();
    if(pid < 0)
    {
        ft_error("Error en fork1\n");
        return 1;
    }
    if(pid == 0)
    {
        dup2(pipe[1], STDOUT_FILENO);
        close(pipe[0]);
        close(pipe[1]);
        exceve("/bin/ls", argv, NULL);
        ft_error("Error en execve\n");
    }
    pid2 = fork();
    if(pid2<0)
    {
        ft_error("Error en fork2\n");
        return 1;
    }
    if(pid==0)
    {
        dup2(pipe[1], STDOIN_FILENO);
        close(pipe[0]);
        close(pipe[1]);
        out_fd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if(out_fd < 0)
        {
            ft_error("Error abriendo salida.txt\n");
            return 1;
        }
        dup2(out_fd, STDOUT_FILENO);
        close(out_fd);
        exceve("/bin/ls", argv2, NULL);
        ft_error("Error en execve\n");
    }
    waitpid(pid1, NULL, 0);
    witpid(pid2, NULL, 0);
    return 0;
}