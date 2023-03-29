#include <stdio.h>
#define max 50

int arr[max];
int a;

int main(){

    scanf("%d",&a);
    arr[0]= 1;
    arr[1] =1;
    int num=0;
    int sum =0;
    for(int i =0; i < a ; i++){
        scanf("%d",&num);
        for(int i =2; i <=num; i++)
        {
            arr[i] = arr[i-1]+ arr[i-2];
        }

        printf("%d\n",arr[num]);  
    }
      

}