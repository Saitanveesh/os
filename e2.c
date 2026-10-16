#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();

    if (pid == 0)
    {
        printf("Child PID: %d, PPID: %d\n", getpid(), getppid());
    }
    else if (pid > 0)
    {
        printf("Parent PID: %d, PPID: %d\n", getpid(), getppid());
        wait(0);
    }
    else
    {
        printf("Fork failed\n");
    }

    return 0;
}
