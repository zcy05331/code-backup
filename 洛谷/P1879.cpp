#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 13;
const int mod = 1e9;

int n, m;
int s[MaxN], a[MaxN][MaxN], f[MaxN][1 << MaxN], ok[1 << MaxN];

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

int main()
{
    m = read(), n = read();
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = read(), s[i] = (s[i] << 1) + a[i][j];
    int maxstate = (1 << n);
    f[0][0] = 1;
    for (int i = 0; i < maxstate; i++)
        if (((i & (i << 1)) == 0) && ((i & (i >> 1)) == 0))
            ok[i] = 1;
    for (int i = 1; i <= m; i++)
        for (int w1 = 0; w1 < maxstate; w1++)
            if (ok[w1] && (w1 & s[i]) == w1)
                for (int w2 = 0; w2 < maxstate; w2++)
                    if ((w1 & w2) == 0)
                        f[i][w1] = sum(f[i][w1], f[i - 1][w2], mod);
    ll ans = 0;
    for (int i = 0; i < maxstate; i++)
        ans = sum(ans, f[m][i], mod);
    printf("%lld\n", ans);
    return 0;
}
