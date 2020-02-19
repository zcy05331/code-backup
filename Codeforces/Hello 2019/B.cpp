
# include <bits/stdc++.h>

int n, flag, a[20], used[20];

inline void check()
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += a[i] * (used[i] ? (-1) : 1);
    if(sum % 360 == 0)
        flag = 1;
}

void dfs(int x)
{
    if(x == n + 1)
        return (void) (check());
    dfs(x + 1);
    used[x] = 1;
    dfs(x + 1);
    used[x] = 0;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    dfs(1);
    printf(flag ? "YES" : "NO");
    return 0;
}