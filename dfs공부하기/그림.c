#include <stdio.h>
#define max 505
int N,M;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int paint[max][max];


void dfs(int st,int end, int *count)
{
    paint[st][end] =0;
    (*count)++;
    for(int i =0; i<4; i++)
    {
        int x = st+dx[i];
        int y = end+dy[i];
        if(x <0 || y<0 || x>=N || y>= M)
            continue;
        if(paint[x][y]==1)
            dfs(x,y,count);
    }
}

int main(){

freopen("input.txt", "r", stdin);
scanf("%d %d" ,&N,&M);

for(int i =0; i< N;i++)
    for(int j =0; j<M ; j++)
        scanf("%d",&paint[i][j]);

int max_num = -9999;
int cnt =0;
int count =0;
for(int i =0; i< N;i++)
{
    for(int j =0; j<M ; j++)
    {
        count =0;
        if(paint[i][j]==1)
        {
            dfs(i,j,&count);
            cnt++;
        }
        if(count > max_num)
            max_num=count;
    }    
}
printf("%d\n" ,cnt);
printf("%d",max_num);
}