/**
 * 실습 문제 9번 학생을 동적 할당하여 트리 탐색을 하는 프로그램.
 * 파일 이름 : student_tree_search.c
 * 만든이 : 20153265 김동현
 */
#include <stdio.h>
#include <search.h>
#include <string.h>
#include <stdlib.h>

/* 학생 구조체 : 이름, 중간고사 점수, 기말고사 점수, 합계 점수 */
struct node {
    char *name;
    int midterm_score;
    int final_score;
    int total_score;
};

struct node *root = NULL;

/* 탐색중인 노드의 위치를 비교 */
int compare(const void *cp1, const void *cp2)
{
    return strcmp(((struct node *)cp1)->name,
        ((struct node *)cp2)->name);
}

/* twalk 가 노드를 처음 만나게 되면 출력됨 */
void print_student_node(const void *nodeptr, VISIT order, int level)
{
    if (order == preorder || order == leaf)
        printf("\n이름 = %-10s,\n 중간고사 점수 = %d점,\n 기말고사 점수 = %d점,\n 합계 점수 = %d점\n",
            (*(struct node **)nodeptr) -> name,
            (*(struct node **)nodeptr) -> midterm_score,
            (*(struct node **)nodeptr) -> final_score,
            (*(struct node **)nodeptr) -> total_score);
}

int main()
{
    int i, j;
    int num_students;
    
    struct node **ret;

    printf("학생의 수를 입력하세요 : ");
    scanf("%d", &num_students);

    /* 입력받은 크기 만큼의 이름을 저장할 테이블 */
    char nametable[num_students * 20];
    char *nameptr = nametable;
    
    /* 입력받은 크기 만큼의 노드가 담길 테이블 */
    struct node nodetable[num_students];
    struct node *nodeptr = nodetable;

    struct node *nodap;

    /* 학생 구조체를 사용하여 사용자가 입력한 수 만큼 메모리 할당 */
    nodeptr = (struct node*)malloc(num_students * sizeof(struct node));

    for(i=1; i<num_students+1; i++)
    {
        printf("\n%d 번 학생의 정보를 입력합니다.\n", i);
        printf("%d 번 학생의 이름을 입력하세요 : ", i);
        scanf("%s", nameptr);
        printf("%d 번 학생의 중간고사 점수를 입력하세요 : ", i);
        scanf("%d", &nodeptr->midterm_score);
        printf("%d 번 학생의 기말고사 점수를 입력하세요 : ", i);
        scanf("%d", &nodeptr->final_score);

        nodeptr->total_score = nodeptr->midterm_score + nodeptr->final_score;
        
        nodeptr->name = nameptr;

        /* 트리에 넣기 */    
        ret = (struct node**)tsearch((void *)nodeptr,
            (void **)&root, compare);
        printf("\"%s\" 님", (*ret)->name);
        if (*ret == nodeptr)
        {
            printf("이 트리에 추가되었습니다.\n");
        }
        else
        {
            printf("은 트리에 이미 존재합니다\n");
        }

        nameptr += strlen(nameptr) +1;
        nodeptr++;
    }

    twalk((void *)root, print_student_node);

    free(nodeptr - num_students);    

    printf("\n");

    return 0;
}
