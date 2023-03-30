#include <stdio.h>

#define min(a,b) a>b? b:a
#define max 5000

int del[max];

int main(){
    int candy;
    scanf("%d", &candy);
    del[1] = -1;
    del[2] = -1;
    del[3] =  1;
    del[4] = -1;
    del[5] = 1;
    del[6] = 2;
    del[7] = -1;

    for(int i = 8 ; i<=candy; i++)
    {
    
        del[i] = del[i-5]+1;
        if(del[i] == 0)
            del[i] = del[i-3]+1;
        if(i%5 == 0)
            del[i]=min(del[i],del[i]/5);
        if(i%3 == 0)
            del[i]=min(del[i],del[i]/3);
       
    }
    printf("%d",del[candy]);
}