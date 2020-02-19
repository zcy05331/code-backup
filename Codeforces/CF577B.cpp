#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e6 + 10, MaxM = 1e3 + 10;

int n, m;
int a[MaxN], s[MaxN], f[MaxM][MaxM << 2];

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
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read() % m;
    if (n > m)
        return 0 * printf("YES");
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i][a[i]] = 1;
        for (int j = 1; j <= m && !flag; j++)
            f[i][j] |= f[i - 1][j], f[i][(j + a[i]) % m] |= f[i - 1][j], flag = (f[i][0] ? 1 : flag);
        flag = f[i][0] ? 1 : 0;
        if (flag)
            break;
    }
    printf(flag ? "YES" : "NO");
    return 0;
}
