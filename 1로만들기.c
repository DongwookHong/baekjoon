#include <stdio.h>
#include <stdbool.h>

int arr[101][101];
bool visited[101][101];
int xarr[4] = {0, 0, -1, 1};
int yarr[4] = {-1, 1, 0, 0};
int N;
int count[101];
int rain = 0;
int ans[101];
int p = 0;

void bfs(int x, int y, int k)
{
    visited[x][y] = true;
    count[rain]++;
    int xd, yd;
    for (int i = 0; i < 4; ++i)
    {
        xd = xarr[i] + x;
        yd = yarr[i] + y;
        if (xd < 1 || yd < 1 || xd > N || yd > N)
            continue;
        if (!visited[xd][yd] && arr[xd][yd] >= k)
            bfs(xd, yd, k);
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            scanf("%d", &arr[i][j]);
    
    int max = 0;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            if(arr[i][j] > max)
                max = arr[i][j]; // max 값 찾기

    for(int k = 0; k <= max; ++k) 
    {
        // bfs 탈출하면 vistited 초기화
        for(int q = 1; q <= N; ++q)
            for(int r = 1; r <= N; ++r)
                visited[q][r] = false;
        rain = 0;

        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= N; ++j){
                if (!visited[i][j] && arr[i][j] >= k)
                {
                    bfs(i, j, k);
                    rain++;
                }
            }
        }
        for (int i = 0; i < rain; ++i)
        {
            if(count[i] != 0)
                ans[p]++;
            count[i] = 0;
        }
        ++p;
    }

    int answer = 0;
    for(int i = 0; i < p; ++i)
        if(ans[i] > answer)
            answer = ans[i];
    
    printf("%d", answer);

    return 0;
}