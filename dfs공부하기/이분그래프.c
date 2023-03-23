#include <stdio.h>

#define max 1000

int m,n;//정점의 갯수 m랑 간선의 갯수 n
int visited[max];
int graph[max][max];
int agroup[max];
bool flag;
int stack[max];
int top = -1;

int isEmpty() {
    return (top == -1);
}
int isFUll(){
    return (top == max-1);
}
 
void push(int a)
{
    if(isFUll())
    {
        return;
    }
    stack[++top] =a;
}

int pop(){
    if(isEmpty())
    {
        return -1;
    }
    return stack[top--];
}
int front_element() {
    if (front == rear) {
        return -1;
    }

    return queue[front + 1];
}

void dfs(int start, int group,int end)
{
    stack.push(start);
    agroup[start] = group;
    visited[start]= 1;

    while(!stack.isEmpty()){
        int frog = stack.front_element();
        stack.pop();
        for(int i =1; i <= end; i++ )
        {
            int node = graph[frog][i];

            if(agroup[node] != 0 && agroup[node] == agroup[frog]){
                flag = true;
                return;
            }
        }
        int c2;
        if(group[frog] ==1) c2 =2;
        else c2 =1;
        if(!check[node]){
            check[node] = 1;
            agroup[node] =c2;

            stack.push(node);
       } 
    }
}




int main()
{
    scanf("%1d %1d", &m,&n);

    for(int i=0; i <n; i++)
    {
        int a,b;
        scanf("%1d %1d", &a,&b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    flag = false;

    dfs(1,1,m); 

    if(flag) printf("No\n");
    else printf("Yes\n"); 
}