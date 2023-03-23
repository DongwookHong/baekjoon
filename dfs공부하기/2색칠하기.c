#include <stdio.h>
#define max 1000
int N, M;
int check[max][max];
int visited[max];
int color[max];
int black[max];

void bfs(int st)
{
    visited[st] = 1;
    if (!black[st])
        color[st] = 1;
    int y;
    for (int i = 0; i < N; i++)
    {
        if (check[st][i] == 1)
        {
            if (color[st])
                black[i] = 1;
            y = i;
            if (!visited[y])
                bfs(y);
        }
    }
}

int check_color()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (check[i][j] == 1 && color[i] ==1 && black[i]==1)
                return -1;
        }

    }
   
    return 1;
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        check[a][b] = 1;
        check[b][a] = 1;
    }
    bfs(0);
    int k; 
    k = check_color();
    if (k == -1)
        printf("NO\n");
    else 
        printf("YES\n");
  
    return 0;
}

