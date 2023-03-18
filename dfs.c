#include <stdio.h>

#define max 55;
int graph[max][max];
int vitied[max];
int stack[max];
int top -1;

void initial(){
    for(int i = 0;  i < max ; i++)
    {
        visitied[i]  = 0;
        for(int j =0 ; j < max ; j++)
        {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int a, int b)
{
    graph[a][b] = 1;
     graph[b][a] = 1;
}

void push (int node){
    stack[++top] = node;
}
int  pop(){
    return stack[--top];
}

void dfs(int start) {
    visited[start] = 1; // 시작 노드 방문 처리
    push(start); // 시작 노드를 스택에 저장

    while (top != -1) { // 스택이 빌 때까지 반복
        int node = pop(); // 스택에서 정점을 꺼냄
        printf("%d ", node); // 정점 출력

        // 현재 노드와 연결된 모든 노드를 탐색
        for (int i = 0; i < max; i++) {
            if (graph[node][i] && !visited[i]) { // 인접한 노드이면서 방문하지 않은 노드인 경우
                visited[i] = 1; // 해당 노드를 방문 처리
                push(i); // 스택에 저장
            }
        }
    }
}
