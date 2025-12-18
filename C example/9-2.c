#include <stdio.h>
#define DEBUG 1
void main()
{
    int i,j;
    char ch[26];
    for(i='a',j=0;i<='z';i++,j++)
    {
        ch[j]=i;
        #if DEBUG
            printf("ch[%d]=%c\n",j,ch[j]);
        #endif
    }
    for(j=0;j<26;j++)
        printf("%c",ch[j]);
    printf("\n");
}