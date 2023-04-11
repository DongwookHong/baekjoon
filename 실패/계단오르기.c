#include <stdio.h>
#include <string.h>
# define max 320
int stairs[max];
int step;
int sum;
int visited[max];

int big(int a, int b)
{
    if(!b)
        return a;
    if(a == step-1 || b== step-1)
        return step -1;
    return (stairs[a] > stairs[b])? a:b;
}


int jump(int k) {
    visited[k] = 1; 
    if (visited[k] == 1 && visited[k-1] == 1 && visited[k-2] == 1) {
            return -1; 
        }
    sum += stairs[k];
    
    if (k>= step - 1)return sum; 
    if(k+1 == step -4)
    {
        if((stairs[step-4]+ stairs[step-1]+stairs[step-2]) > (stairs[step-3]+ stairs[step-1]))
            return jump(k+1);
    }
    int nextnum = big(k+1,k+2);
    
    if (nextnum ==0) return sum;
    return jump(nextnum);
}


int main()
{
    scanf("%d", &step);
    int result;
    int result2;
    int y;
    for(int i=0; i<step; i++)
        scanf("%d",&stairs[i]);
    
  
    result =jump(0);
    memset(visited, 0, sizeof(visited));
    sum =0;
    result2 = jump(1);
    if(result<result2)
        result = result2;
    printf("%d",result);    
}
