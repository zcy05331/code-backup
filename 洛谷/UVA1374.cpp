#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int n, cnt, ans;
int used[1001], s[1001];

inline int dfs(int m, int dep, int now)
{
    if (dep > m || now <= 0 || now << (m - dep) < n)
        return 0;
    if (now == n || now << (m - dep) == n)
        return (ans = 1);
    s[dep] = now;
    for (int i = 0; i <= dep; i++)
    {
        int flag = dfs(m, dep + 1, now + s[i]) | dfs(m, dep + 1, now - s[i]);
        if (flag)
            return 1;
    }
    return 0;
}

int main()
{

    while (scanf("%d", &n) && n)
    {
        memset(used, 0, sizeof(used));
        cnt = 1, s[1] = 1, used[1] = 1, ans = 0;
        for (int i = 0; i <= n; i++)
        {
            dfs(i, 0, 1);
            if (ans)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
