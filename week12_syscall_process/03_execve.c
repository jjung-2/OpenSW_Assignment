#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <program path> [OPTION]...\n", argv[0]);
        exit(0);
    }

    pid_t child_pid = fork();

    if(child_pid == 0)
    {
        execve(argv[1], &argv[1], NULL);
        if(execve(argv[1], &argv[1], NULL) == -1)
        {
            perror(argv[1]);
            exit(1);
        }
    }
    else
    {
        int wstate;

        waitpid(child_pid, &wstate, 0);

        if(WIFEXITED(wstate))
        {
            printf("Child exited with status: %d\n", WEXITSTATUS(wstate));
        }
    }
    
    return 0;
}