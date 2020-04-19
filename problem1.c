#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    FILE *fp;
    fp = fopen("number.txt", "rb");

    char buff[100];
    int a[100];
    int n = 0;

    while (fgets(buff, sizeof(buff), fp) != NULL)
    {
        int assigned = sscanf(buff, "%d", &a[n]);
        n++;
    }

    pid_t pid;
    pid = fork();
    int res;

    if (pid > 0)
    {
        res = 0;
        for (int i = 0; i < n; i++)
            if (a[i] % 2 == 0)
                res++;
        printf("%d\n", res);
        fflush(stdout);
    }
    else if (pid == 0)
    {
        res = 0;
        for (int i = 0; i < n; i++)
            if (a[i] % 3 == 0)
                res++;
        printf("%d\n", res);
        fflush(stdout);
    }

    fclose(fp);
    return 0;
}
