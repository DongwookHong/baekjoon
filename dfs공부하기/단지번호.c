#include <stdio.h>
#include <stdlib.h>
#define max 30
int a;
int square[max][max]={0,};


void swap(int *a,int *b)
{
    int temp ;

    temp = *a;
    *a = *b;
    *b = temp;
}

void bfs(int k,int b,int *cnt)
{
    square[k][b] =0;
    (*cnt)++;
    if(k+1 <=a && square[k+1][b] ==1)bfs(k+1,b,cnt);
    if(k-1 >=0 && square[k-1][b] ==1)bfs(k-1,b,cnt);
    if(b+1 <=a && square[k][b+1] ==1)bfs(k,b+1,cnt);
    if(b-1 >=0 && square[k][b-1] ==1)bfs(k,b-1,cnt);
}


int main(){
   int *arr;
   scanf("%d",&a);

   arr= (int *)calloc(a*a,sizeof(int)); 
   for(int i = 1; i<=a; i++)
   {
        for(int j = 1; j<=a; j++)
        {
            scanf("%1d",&square[i][j]);   
        }
   }  
   int cnt;
  
   int count =0;
    for(int i = 1; i<=a; i++)
   {
        for(int j = 1; j<=a; j++)
        {
          cnt =0;
        
          if(square[i][j] == 1)
            {
                bfs(i,j,&cnt);
                count++;
               arr[count-1] =cnt;
            }
             
        }
  
   }  
     for(int i=0; i<count; i++)
  {
     for(int j=i+1; j<count;j++)
     {
        if(arr[i]>arr[j])
            swap(&arr[i],&arr[j]);
     }
  }
  printf("%d\n", count);

 for(int i=0; i<count; i++)
  {
     printf("%d\n",arr[i]);
  }
}