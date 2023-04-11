#include <stdio.h>
#define max 15

int n;
char s[max][max];
char ch[max][max];

int dx[4]= {-1,1,0,0};
int dy[4]= {0,0,-1,1};
// int cnt;

int bfs(int st , int end , int *cnt)
{
    // ch[st][end] =1;
    
   for(int i = 0; i <4; i++)
    {
        int x= st+dx[i];
        int y = end+dy[i];
        if(x<0|| x>n||y <0|| y>n)
            continue;
        if(s[x][y] == '.' )
        {
            (*cnt)++;
            if((*cnt)>=2)
                return 1;
        }
    }
    return 0;
}
// void squre(char abc[max][max])
// {
//     for (size_t i = 0; i < n; i++)
//         for(size_t j=0; j<n; j++)
//             abc[i][j]= 0;
// }

void revol(){
    freopen("input.txt","r",stdin);

    scanf("%d",&n);
    
    for (int i = 0; i < n; i++)
        for(int j=0; j<n; j++)
            scanf("%c",&s[i][j]); 

    int k=0;
    int cnt =0;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cnt=0;
            if(s[i][j]=='.')
                k=bfs(i,j,&cnt);
            // squre(ch);
            if(k == 1)
                sum++;
        }  

    }
    printf("%d",sum);
}

int main()
{
    revol();
}

