#include <stdio.h>

#define min(a,b) a >b? b:a
#define max 10000000
int num[max];
int main()
{
    int k =0;
    scanf("%d" ,&k);
    num[1]= 0;

    for(int i =2; i <=k ;i++)
    {
      num[i]= num[i-1]+1;
      if (i %2 ==0)
        num[i]= min(num[i/2]+1,num[i]);
      if(i %3 == 0)
         num[i]= min(num[i/3]+1,num[i]);
    }
    printf("%d", num[k]);
}