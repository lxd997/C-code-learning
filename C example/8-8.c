#include <stdio.h> 
#define N 3
void main()
{
    void convert(int a[][N]);
    int i,j,arr[N][N];
    printf("请输入数组元素的值:\n");
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            scanf("%d",&arr[i][j]);
    convert(arr);
    printf("\n转置之后的矩阵为:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%4d",arr[i][j]);
        printf("\n");
    }
}
void convert(int a[][N])
{
    int i,j,t;
    for(i=0;i<N;i++)
        for(j=0;j<i;j++)
        {
            t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
        }
}