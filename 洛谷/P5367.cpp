#include <bits/stdc++.h>

#define R register
#define ll long long
#define lowbit(x) (x & (-x))
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e6 + 10;
const ll mod = 998244353;

ll n;
ll a[MaxN], fac[MaxN];

struct BIT
{
    ll c[MaxN];
    void add(ll pos, ll x)
    {
        while (pos <= n)
        {
            c[pos] += x;
            pos += lowbit(pos);
        }
    }
    ll query(int pos)
    {
        int ret = 0;
        while (pos)
        {
            ret += c[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }
} T;

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
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        a[i] = read(), fac[i] = (ll)(fac[i - 1] * 1ll * i) % mod, T.add(a[i], 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + ((T.query(a[i]) - 1) * fac[n - i]) % mod) % mod;
        T.add(a[i], -1);
    }
    printf("%lld\n", ans + 1);
    return 0;
}
