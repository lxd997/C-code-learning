#include "stdio.h"
void main()
{
    int i,j,a[2][3],b[3][2];
    printf("Input 数组a共6个元素为:\n");
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            b[j][i]=a[i][j];
    printf("Output转置后的数组元素为:\n");
    for(i=0;i<3;i++)
        for(j=0;j<2;j++)
        {
            if(j%2==0) printf("\n");
            printf("%3d ",b[i][j]);
        }
    printf("\n");
}