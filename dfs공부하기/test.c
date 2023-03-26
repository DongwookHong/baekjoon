#include <stdio.h>
 
const int MAX_NM = 300 + 10;
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };
int N, M, ans;
int map[MAX_NM][MAX_NM];
int visited[MAX_NM][MAX_NM];
void Flood_Fill(int x, int y, int v) {
    visited[x][y] = v;
    int waterCnt = 0;
    for (int i = 0; i < 4; i++) {
        int nX = x + dx[i];
        int nY = y + dy[i];
        // 외곽은 바다(0)로 채워져 있으므로 범위 초과 X
        if (visited[nX][nY] == v)
            continue;
        // 동서남북 중에 바다인 곳
        if (map[nX][nY] <= 0)
            waterCnt++;
        // 바다가 아닌 곳은 (재귀)탐색
        else Flood_Fill(nX, nY, v);
    }
    map[x][y] -= waterCnt;
}
int findSection(void) {
    int time = 0, v = 1;
    while (1) {
        int cnt = 0;
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < M; j++) {
                // 방문하지 않은 빙산이 존재하는 경우
                if ((map[i][j] > 0) && (visited[i][j] != v)) {
                    cnt++;
                    Flood_Fill(i, j, v);
                }
            }
        }
        // 모두 녹은 경우
        if (cnt == 0) return 0;
        // 빙산이 2개 이상으로 분리된 경우
        if (cnt > 1) return time;
        time++; v++;
    }
}
int main(void) {
    // freopen("input.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    ans = findSection();
    printf("%d\n", ans);
}