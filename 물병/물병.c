#include <stdio.h>


int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int cnt;
    int ans=0;
    int temp =0;
    while(N > 0)
    {
        temp = N;
        cnt =0;
        while(temp > 0)
        {
            if(temp %2 != 0)
                cnt++;
            temp /= 2;
        }
        if(K >= cnt)
            break;
        ans++;
        N++;
    }
    printf("%d", ans);
    return 0;
}
