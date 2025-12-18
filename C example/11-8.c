/*例11-8 example11_8.c动态链表的建立和输出*/
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct student)
struct student
{
    int num;
    float score;
    struct student *next;
};
struct student *create(int n);
void main()
{
    struct student *p;
    p=create(5);
    while(p!=NULL)
    {
        printf("%d,%6.2f\n",p->num,p->score);
        p=p->next;
    }
}
struct student *create(int n)
{
    struct student *head ,*p1,*p2;
    int i;
    head=p2=(struct  student*)malloc(LEN);
    printf("input num and score:\n");
    scanf("%d%f",&p2->num,&p2->score);
    for(i=2;i<=n;i++)
    {
        p1=(struct  student*)malloc(LEN);
        printf("input Number and score:\n");
        scanf("%d%f",&p1->num,&p1->score);
        p2->next=p1;
        p2=p1;
    }
    p2->next=NULL;
    return (head);
}