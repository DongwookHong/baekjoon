#include <stdio.h>

#define max 10

int pizza[max];


void pizza_num()
{
    int a;
    scanf("%d",&a);

    pizza[1] =0;
    pizza[2]= 1;
    pizza[3] =3;

    int num;
    for(int i =4; i <= a; i++)
    {
        num = i/2;
        if(i%2 ==0)
            pizza[i] = (num* num)+2*(pizza[num]);
        else
        {
            pizza[i] = ((num+1)* num)+pizza[(num+1)]+pizza[num];
        }
    }
    printf("%d",pizza[a]);
}


int main()
{
    pizza_num();
}