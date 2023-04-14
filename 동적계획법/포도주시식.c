//2156 포도주 시식

//1.포도주 선택 다마시기 
//2. 연속 3잔 x

#include <stdio.h>
#define max 10005
int dp [max];
int content[max];
int c_max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

void drink(){

    // freopen("input.txt","r",stdin);
    int a;
    scanf("%d",&a);
    for(int i=1; i<=a; i++)
        scanf("%d", &content[i]);
    dp[0]= 0;
    dp[1]= content[1];
    dp[2]= content[1] +content[2];
    for(int i=3; i<=a; i++)
    {
        dp[i]= c_max(c_max(dp[i-3]+content[i-1]+ content[i],dp[i-1]),dp[i-2]+content[i]);
    }
    printf("%d",dp[a]);
}


int main()
{
    drink();
}
