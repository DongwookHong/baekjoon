//백준 s2 문제 1012 | 유기농 배추 (좌표를 선언해서 풀어보기)

#include <stdio.h>
#include <stdlib.h>

int arr[51][51];
int M, N;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    arr[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < M && ny >= 0 && ny < N && arr[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
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