#include <stdio.h>
#define max 305
int width, height;

int ice[max][max];
int check[max][max];
int dx[4]={-1,1,0,0};
int dy[4]={-1,1,0,0};
int flag;

void dfs(int st,int end)
{
    int ran;
    ran = ice[st][end]; 
    if(ran <= 0)
        ice[st][end]= -1;
    else
        ice[st][end]=ran-1;

    for(int i =0; i< 4; i++)
    {
        int x = st+dx[i];
        int y = end+dy[i];
        if (x < 0 || y < 0 || x >= width || y >= height)
            continue;
        if (ice[x][y] <= 0)
            dfs(x, y);
  
    }
}

void dfs_check(int st,int end)
{
    check[st][end]=0;

    for(int i =0; i< 4; i++)
    {
        int x = st+dx[i];
        int y = end+dy[i];
        if (x < 0 || y < 0 || x >= width || y >= height)
            continue;
        if (check[x][y] >= 1)
            dfs_check(x, y);
    }
}


void back_ice(int check[max][max])
{
    for(int i=0; i< width; i++)
    {
        for (int j =0; j < height; j++)
        {
            check[i][j] = ice[i][j];
        }
    }
}

int main(){
    
    scanf("%d %d", &width,&height);

    for(int i=0; i< width; i++)
    {
        for(int j=0;j <height; j++)
        {
            scanf("%d",&ice[i][j]);
        }
    }
    
    int cnt= max;
    int random=0;
    while(1)
    {
        for(int i=0; i< width; i++)
        {
            for(int j=0;j <height; j++)
            {
                cnt =0;
                if(ice[i][j]<= 0)
                {
                    dfs(i,j);
                    random++;
                }
                if(ice[i][j]>=1)
                {
                    dfs_check(i,j);
                    cnt++;
                    if(cnt >=2)
                    {
                        printf("%d",random);
                        return 0;
                    }
                    else
                        back_ice(check);
                }
            }
        }
        if (cnt ==0) 
            {
                printf("1");
                return 0;
            }
    }
    
}