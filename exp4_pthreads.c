#include <stdio.h>
#include <pthread.h>

void *display(void *arg)
{
    int n = *(int *)arg;

    printf("Thread %d is running\n", n);
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int a = 1, b = 2;

    pthread_create(&t1, NULL, display, &a);
    pthread_create(&t2, NULL, display, &b);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads completed\n");
    return 0;
}
