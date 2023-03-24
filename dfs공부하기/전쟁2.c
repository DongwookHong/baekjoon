#include <stdio.h>
# define max 105
char terri[max][max];
int M,N;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void dfs_W(int a,int b, int * ally)
{
    terri[a][b]='0';
    (*ally)++;
    for(int i=0; i<4; i++)
    {
        int x = a+ dx[i];
        int y = b+ dy[i];
        if(x>=0 && x<M && y>=0 && y< N && terri[x][y]  =='W')
            dfs_W(x,y,ally);     
    }
}
void dfs_B(int a,int b, int *enemy)
{
    terri[a][b]='0';
    (*enemy)++;
    for(int i=0; i<4; i++)
    {
        int x = a+ dx[i];
        int y = b+ dy[i];
        if(x>=0 && x<M && y>=0 && y< N && terri[x][y]  =='B')
            dfs_B(x,y,enemy);     
    }
}

int main()
{
   
    scanf("%d %d" , &N,&M);
 
    for (int i = 0; i < M; i++) {
        scanf("%s",terri[i]);
        // for (int j = 0; j < N; j++) {
        //     scanf(" %c", &terri[i][j]);
        // }
    }
    int ally;
    int enemy;
    int a=0;
    int b=0;
     for(int i =0 ; i<M;i++)
    {
   
        for(int j =0; j<N; j++)
        {
            ally =0;
            enemy =0;
            if(terri[i][j] == 'W')
                {
                    dfs_W(i,j,&ally);
                }
            else if(terri[i][j] == 'B')
                {
                    dfs_B(i,j,&enemy);
                }
                 ally = ally *ally;
                 enemy= enemy*enemy;
                 a+= ally;
                b+= enemy;
        }
    }
    printf("%d %d", a,b);

}