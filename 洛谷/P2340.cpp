#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e3 + 10;
const int MaxM = 1e6 + 10;

int n, m, ans, *g;
int a[MaxN], b[MaxN], f[MaxM];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

int main()
{
    n = read(), m = 400000, g = f + 400000;
    for (int i = 1; i <= n; i++)
        a[i] = read(), b[i] = read();
    memset(f, -0x3f, sizeof(f)), g[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 0)
        {
            for (int j = m; j >= a[i] - m; j--)
                g[j] = std::max(g[j], g[j - a[i]] + b[i]);
        }
        else
        {
            for (int j = -m; j <= m + a[i]; j++)
                g[j] = std::max(g[j], g[j - a[i]] + b[i]);
        }
    }
    for (int i = 0; i <= m; i++)
        if (g[i] >= 0)
            ans = std::max(ans, i + g[i]);
    printf("%d\n", ans);
    return 0;
}
