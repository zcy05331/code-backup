#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int n, m, ans;
int a[30], used[30], tmp[30], f[2001];

inline void check()
{
    int sum = 0;
    memset(f, 0, sizeof(f));
    f[0] = 1;
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            for (int j = sum; j >= 0; j--)
                if (f[j] && !f[j + a[i]])
                    f[j + a[i]] = 1, ++ret;
            sum += a[i];
        }
    }
    ans = cmax(ans, ret);
}

inline void dfs(int x, int y)
{
    if (y > m || x > n)
        return;
    if (x == n)
    {
        if (y == m)
            check();
        return;
    }
    dfs(x + 1, y);
    used[x + 1] = 1;
    dfs(x + 1, y + 1);
    used[x + 1] = 0;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}
