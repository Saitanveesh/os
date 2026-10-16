#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int a, b, n;
    char s[50], d[50], buf[100];

    printf("Enter Source File Name: ");
    scanf("%49s", s);

    printf("Enter Destination File Name: ");
    scanf("%49s", d);

    if (strcmp(s, d) == 0)
    {
        printf("Use different filenames\n");
        return 1;
    }

    a = open(s, O_RDONLY);
    if (a < 0)
    {
        printf("Source file not found\n");
        return 1;
    }

    b = open(d, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (b < 0)
    {
        printf("Destination file error\n");
        close(a);
        return 1;
    }

    while ((n = read(a, buf, 100)) > 0)
        write(b, buf, n);

    close(a);
    close(b);

    printf("File copied successfully\n");
    return 0;
}
