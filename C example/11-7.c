/*例11-7 example11_7.c 简单的静态链表的建立*/
#include <stdio.h>
/*定义结构体类型*/
struct student
{
    int num;
    float score;
    struct student *next;
};
void main()
{
    struct student a,b,c,*head,*p;
    a.num=101;a.score=89.5;
    b.num=102;b.score=78.5;
    c.num=103;c.score=80.0; /*对结点的num和score成员赋值*/
    head=&a;                /*将结点a的起始地址赋给头指针head*/
    a.next=&b;              /*将结点b的起始地址赋给a结点的成员next*/
    b.next=&c;              /*将结点c的起始地址赋给b结点的成员next*/
    c.next=NULL;            /*结点c为表尾，将NULL赋给c结点的成员next*/
    /*输出链表中各个结点——链表的遍历*/
    p=head;
    do
    {
        printf("num:%5d\tscore:%6.2f\n",p->num,p->score);/*输出p指向的结点的数据*/
        p=p->next;                                       /*使p指向下一个结点*/
    } while (p!=NULL);
}