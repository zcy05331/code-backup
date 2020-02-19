#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e5 + 10;

int n;
std::string s, t = "hard";
ll a[MaxN], f[MaxN][5];

inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    n = read();
    std::cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            f[i][j] = cmin(f[i][j], f[i - 1][j] + a[i]);
            if (s[i] != t[j])
                f[i][j] = cmin(f[i][j], f[i - 1][j]);
            else
                f[i][j + 1] = cmin(f[i][j + 1], f[i - 1][j]);
        }
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < 4; i++)
        ans = cmin(ans, f[n][i]);
    printf("%I64d\n", ans);
    return 0;
}
