# include <bits/stdc++.h>

const int MaxN = 10010;

int n;
int a[MaxN], dp[MaxN];

int check()
{
    for(int i = 2; i <= n; i++)
        dp[i + 1] = a[i] - dp[i - 1] - dp[i];
    if(!dp[n + 1])
        return 1;
    return 0;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int ans = 0;
    for(int i = 0; i <= a[1]; i++)
    {
        memset(dp, 0, sizeof(dp));
        dp[1] = i, dp[2] = a[1] - i;
        ans += check();
    }
    printf("%d\n", ans);
    return 0;
}