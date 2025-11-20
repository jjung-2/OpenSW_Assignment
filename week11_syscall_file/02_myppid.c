#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t mypid = getpid();
    pid_t myppid = getppid();

    printf("pid : %lu\n", (unsigned long)mypid);
    printf("ppid : %lu\n", (unsigned long)myppid);

    return 0;
}