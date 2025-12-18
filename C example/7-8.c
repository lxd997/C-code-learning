#include "stdio.h"
void main()
{
    int i,j,a[3][4];
    int row,column,min;
    printf("Input 3*4 二维数组:\n");
    for(i=0;i<3;i++)
        for(j=0;j<4;j++)
    scanf("%d",&a[i][j]);
        min=a[0][0];row=0;column=0;
    for(i=0;i<3;i++)
        for(j=0;j<4;j++)
            if(a[i][j]<min)
            {
                min=a[i][j];
                row=i;
                column=j;
            }
    printf("min=%d,row=%d,column=%d\n",min,row,column);
}