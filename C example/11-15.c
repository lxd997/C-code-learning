/*一副扑克牌除去大王和小王还有4种花色，每种花色13张牌，共有52张。
设计一个洗牌和发牌的程序，用H代表红桃，D代表方块，C代表梅花，S代表黑桃，
用1~13代表每一种花色的面值*/
/*分析：可用结构体类型来表示扑克牌的花色和面值
struct card {
    char *face; //面值
    char *suit; //花色
};     */
/*例11_15 example11_15.c 洗牌算法*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct card {
    char *face; //面值
    char *suit; //花色
}; 
typedef struct card Card;
void fillDeck(Card *,char *[],char *[]);
void shuffle(Card *);
void deal(Card *);
void main()
{
    Card deck[52];
    char *face[]={"1","2","3","4","5","6","7","8","9","10","11","12","13"};
    char *suit[]={"H","D","C","S"};
    srand(time(NULL));
    fillDeck(deck,face,suit);
    shuffle(deck);
    deal(deck);
}
void fillDeck(Card *wDeck,char *wFace[],char *wSuit[])
{
    int i;
    for(i=0;i<=51;i++)
    {
        wDeck[i].face=wFace[i%13];
        wDeck[i].suit=wSuit[i/13];
    }
}
void shuffle(Card *wDeck)
{
    int i,j;
    Card temp;
    for(i=0;i<=51;i++)
    {
        j=rand() % 52;
        temp=wDeck[i];
        wDeck[i]=wDeck[j];
        wDeck[j]=temp;
    }
}
void deal(Card *wdeck)
{
    int i;
    for(i=0;i<=51;i++)
        printf("%2s--%2s%c",wdeck[i].suit,wdeck[i].face,(i+1)%4?'\t':'\n');
}