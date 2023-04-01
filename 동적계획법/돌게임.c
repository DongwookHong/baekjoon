#include <stdio.h>
#define max 100

int win[max];


int main()
{
    int n;
    scanf("%d", &n);
    if(n %2 == 0)
        printf("SK");
    else
        printf("CY");
}