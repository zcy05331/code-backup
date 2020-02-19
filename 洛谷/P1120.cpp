#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int n, len, cnt;
int a[100], vis[100], b[100];

bool dfs(int x, int cab, int last)
{
    if (x > cnt)
        return true;
    if (cab == len)
        return dfs(x + 1, 0, 1);
    int fail = 0;
    for (int i = last; i <= n; i++)
    {
        if (!vis[i] && cab + a[i] <= len && fail != a[i])
        {
            vis[i] = 1;
            if (dfs(x, cab + a[i], i + 1))
                return true;
            fail = a[i];
            vis[i] = 0;
            if (cab == 0 || cab + a[i] == len)
                return false;
        }
    }
    return false;
}

int main()
{
    while (scanf("%d", &n) && n)
    {
        memset(vis, 0, sizeof(vis));
        int sum = 0, max = 0, pos = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
            if (b[i] <= 50)
                a[++pos] = b[i], sum += a[pos], max = cmax(max, a[pos]);
        }
        n = pos;
        std::sort(a + 1, a + n + 1);
        std::reverse(a + 1, a + n + 1);
        for (int i = max; i <= sum; i++)
        {
            if (sum % i)
                continue;
            len = i, cnt = sum / i;
            if (dfs(1, 0, 1))
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
