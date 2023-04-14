//2156 포도주 시식

//1.포도주 선택 다마시기 
//2. 연속 3잔 x

#include <stdio.h>
#define max 10005
int dp [max];
int arr[max];
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
        scanf("%d", &arr[i]);
    dp[1]= arr[1];
    dp[2]= arr[1] +arr[2];
    for(int i=3; i<=a; i++)
        dp[i]= c_max(dp[i-2]+arr[i],c_max(dp[i-3]+arr[i-1]+ arr[i],dp[i-1]));
    printf("%d",dp[a]);
}


int main()
{
    drink();
}
