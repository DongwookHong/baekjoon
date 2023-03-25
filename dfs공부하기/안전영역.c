#include <stdio.h>
# define max 105

int squre[max][max];
int copy[max][max];
int a;


int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};



void dfs(int st,int end, int num)
{
    squre[st][end] =0;

    for (int i =0 ; i < 4 ; i++)
    {
        int x = st+dx[i];
        int y = end+dy[i];

        if(x>=0 && y>=0 && x<a && y<a && squre[x][y] >= num)
            dfs(x,y,num);
    }

}

void back_floor(int ab[max][max])
{
    for(int i=0; i< a; i++)
    {
        for (int j =0; j < a; j++)
        {
            squre[i][j] = copy[i][j];
        }
    }
}
int main()
{
    scanf("%d",&a);
    int big = -1;
    for(int i=0; i< a; i++)
    {
        for (int j =0; j < a; j++)
        {
            scanf("%d", &squre[i][j]);
            if(squre[i][j]>big)
                big = squre[i][j];
            copy[i][j] = squre[i][j];
        }
    }
  
   int k =1;
   int cnt;
   int max_suqre = -1;
   while(k <= big)
    {
        cnt = 0;  
        for(int i=0; i< a; i++)
        {
            for (int j =0; j <a; j++)
            { 
               
                if(squre[i][j] >= k)
                {
                    dfs(i,j,k);
                    cnt++;
                }
                if(max_suqre < cnt)
                    max_suqre = cnt;
            }
        }
        back_floor(squre);
        k++;
       
    }
    if(max_suqre == -1)
        printf("1");
    else
        printf("%d",max_suqre);   
}