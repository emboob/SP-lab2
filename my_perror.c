/**
 * 실습문제 5번 my_perror() 구현
 * 파일 이름 : my_perror.c
 * 만든이 : 20153265 김동현
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void my_perror(char *userInput)
{
    if (userInput == NULL)
    {
        printf("%s\n", strerror(errno));
    }
    else
    {
        printf("%s: %s\n", userInput, strerror(errno));
    }
}

int main(int argc, char *argv[])
{
    FILE *f;

    if (argc < 2)
    {
        printf("Usage : perror_use nofilename\n");
        exit(1);
    }

    if  ((f=fopen(argv[1], "r")) == NULL )
    {
        my_perror(NULL);
        my_perror("dongdong");
        printf("\n");
        perror(NULL);
        perror("dongdong");
        exit(1);
    }

    printf("Open a file \"%s\".\n", argv[1]);

    fclose(f);
}
