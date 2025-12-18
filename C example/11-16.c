/*编写程序，求解“约瑟夫问题”。由n个人围成一圈，
对他们从1开始依次编号，现指定从第m个人开始报数，报到第s个数时，
该人员出列，然后从下一个人开始报数，仍是报到第s个数时，人员出列，
如此重复，直到所有人都出列。输出人员的出列顺序*/
/*例11_16 example 11_16.c 用结构体解决约瑟夫问题*/
#include <stdio.h>
struct person
{
    int num;    /*本人的序号*/
    int next;   /*下一个人的序号*/
};
void OutQueue(int m,int n,int s,struct person ring[]);
void main()
{
    struct person ring[100];
    int i,n,m,s;
    printf("请输入人数n(1~99): ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)   /*对人员编号*/
    {
        ring[i].num=i;
        if(i==n)
            ring[i].next=1;
        else
            ring[i].next=i+1;
    }
    printf("人员编号为:\n");    /*输出人员编号*/
    for(i=1;i<=n;i++)
    {
        printf("%6d",ring[i].num);
        if(i%10==0)
            printf("\n");
    }
    printf("\n请输入开始报数的编号m(1~100): ");
    scanf("%d",&m);
    printf("报到第几个数出列s(1~100): ");
    scanf("%d",&s);
    printf("出列顺序: \n");
    OutQueue(m,n,s,ring);
}
void OutQueue(int m,int n,int s,struct person ring[])
{
    int i,j,count;
    if(m==1)
        j=n;
    else
        j=m-1;
    for(count=1;count<=n;count++)
    {
        i=0;
        while (i!=s)
        {
            j=ring[j].next;
            if(ring[j].num!=0)
            i++;
        }
        printf("%6d",ring[j].num);
        ring[j].num=0;
        if(count%10==0)
            printf("\n");
    }
}
