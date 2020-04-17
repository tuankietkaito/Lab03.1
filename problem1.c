#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("number.txt", "rb");

    char buff[100];
    int a[100];
    int n = 0;

    // while(fscanf(fp, "%[^\n]\n", buff) != EOF)
    // {
    //     arr[size++] = atoi(buff);
    // }

    while (fgets(buff, sizeof(buff), fp) != NULL)
    {
        a[n++]=atoi(buff);
    }

    fclose(fp);

    pid_t pid;
    pid = fork();

    if (pid == 0)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
            if (a[i] % 3 == 0)
                count++;

        printf("%d\n", count);
        fflush(stdout);
        return 0;
    }
    else
    {
        int count = 0;
        for (int i = 0; i < n; i++)
            if (a[i] % 2 == 0)
                count++;
        printf("%d\n", count);
        fflush(stdout);
        return 0;
    }
    return 0;
}
