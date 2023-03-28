
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX_SIZE 501
#define MAX(a,b) a<b?b:a

int Graph[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

int N, ans,k=1;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void Input_Data() {
	scanf("%d", &N);
	for (int x = 0; x < N; x++){
		for (int y = 0; y < N; y++) {
			visited[x][y] = -1;
			scanf("%d", &Graph[x][y]);
		}
	}
}

int DFS(int x_, int y_) {
	if (visited[x_][y_] != -1) {
		return visited[x_][y_];
	}
	visited[x_][y_] = 1;

	for (int i = 0; i < 4; i++) {
		int nextX = dx[i] + x_;
		int nextY = dy[i] + y_;

		if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N) {
			if (Graph[x_][y_] < Graph[nextX][nextY]) {
				int day = 1;
				day += DFS(nextX, nextY);
				visited[x_][y_] = MAX(visited[x_][y_], day);
				if (visited[x_][y_] > k) k = visited[x_][y_];
			}
		}
	}
	return visited[x_][y_];
}

void Solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == -1)
				DFS(i, j);
		}
	}
}

int main() {
	Input_Data();
	Solve();
	printf("%d\n", k);

	return 0;
}