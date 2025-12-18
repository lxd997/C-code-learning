#include <stdio.h>
void main()
{
    int year,month,days;
    printf("Please enter year and month:");
    scanf("%d%d",&year,&month);
    if(month<0&&month>13)
    printf("You input error data\n");
    else
    switch (month)
    {
    case 2:
        /* code */
        if(year%4==0&&year%100!=0||year%400==0)
            days=29;
        else
            days=28;
        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:days=31;break;
    case 4:
    case 6:
    case 9:
    case 11:days=30;break;
    }
    printf ("%d年%d月有%d天\n",year,month,days);

}