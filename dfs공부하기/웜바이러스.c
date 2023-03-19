#include <stdio.h>

#define max 101
int com,virus;
int comp[max][max];
int visited[max] ={0,};

void bfs(int a, int virus)
{
    visited[a] =1;
    printf("%d ",a);
    for(int i =1; i <= virus; i++)
    {
        int y;
        if(comp[a][i])
        {
            y =i;
            if(!visited[y])
                bfs(y,virus);
        }
    }
}

int main()
{
    scanf("%d",&com);
    scanf("%d",&virus);

    for(int i =0; i< virus; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);

        comp[a][b] = 1;
        comp[b][a] = 1;
    }
    bfs(1,com);
    int cnt = 0;
    for(int i=1; i<=com; i++) {
    if(visited[i])
        cnt++;
    }
     printf("%d", cnt-1);
}
   
