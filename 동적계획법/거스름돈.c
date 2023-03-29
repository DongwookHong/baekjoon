#include <stdio.h>
#define max 100000
#define bigger(a,b) (a >b) ?a:b;
int money[max];


// int chceck( int a)
// {
//     int num=0;
//     int cnt=0;
//     if(a== 0)
//         return cnt;
//     if(a%5==0|| a%2 ==0)
//         bigger(check(a-5),check(a-2));
//     else
//         check(a);
//     return cnt;

// }


int main(){
int n; 
scanf("%d", &n);
int cnt =0;


int sum;

    if(n%5 == 0)
        cnt = n/5;
    else if((n%5 !=0) )
    {
        if((n/5)%2 ==0)
        {
            sum = (n/5);
            cnt = sum+ sum/2;
        }
        else if((n/2)==0)
            cnt= n/2;
    }
    
    printf("%d",cnt);
}