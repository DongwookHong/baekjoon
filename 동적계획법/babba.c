#include <stdio.h>
#define max 50


int a[max];
int b[max];


int main(){
    int k ;
    scanf("%d",&k);

    a[0]=1;
    a[1] =0;
    a[2] =1;

    b[0]=1;
    b[1]=1;
    b[2]=1;

    for(int i =3 ; i <= k;i++)
    {
        a[i]= a[i-1]+a[i-2];
        b[i] = b[i-1]+b[i-2];
    }
    printf("%d %d",a[k],b[k]);

}