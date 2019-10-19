/**
 * 실습문제 5번 my_assert() 구현
 * 파일 이름 : my_assert.c
 * 만든이 : 20153265 김동현
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define STRINGFY(x) #x
#define FALSE 0
#define TRUE 1

int my_assert(int expression)
{
    if (expression == FALSE)
    {
        printf("%s: %s:%d: ", __func__,__FILE__, __LINE__);
        
        return FALSE;
    }
    else 
        return TRUE;
}

void foo(int num)
{
    if (my_assert(((num >= 0) && (num <= 100))) == FALSE)
    {
        printf("%s: Assertion '%s' failed.\n", __func__,
            STRINGFY(((num >= 0) && (num <= 100))));
        abort();
    }

    printf("foo : num = %d\n", num);
}

int main(int argc, char *argv[])
{
    int num;

    if (argc < 2)
    {
        fprintf(stderr, "Usage : my_assert_test aNumber\n(0 <= Number <= 100)\n");
        exit(1);
    }

    num = atoi(argv[1]);
    foo(num);
}
