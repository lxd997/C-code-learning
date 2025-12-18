/*example11_6.c使用指向结构体变量的指针作为函数参数*/
#include <stdio.h>
#define NUM 10
struct student *search_max(struct student *pstu,int n);
struct student
{
    int num;
    char name[10];
    int age;
    float score[3];
};
void input(struct student *pstu,int n);
void main()
{
    struct student stu[NUM],*pmax;
    int j;
    input(stu,NUM);
    pmax=search_max(stu,NUM);
    printf("name=%s\nage=%d\n",pmax->name,pmax->age);
    for(j=0;j<3;j++)
        printf("%6.2f",pmax->score[j]);
    printf("\n");
}
void input(struct student *pstu,int n)
{
    int i;
    for(i=0;i<n;i++,pstu++)
    {
        printf("input num,name,age,three score:\n");
        scanf("%d%s%d%f%f%f",&pstu->num,pstu->name,&pstu->age,
        &pstu->score[0],&pstu->score[1],&pstu->score[2]);
    }
}
/*查找总分最高的学生记录*/
struct student * search_max(struct student *pstu,int n)
{
    int i,k=0;
    float sum,max=0;
    for(i=0;i<n;i++)
    {
        sum=(pstu+i)->score[0]+(pstu+i)->score[1]+(pstu+i)->score[2];
        if(max<sum)
        {
            max=sum;
            k=i;
        }
    }
    return pstu+k;
}