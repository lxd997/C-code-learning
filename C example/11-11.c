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
void print(struct student *head);
struct student *del(struct student *head, int num);
struct student *insert(struct student *head,struct student *stud);
void main()
{
    struct student *head ,*stu;
    int n;
    int del_num;
    printf("input the number of the record:\n");
    scanf("%d",&n);
    head=create(n);
    print(head);
    printf("input the deleted number:\n");
    scanf("%d",&del_num);
    head=del(head,del_num);
    print(head);
    printf("\ninput the inserted record\n");
    stu=(struct student *)malloc(LEN);
    scanf("%d%f",&stu->num,&stu->score);
    head=insert(head,stu);
    print(head);
}
/*例11-8 example11_8.c 动态链表的建立和输出*/
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
/*例11-9 example11_9.c 输出链表函数*/
void print(struct student *head)
{
    struct student *p;
    p=head;
    while(p!=NULL)
    {
        printf("%d,%6.2f\n",p->num,p->score);
        p=p->next;
    }
}
/*例11-10 example11_10.c 删除动态链表结点函数*/
struct student *del(struct student *head, int num)
{
    struct student *p1, *p2; // 定义两个工作指针：p1当前节点，p2前驱节点
    /*-- 1. 检查链表是否为空 --*/
    if (head == NULL) {                   // 如果链表是空的
        printf("\n list null\n");         // 提示空链表
        return head;                      // 直接返回空指针
    }
    /*-- 2. 初始化指针，开始查找目标节点 --*/
    p1 = head;                            // p1从头节点开始找（就像火车头出发）
    while (num != p1->num && p1->next != NULL) // 循环条件：当前节点不是目标 且 后面还有节点
    {
        p2 = p1;                          // p2记住当前节点位置（像记录火车经过的车厢）
        p1 = p1->next;                    // p1移动到下一个节点（像走到下一节车厢）
    }
    /*-- 3. 判断是否找到目标节点 --*/
    if (num == p1->num)                   // 如果找到了目标学号
    {
        if (p1 == head)                   // 情况1：目标节点是头节点（要删火车头）
            head = p1->next;              // 新头节点是原第二节（火车头换成下一节）
        else                              // 情况2：目标在中间或尾部
            p2->next = p1->next;          // 前驱节点跳过当前节点（前车厢挂钩连到后车厢）
        printf("delete %d\n", num);       // 提示删除成功
    }
    else                                  // 没找到目标节点
    {
        printf("%d not has been found\n", num); // 提示未找到
    }
    /*-- 4. 返回更新后的链表头 --*/
    return head;                          // 返回可能被修改的链表头
}
/*插入结点的函数insert如下*/
struct student *insert(struct student *head,struct student *stud)
{
    struct student *p0,*p1,*p2;
    p1=head;
    p0=stud;
    if(head==NULL) /*原来的链表是空表*/
    {head=p0;p0->next=NULL;}
    else
    {
        while ((p0->num>p1->num)&&(p1->next!=NULL))
        {p2=p1; p1=p1->next;}
        if(p0->num<=p1->num)
        {
            if(head==p1) head=p0;
            else p2->next=p0;
            p0->next=p1;
        }
        else
        {p1->next=p0;p0->next=NULL;}
    }
    return head;
}