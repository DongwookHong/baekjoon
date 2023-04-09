#include <stdio.h>
#define max 105

int check[max][max];
int squre[max][max];
int n,m;
int dx[8] = {-1,-1,-1,0,0,1,1,1 };
int dy[8] = { 1,0,-1,1,-1,1,0,1 };
// int big =-999;

void dfs(int st, int end)
{
    check[st][end]=1;
   
     for(int i=0; i<8; i++)
    {
        int x = st+dx[i];
        int y = end+dy[i];
        
        if(x<1|| y<1 || x>n||y>m)
            continue;
        if(squre[x][y]>=1 && !check[x][y])
        {
                    dfs(x,y);
        }
    }
}

void farm(){
    freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m;j++)
            scanf("%d", &squre[i][j]);
    int cnt=0;

     for(int i=1; i<=n; i++){
        for(int j=1; j<=m;j++)
            {
               if(!check[i][j])
               { 
                    dfs(i,j);
                    cnt++;
               }
            }
            
     }
     printf("%d",cnt); 
}


int main(){
    farm();
}