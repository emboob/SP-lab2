/**
 * lab 2-1 사칙연산 함수들을 정적, 공유 라이브러리로 만드는 main문
 * 파일 이름 : dlcalculator.c
 * 만든이 : 20153265 김동현
 */
#include <stdio.h>
#include "arithmaticlib.h"

int main()
{
    double num1, num2;
    
    printf("계산기 프로그램입니다!\n");
    printf("첫 번째 수는 : ");
    scanf("%lf", &num1);
    printf("두 번째 수는 : ");
    scanf("%lf", &num2);

    printf("%lf + %lf = %lf\n", num1, num2, add(num1, num2));
    printf("%lf - %lf = %lf\n", num1, num2, subtract(num1, num2));
    printf("%lf * %lf = %lf\n", num1, num2, multiply(num1, num2));
    printf("%lf / %lf = %lf\n\n", num1, num2, divide(num1, num2));

    printf("감사합니다.\n");

    return 0;
}
