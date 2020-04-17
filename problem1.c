#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>

struct Node {

};

int main(int argc, char* argv[]) {

    FILE* fp;

    char line[100];
    int arr[100];
    int size=0;
    fp = fopen("number.txt", "rb");
    while(fscanf(fp, "%[^\n]\n", line) != EOF)
    {
        arr[size++] = atoi(line);
    }
    fclose(fp); 

    pid_t pid;
    pid = fork();

    if (pid == 0) {
        int count = 0;
        for(int i=0 ;i<size; i++)
            if(arr[i] % 3 == 0)
                count++;

        printf("%d\n",count);
        fflush (stdout) ;
        return 0;

    }
    else{
        int count = 0;
        for(int i=0 ;i<size; i++)
            if(arr[i] % 2 == 0)
                count++;
        printf("%d\n", count);
        fflush (stdout) ;
        return 0;
    }
    return 0;
}
