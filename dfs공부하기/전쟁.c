#include <stdio.h>
# define max 105

char terri[max][max];
int M,N;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int dfs_W(int a,int b)
{
    terri[a][b]='0';
    int res =1;
    for(int i=0; i<4; i++)
    {
        int x = a+ dx[i];
        int y = b+ dy[i];
        if(x>=0 && x<M && y>=0 && y< N && terri[x][y]  =='W')
            res +=dfs_W(x,y);     
    }
    return res;
}
int dfs_B(int a,int b)
{
    terri[a][b]='0';
    int res =1;
    for(int i=0; i<4; i++)
    {
        int x = a+ dx[i];
        int y = b+ dy[i];
        if(x>=0 && x<M && y>=0 && y< N && terri[x][y]  =='B')
            res+=dfs_B(x,y);     
    }
    return res;
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
    int k=0;
    int y =0;
    int a=0;
    int b=0;
     for(int i =0 ; i<M;i++)
    {
     
        for(int j =0; j<N; j++)
        {
         
            if(terri[i][j] == 'W')
                {   
                     k =dfs_W(i,j);           
                    a += k*k;
                 
                }
            if(terri[i][j] == 'B')
                {
                     y=   dfs_B(i,j);
                    b += y *y;

                }
        }
       
    }
    printf("%d %d\n", a,b);

}