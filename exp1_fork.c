#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid;

    pid = fork();

    if (pid == 0)
    {
        printf("Child process created successfully\n");
        fflush(stdout);
        execlp("ls", "ls", NULL);
        printf("execlp failed\n");
    }
    else if (pid > 0)
    {
        printf("Parent process ID is %d\n", getpid());
        wait(0);
        printf("Child process completed\n");
    }
    else
    {
        printf("Fork failed\n");
    }

    return 0;
}
