#include <stdio.h>

#define bigger(a,b) a>b? a:b
// w 물건의무게 v 가치  k최대 무게
#define max 100005
int bag[max];
int carry[max];
int please[max];

void heavy(){
    // freopen("input.txt", "r", stdin);
    int num,k;

    scanf("%d %d",&num, &k);
    

    for(int i =1 ; i<=num; i++ )
        scanf("%d %d" , &carry[i], &please[i]);
    
    for(int i =1 ; i<=num; i++)
        for(int j=k; j>=carry[i]; j--)
            bag[j]= bigger(bag[j],bag[j - carry[i]]+please[i]);
    
    printf("%d", bag[k]);
    return ;
}


int main(){
    heavy();
    return 0;
}