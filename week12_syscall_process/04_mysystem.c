#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int mysystem(const char* command)
{
    pid_t child = fork();

    if(child == 0)
    {
        execl("/bin/sh", "sh", "-c", command, (char *) NULL);
    }
    else
    {
        int wstatus;
        waitpid(child, &wstatus, 0);
        return wstatus;
    }
}

int main()
{
    // system("ls -l | wc -l");
    // system("find . -name '*.c'");

    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");

    printf("Good Bye~\n");

    return 0;
}