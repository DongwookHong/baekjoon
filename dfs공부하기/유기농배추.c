#include <stdio.h>
#define max 55
int m,n,k;

int square[max][max];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfs(int st, int end)
{
    square[st][end] =0;

    for(int i=0; i<4; i++)
    {
        int x = dx[i]+st;
        int y= dy[i]+end;

        if(x<0||y<0 || x>=n|| y>=m)
            continue;
        if(square[x][y] ==1)
            bfs(x,y);
    }
}

void toss(){
    freopen("input.txt","r",stdin);
    int num;

    scanf("%d", &num);

    

    int a,b;
    int cnt;
    for(int j =0; j <num; j++)
    {
        
        scanf("%d %d %d", &n ,&m,&k);
       
        a=0; b=0; cnt =0;
        for(int i = 0; i<k;i++)
        {
            scanf("%d %d",&a,&b);
            square[a][b] =1;
        }
       
        for(int i =0; i<n;i++)
        {
            for(int d =0; d<m; d++)
            {
                if(square[i][d]==1)
                {
                    bfs(i,d);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }

}


int main(){
    toss();
}