#include <bits/stdc++.h>
#define R register
#define ll __int128
#define cmin(a, b) ((a < b) ? a : b)
#define cmax(a, b) ((a < b) ? b : a)
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
const int MaxN = 100;
int n, m;
int a[MaxN][MaxN];
ll ans, l2[MaxN], f[MaxN][MaxN];

ll dp(int id, int l, int r)
{
    if (f[l][r] != -1)
        return f[l][r];
    int k = m - r + l;
    if (r - l >= 1)
        f[l][r] = cmax(a[id][l] * l2[k] + dp(id, l + 1, r), a[id][r] * l2[k] + dp(id, l, r - 1));
    else
        f[l][r] = a[id][l] * l2[k];
    return f[l][r];
}

void print(ll x)
{
    if (x == 0)
        return;
    print(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
    n = read(), m = read();
    l2[0] = 1;
    for (int i = 1; i <= m; i++)
        l2[i] = l2[i - 1] * 2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    for (int i = 1; i <= n; i++)
    {
        memset(f, -1, sizeof(f));
        ans += dp(i, 1, m);
    }
    if (ans == 0)
        return 0 * printf("0");
    else
        print(ans);
    return 0;
}
