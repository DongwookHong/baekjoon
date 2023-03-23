#include <stdio.h>

void numsize(int min, int y)
{
    return min > y?min:y; 
}

void check(int num ,int *cnt)
{
    
    if(num ==1)
        return ; 
    (*cnt)++; 
    printf("num 의값은 %d\n",num); 
    
    if(num%3 == 0)check(num/3,cnt);
    if(num%2 == 0)numsize(check(num%2,cnt), check(num-1,cnt));
    else
        check(num-1,cnt);
}

int main(){
    int a; 
    scanf("%d",&a);
    if(a ==1)
        printf("%d",a);
    else
    { 
        int cnt =0;
        check(a,&cnt);
        printf("%d",cnt);
    }
}