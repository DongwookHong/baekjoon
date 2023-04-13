#include <stdio.h>
#define max 40


int dp[max];
int day,cake;

void tiger()
{
    scanf("%d %d" ,&day,&cake);

  
    while(1)
    {
        
        for(int i =3; i<=day; i++)
        {
            dp[i]= dp[i-1]+dp[i-2];
            if(dp[6]== 41)
            {

            }
        }
    }
}

int main(){
    tiger();
}