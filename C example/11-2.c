/*example 11_2.c 建立同学通讯录*/
#include <stdio.h>
#define NUM 10
struct mem
{
    char name[20];
    char phone[10];
};
void main()
{
    struct mem man[NUM];
    int i;
    for (i = 0; i < NUM; i++)
    {
        printf("input name:\n");
        gets(man[i].name);
        printf("input phone:\n");
        gets(man[i].phone);
    }
    printf("name\t\t\tphone\n\n");
    for(i=0;i<NUM;i++)
        printf("%s\t\t\t%s\n",man[i].name,man[i].phone);
}
