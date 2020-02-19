#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxK = 55;
const ll MaxN = 2e5 + 10;

ll n, k, p;
ll a[MaxN], b[MaxN], s[MaxN][MaxK];

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
    n = read(), k = read(), p = read();
    for (ll i = 1; i <= n; i++)
        a[i] = read() + 1, b[i] = read();
    ll ans = 0, last = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (b[i] <= p)
            last = i;
        for (int j = 1; j <= k; j++)
            s[i][j] = s[i - 1][j];
        ans += s[last][a[i]];
        ++s[i][a[i]];
    }
    printf("%lld\n", ans);
    return 0;
}
