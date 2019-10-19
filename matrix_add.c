/**
 * 실습 문제 8번 두 행렬을 동적으로 할당하여 두 행렬을 더하는 프로그램.
 * 파일 이름 : matrix_add.c
 * 만든이 : 20153265 김동현
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int row, col;
    int **first_matrix = NULL;
    int **second_matrix = NULL;
    int **result_matrix = NULL;

    printf("행렬의 행의 크기를 입력하세요 : ");
    scanf("%d", &row);
    printf("행렬의 열의 크기를 입력하세요 : ");
    scanf("%d", &col);

    /* 첫 번째 행렬에 사용자가 입력한 수 만큼 메모리 할당 */
    first_matrix = (int **)malloc(row * sizeof(int *));
    for(i=0; i<row; i++)
    {
        first_matrix[i] = (int *)malloc(col * sizeof(int));
    }
    if (first_matrix == NULL)
    {
        printf("첫 번째 행렬에 메모리를 할당하지 못했습니다.");
        exit(-1);
    }

    /* 두 번째 행렬에 사용자가 입력한 수 만큼 메모리 할당 */
    second_matrix = (int **)malloc(row * sizeof(int *));
    for(i=0; i<row; i++)
    {
        second_matrix[i] = (int *)malloc(col * sizeof(int));
    }
    if (second_matrix == NULL)
    {
        printf("두 번째 행렬에 메모리를 할당하지 못했습니다.");
        exit(-1);
    }

    /* 첫 번째 행렬에 값 입력 */
    printf("\n첫 번째 행렬의 값들을 차례로 입력하세요.\n");
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            scanf("%d", &first_matrix[i][j]);
        }
    }

    /* 두 번째 행렬에 값 입력 */
    printf("\n두 번째 행렬의 값들을 차례로 입력하세요.\n");
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            scanf("%d", &second_matrix[i][j]);
        }
    }

    /* 첫 번째 행렬의 값 출력 */
    printf("\n첫 번째 행렬입니다.\n");
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            printf("%d  ", first_matrix[i][j]);
        }
        printf("\n");
    }

    /* 두 번째 행렬의 값 출력 */
    printf("\n두 번째 행렬입니다.\n");
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            printf("%d  ", second_matrix[i][j]);
        }
        printf("\n");
    }

    /* 두 행렬을 더한 결과 행렬에 사용자가 입력한 수 만큼 메모리 할당 */
    result_matrix = (int **)malloc(row * sizeof(int *));
    for(i=0; i<row; i++)
    {
        result_matrix[i] = (int *)malloc(col * sizeof(int));
    }
    if (result_matrix == NULL)
    {
        printf("결과 행렬에 메모리를 할당하지 못했습니다.");
        exit(-1);
    }

    /* 두 행렬을 더한 결과 행렬에 값 할당 */
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            result_matrix[i][j] = first_matrix[i][j] + second_matrix[i][j];
        }
    }
    
    /* 결과 행렬의 값 출력 */
    printf("\n두 행렬을 더한 결과 행렬입니다.\n");
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            printf("%d  ", result_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    /* 만들어졌던 세 개의 행렬의 메모리 할당 해제 (열->행 순서) */
    for (j=0; i<row; j++)
    {
        free(first_matrix[j]);
        free(second_matrix[j]);
        free(result_matrix[j]);
    }
    free(first_matrix);
    free(second_matrix);
    free(result_matrix);

    return 0;
}
