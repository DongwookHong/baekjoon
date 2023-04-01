#include <stdio.h>
#define max 80


long long tile[max];

int main(){

    int a;
    scanf("%d",&a);

    tile[1]=4;
    tile [2] =6;
    for(int i =3; i <= a; i++)
    {
        tile[i]= tile[i-1]+ tile[i-2];
    }
    printf("%lld" , tile[a]);
}