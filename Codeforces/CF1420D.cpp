#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll mod = 998244353;
const ll MaxN = 6e5 + 10;

std::vector<ll> v;
std::pair<ll, ll> a[MaxN];
ll n, m, k, ans, c[MaxN], fac[MaxN], inv[MaxN];

ll lowbit(ll x) { return x & (-x); }

ll C(ll n, ll m)
{
    if (n > m) return 0;
    return ((fac[m] * inv[n]) % mod) * inv[m - n] % mod;
}

void add(ll pos, ll val)
{
    while (pos <= m)
        c[pos] += val, pos += lowbit(pos);
}

ll query(ll pos)
{
    ll ret = 0;
    while (pos)
        ret += c[pos], pos -= lowbit(pos);
    return ret;
}

ll read()
{
    ll x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

ll fast_pow(ll a, ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1)
            ret = (ret * a) % mod;
        a = (a * a) % mod, b >>= 1;
    }
    return ret;
}

void prework()
{
    for (int i = 1; i <= n; i++)
        v.push_back(a[i].first), v.push_back(a[i].second);
    std::sort(v.begin(), v.end()), v.erase(std::unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n; i++)
    {
        a[i].first = std::lower_bound(v.begin(), v.end(), a[i].first) - v.begin() + 1;
        a[i].second = std::lower_bound(v.begin(), v.end(), a[i].second) - v.begin() + 1;
        m = std::max(a[i].first, m), m = std::max(a[i].second, m);
    }
    inv[0] = fac[0] = 1;
    for (int i = 1; i <= 300000; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[300000] = fast_pow(fac[300000], mod - 2);
    for (int i = 299999; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}

int main()
{
    n = read(), k = read();
    if (k == 1) return 0 * printf("%lld\n", n);
    for (int i = 1; i <= n; i++)
        a[i].first = read(), a[i].second = read();
    std::sort(a + 1, a + n + 1), prework();
    for (int i = 1; i <= n; i++)
    {
        ll x = i - 1 - query(a[i].first - 1);
        ans = sum(ans, C(k - 1, x), mod), add(a[i].second, 1);
    }
    printf("%lld\n", ans);
    return 0;
}
