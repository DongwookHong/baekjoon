#include <stdio.h>
#define big(a,b) a>b? a:b
#define max 110
#include <stdlib.h>




int lose[max];
int ppl[22]
int happy[max];

void swap_temp(int *a, int *b)
{
    int temp =0;
    if(*a > *b )
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}


void hi(){
    int num;
    scanf("%d", &num);
    int hp = 100;
    for(int i = 1; i<= num; i++)
        scanf("%d", lose[i]);

    for(int i = 1; i<= num; i++)
        scanf("%d", happy[i]);
   
    

}


int main(){

}