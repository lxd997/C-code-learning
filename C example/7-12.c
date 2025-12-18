/*折半查找法*/
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
void main()
{
    int i,j,t,data[20],key;
    int flag=0,head,bottom,middle;
    srand(time(NULL));
    //随机产生20个整数
    for(i=0;i<20;i++)
        data[i]=rand()%100;
    //输出随机产生的整数
    printf("随机产生的整数数组为:");
    for (i = 0; i < 20; i++)
    {
        /* code */
        if(i%5==0) printf("\n");
        printf("%d ",data[i]);
    }
    printf("\n");
    //输入准备查找的整数
    printf("Input the locating data key:");
    scanf("%d",&key);
    //按照从小到大的顺序排序
    for(i=0;i<19;i++)
        for(j=0;j<19-i;j++)
            if(data[j]>data[j+1])
            {
                t=data[j];
                data[j]=data[j+1];
                data[j+1]=t;
            }
    //输出排序后的整数数组
    printf("排序后的整数数组为:");
    for(i=0;i<20;i++)
    {
        if(i%5==0) printf("\n");
        printf("%d ",data[i]);
    }
    printf("\n");
    //输出要查找的整数
    printf("the locating data key is:%d\n",key);
    head=0;
    bottom=19;
    while(head<=bottom)
    {
        middle=(head+bottom)/2;
        if(data[middle]<key)
            head=middle+1;
        else if(data[middle]>key)
            bottom=middle-1;
        else if(key==data[middle])
            {
                flag=1;
                break;
            }
    }
    if(flag==1)
    printf("您查找的数为:%d,匹配成功！\n",key);
    else printf("您查找的数为:%d,匹配失败,您要找的数不在数组中！\n",key);
}