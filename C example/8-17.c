/*编写一个函数，实现给定某年某月某日，将其转换成这一年的第几天并输出*/
#include <stdio.h>
int tab[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void main()
{
    int day_year(int y,int m,int d);
    int year,month,day;
    printf("请输入年月日:\n");
    scanf("%d%d%d",&year,&month,&day);
    printf("是这年的第%d天\n",day_year(year,month,day));
}
int day_year(int y,int m,int d)
{
    int i,s=0;
    for(i=1;i<m;i++)
        s=s+tab[i];
    if((y%4==0&&y%100!=0||y%400==0)&&m>=3)
        s++;
    return (s+d);
}