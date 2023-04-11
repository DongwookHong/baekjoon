#include <stdio.h>
#include <stdlib.h>

int arr[51][51];
int M, N;

void dfs(int x, int y)
{
    arr[x][y] = 0;

    if (x - 1 >= 0 && arr[x-1][y] == 1)        
        dfs(x-1, y);
    if (y - 1 >= 0 && arr[x][y-1] == 1)
        dfs(x, y-1);
    if (x + 1 < M && arr[x+1][y] == 1)
        dfs(x+1, y);
    if (y + 1 < N && arr[x][y+1] == 1)
        dfs(x, y+1);
    
}

int main()
{
    int T;
    scanf("%d", &T);
    int K, a, b, cnt;
    for (int i=0; i<T; i++)
    {
        scanf("%d %d %d", &M, &N, &K);
        for (int j=0; j<K; j++)
        {
            scanf("%d %d", &a, &b);
            arr[a][b] = 1;
        }
        cnt = 0;
        for (int k=0; k<M; k++)
        {
            for (int z=0; z<N; z++)
            {
                if (arr[k][z])
                {
                    dfs(k, z);
                    cnt++;
                }     
            }
        }
        printf("%d\n", cnt);
    }
}