#include <stdio.h>
int square[55][55] = {0,};

int dfs(int x, int y, int width, int length) {
    //방문한 곳은 0으로 바꾸기
    square[x][y] = 0;
 
    //상하좌우로 탐색
    if (x + 1 < width && square[x + 1][y] == 1) dfs(x + 1, y,width,length);
    if (x - 1 >= 0 && square[x - 1][y] == 1) dfs(x - 1, y,width,length);
    if (y + 1 < length && square[x][y + 1] == 1) dfs(x, y + 1,width,length);
    if (y - 1 >= 0 && square[x][y - 1] == 1) dfs(x, y - 1,width,length);
    return 0;
}

int main(){
    int  a;
    scanf("%d", &a);
    
    int width, length , num;
    int check_wid = 0;
    int check_len =0;
    int cnt;

    for(int i =0; i < a; i++)
    {
        scanf("%d %d %d", &width,&length, &num);
        
        for(int y = 0; y < num; y ++)
        {
            scanf("%d %d" , &check_wid,&check_len);
            square[check_wid][check_len] = 1;
        }
        cnt =0;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < length; j++) {
                if (square[i][j] == 1) {
                    dfs(i, j,width,length);
                    cnt++;
                }
            }
        }
        printf("%d",cnt);
    }
}





 
