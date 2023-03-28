#include <stdio.h>
#define max 305
int width, height;

int ice[max][max];
int check[max][max];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int ans;



void dfs(int st,int end, int v)
{
    check[st][end] =v;

    int water =0;
    for(int i =0; i< 4; i++)
    {
        int x = st+dx[i];
        int y = end+dy[i];
        
        if(check[x][y] == v)
            continue;
        if (ice[x][y] <= 0)
            water++;
        else 
            dfs(x,y,v);
    }
    ice[st][end] -= water;
}

int iceberg()
{
    int time=0;
    int v =1;
    while(1)
    {
        int cnt=0;
        for(int i=1; i< width; i++)
        {
            for(int j=1;j <height; j++)
            {
                if((ice[i][j]>0) && (check[i][j] != v))
                {
                    cnt++;
                    dfs(i,j,v);                 
                }
            }
        }
        if(cnt ==0)
            return 0;
        if(cnt >1)
            return time;
        time++;
        v++;
    }
}

int main()
{    
   freopen("input.txt", "r", stdin);

   scanf("%d %d", &width, &height);
   for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            scanf("%d", &ice[i][j]);
        }
    }
    ans = iceberg();
    printf("%d\n", ans);
}