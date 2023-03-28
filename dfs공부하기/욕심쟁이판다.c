#include <stdio.h>
#define MAX(a,b) a<b?b:a
int N;
int move[505][505];
int copy[505][505];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int jump= -999;

int dfs(int st , int end, int num, int count)
{
    if (copy[st][end] != 0) {
		return copy[st][end];
	}
    copy[st][end] =1; 
    for(int i =0; i<4; i++)
    {
        int x = st+dx[i];
        int y = end+dy[i];
        if(x <0 || y<0 || x>=N || y>= N)
            continue;
        if(move[x][y] > num && copy[x][y]==0)
        {
            dfs(x,y,move[x][y],count++);
        }
    }
    if(jump < count)
        jump = count;
    return jump;
}

void back_move(int ab[505][505])
{
    for(int i=0; i< N; i++)
    {
        for (int j =0; j < N; j++)
        {
            copy[i][j] = 0;
        }
    }
}


int main()
{
    freopen("input.txt", "r", stdin);
    
    scanf("%d", &N);
    int max = -9999;
    
    for(int i =0; i< N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d", &move[i][j]);
        }
    }

    int k =0;
    // int cnt;
     for(int i =0; i< N; i++)
     {
        for(int j=0; j<N; j++)
        {   back_move(copy);
            k=dfs(i,j,move[i][j],1);
            if(max < k)
                max = k;
        }
     }      
     printf("%d",k);
   
}