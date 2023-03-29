
#include <stdio.h>
#define max 1000
int dp[max];



int main()
{

    int n =0;
    scanf("%d", &n);
    dp[1]=1;
    int sum = 0;
    
    for(int i =3 ; i <=n; i++)
    {
        sum += dp[i-1];
        dp[i] = sum +1;
    }

  
    printf("%d",dp[n]%1000007);
}


