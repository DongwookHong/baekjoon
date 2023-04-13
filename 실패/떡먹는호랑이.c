
//fix  떡먹는 호랑이 2502 -> 백준 ..
#include <stdio.h>
#define max 40

int dp[max];
int day,cake;

void tiger()
{
    scanf("%d %d" ,&day,&cake);

    dp[1]= 1;
    dp[2] =1;
    for(int i =3 ; i<=day; i++)
        dp[i] = dp[i-1]+ dp[i-2];
    int a_pro = dp[day-2];
    int b_pro = dp[day-1];
    int a,b;
    
    for(int i =1;;i++ )
    {
        a= i;
       if ((cake - a_pro * a) % b_pro)
			continue;
		b = (cake - a_pro * a) / b_pro;
		break;
    }
    printf("%d\n",a);
    printf("%d\n",b);
}

int main(){
    tiger();
}

// 실패코드
//#include <stdio.h>
// #define max 40


// int dp[max];
// int day,cake;

// void tiger()
// {
//     scanf("%d %d" ,&day,&cake);

  
//     while(1)
//     {
        
//         for(int i =3; i<=day; i++)
//         {
//             dp[i]= dp[i-1]+dp[i-2];
//             if(dp[6]== 41)
//             {

//             }
//         }
//     }
// }

// int main(){
//     tiger();
// }