#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 3e3 + 10;
const int mod = 998244353;

int n, m, k, f[MaxN][MaxN], g[MaxN][MaxN];

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
    int a, b;
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++)
        g[i][i] = 1;
    for (int i = 1; i <= k; i++)
    {
        a = read(), b = read();
        g[a][b] = 1;
    }
    f[0][1] = 1;
    for (int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                if(!g[j][k])
                    f[i][k] = sum(f[i][k], f[i - 1][j], mod);
    }
    printf("%d\n", f[m][1]);
    return 0;
}
