/**
 * lab 2-1 사칙연산 함수들을 동적 라이브러리로 만드는 main문
 * 파일 이름 : dlcalculator.c
 * 만든이 : 20153265 김동현
 */
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    double (*add)(double, double);
    double (*subtract)(double, double);
    double (*multiply)(double, double);
    double (*divide)(double, double);
    double num1, num2;
    char *error;

    handle = dlopen("./lib/libarithmatic.so", RTLD_LAZY);
    if (!handle)
    {
        fputs(dlerror(), stderr);
        exit(1);
    }
    add = dlsym(handle, "add");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s", error);
        exit(1);
    }
    subtract = dlsym(handle, "subtract");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s", error);
        exit(1);
    }
    multiply = dlsym(handle, "multiply");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s", error);
        exit(1);
    }
    divide = dlsym(handle, "divide");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s", error);
        exit(1);
    }
    
    printf("계산기 프로그램입니다!\n");
    printf("첫 번째 수는 : ");
    scanf("%lf", &num1);
    printf("두 번째 수는 : ");
    scanf("%lf", &num2);

    printf("%lf + %lf = %lf\n", num1, num2, (*add)(num1, num2));
    printf("%lf - %lf = %lf\n", num1, num2, (*subtract)(num1, num2));
    printf("%lf * %lf = %lf\n", num1, num2, (*multiply)(num1, num2));
    printf("%lf / %lf = %lf\n\n", num1, num2, (*divide)(num1, num2));

    printf("감사합니다.\n");

    dlclose(handle);
    
    return 0;
}
