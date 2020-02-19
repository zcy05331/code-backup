#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 4000010;
const int mod = 998244353;

int n, m;
ll ans;
int f[MaxN];

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

inline int getf(int u)
{
    if (f[u] != u)
        f[u] = getf(f[u]);
    return f[u];
}

inline void merge(int u, int v)
{
    int fu = getf(u), fv = getf(v);
    if (fu != fv)
        f[fu] = fv;
}

int main()
{
    n = read(), m = read();
    for (R int i = 1; i <= n; i++)
        f[i] = i;
    for (R int i = 1; i <= m; i++)
    {
        R int op = read(), u = read(), v = read();
        if (op == 0)
            merge(u, v);
        else
        {
            int fu = getf(u), fv = getf(v);
            if (fu != fv)
                ans = (ans * 2) % mod;
            else
                ans = (ans * 2 + 1) % mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
