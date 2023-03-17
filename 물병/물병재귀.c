
int num(int n)
{
    if (n == 0)
        return 0;
    if (n % 2 == 0)
        return num(n / 2);
    else
        return num(n / 2) + 1;
}

int purchase(int N, int K, int ans)
{
   
    int cnt = num(N); 
    if (cnt <= K)
        return ans;
    else
        return purchase(N + 1, K, ans + 1);
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    if (K >= N)
        printf("-1");
    else
        printf("%d\n", purchase(N, K, 0));
    return 0;
}