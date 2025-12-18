#include "stdio.h"
#include "string.h"
void main()
{
    char s11[40]="university",s22[20]="qingdao";
    //printf("复制函数的结果:");
    //puts(strcpy(s11,s22));
    //strcpy(字符串组1，字符串2);
    //其功能是将字符串2复制到字符数组1中去
    printf("复制4个字符的结果:");
    puts(strncpy(s11,s22,4));
    //如strncpy(str1,str2,2)是指把字符串str2中的前2个字符复制到str1中取代str1中原有的最前的2个字符
    /*还有字符串比较函数strcmp(字符串1，字符串2)
      字符串长度测试函数strlen(字符数组)
      strlwrh函数是把字符串中的大写字母转换成小写字母
      strupr函数是把字符串中的小写字母转换成大写字母
      相关的字符串处理函数详见附录C-3,其他字符串函数等等*/
}