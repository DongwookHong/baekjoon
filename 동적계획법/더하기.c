#include <stdio.h>
#define max 100000000
int num[max];


void cal(){
    int n;
    scanf("%d",&n);
    int ans[12];
    int k;
    int oh =0;
    for(int i =1; i<=n; i++)
    {
        scanf("%d" ,&k);
        num[1]= 1;
        num[2] =2;
        num[3]=4;
        
        for(int j=4; j<=k; j++)
        {
            num[j] = num[j-3]+num[j-2]+num[j-1]; 
        }
        ans[oh++] = num[k];
    }   
    for(int i =0; i<n; i++)
        printf("%d\n",ans[i]);

}


int main()
{
    cal();
}