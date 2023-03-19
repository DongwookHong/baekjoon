#include <stdio.h>
#include <string.h>

#define MAX 1001
                  
int adj[MAX][MAX]; //인접행렬 만들때 사용 
int visited[MAX]; //방문했는지 check  
 
void init(int N) {
    for(int i=1; i<=N; i++) {
        visited[i] = 0; //방문한곳 0으로 초기화 !
    }
}
 
// 모든 컴포넌트 방문
// void DFSAll(int N);
 
void DFS(int here, int N) { //정점과 정점개수
    int there;
    
    visited[here] = 1; //방문 check
    printf("%d ", here); //정점 출력
    
    for(int i = 1; i <= N; i++) {
        if(adj[here][i]) {
            there = i;
            if(!visited[there]) {
                DFS(there, N); //발견하자마자 바로 함수로 다시 들어가
            }
        }
    }
}
 
int main() {
    int N,M,v; // 정점개수, 간선개수, 시작정점
    int x,y; // 좌표
    
    scanf("%d %d %d", &N, &M, &v);
    for(int i=1; i<=M; i++) { //M(간선개수) 만큼
        scanf("%d %d", &x,&y);
        adj[x][y]=1;
        adj[y][x]=1; //인접행렬 만들기
    }
        
    //DFS 호출
    DFS(v, N);
    
    return 0;
}