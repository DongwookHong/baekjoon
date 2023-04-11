#include <stdio.h>

#define max 51
int M,N;
int square[max][max];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};


void dfs(int a,int b)
{
    square[a][b]=0;
   
    for(int i=0; i<4; i++)
    {
        int x = a+ dx[i];
        int y = b+ dy[i];
        if(x>=0 && x<M && y>=0 && y< N && square[x][y]  ==1)
            dfs(x,y);     
    }
}
int main()
{
    int test;
    scanf("%d" , &test);
    int k;
    int cnt;
    for(int i =0; i < test; i++)
    {
        scanf("%d %d %d", &M,&N,&k );

        for(int j =0; j < k;j++)
        {
            int a,b;
            scanf("%d %d", &a,&b);
            square[a][b]=1;
        }
        
        cnt =0;
        for(int k =0; k < M; k++)
        {
            for(int y= 0; y <N; y++)
            {
                if(square[k][y]==1)
                {
                    dfs(k,y);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }

}