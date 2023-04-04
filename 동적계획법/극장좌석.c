#include <stdio.h>
int dp[41];

int main()
{
    int N;
    int M;
    int i;
    int result = 1;
    int num;
    int sub=0;

    scanf("%d %d", &N, &M);
  
    dp[1] = 1;
    dp[2] = 2;
    for (i = 3; i <=N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    for (i = 0; i < M; i++)
    {
        scanf("%d", &num);
        result *= dp[num-sub-1];
        sub = num;
    }
    result *= dp[N-sub];
    printf("%d", result);
}
