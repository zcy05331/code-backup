#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int ll p[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 27};

ll n, ansx, ans;
ll cnt[20], num[20], fac[20];

void dfs(int x)
{
    for (cnt[x] = 1, num[x] = num[x - 1] * p[x], fac[x] = fac[x - 1] << 1; cnt[x] <= cnt[x - 1] && num[x] <= n; ++cnt[x], fac[x] += fac[x - 1], num[x] *= p[x])
    {
        if (ansx < fac[x])
            ansx = fac[x], ans = num[x];
        else if (ansx == fac[x])
            ans = std::min(ans, num[x]);
        dfs(x + 1);
    }
}

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
    n = read(), cnt[0] = 0x3f3f3f, fac[0] = num[0] = ansx = ans = 1;
    dfs(1), printf("%lld\n", ans);
    return 0;
}
