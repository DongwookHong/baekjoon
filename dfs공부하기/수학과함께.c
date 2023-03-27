#include <stdio.h>
#include <string.h>
#define max 7
int N;
char sum[max][max];
int min =9990;
int large = -11111;
int visit[max][max];


int dx[4]={0,1};
int dy[4]={1,0};


void dfs(int st, int end, int k)
{
  
     if(end == N -1&& st ==N-1){
            if((k) <min)
                min =(k);
                
            if((k) > large)
                large =(k);
            return ;     
    }
    for(int i =0; i<2 ;i++)
    {
        int x = st+dx[i];
        int y= end+dy[i];
        int cnt = k;
     
        if( x<0 ||y <0 || x>=N || y>=N)
            continue;
        if(sum[st][end] == '+')
            (cnt) += (sum[x][y]- '0');
        else if( sum[st][end] == '-')
            (cnt) -= (sum[x][y] - '0');
        else if(sum[st][end] == '*')
            (cnt) *= (sum[x][y] - '0');
        dfs(x,y,cnt);
    }
    
}

int main()
{ 
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
   
    for(int i =0; i<N; i++)
    {
        for(int j =0; j< N ;j++)
        {
            scanf(" %c", &sum[i][j]);
        }
    }
   int cnt =sum[0][0] - '0';
   
    dfs(0,0, cnt);
    printf("%d %d", large , min);
}