#include <bits/stdc++.h>

#define R register
#define ll long long
#define sqr(x) ((x) * (x))
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const ll MaxN = 2e3 + 10;
const ll mod = 1e9 + 7;

ll add(ll a, ll b) { return a + b >= mod ? a + b - mod : a + b; }
ll dec(ll a, ll b) { return a - b < 0 ? a - b + mod : a - b; }
ll pw(ll a, ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod, b >>= 1;
    }
    return ret;
}

struct num
{
    ll a, b;
    num(ll a = 0, ll b = 0) : a(a), b(b) {}
    num operator+(const num &x) const { return num(add(a, x.a), add(b, x.b)); }
    num operator+(const ll &x) const { return num(add(a, x), b); }
    inline num operator-(const num &x) const { return num(dec(a, x.a), dec(b, x.b)); }
    inline num operator-(const ll &x) const { return num(dec(a, x), b); }
    inline num operator*(const num &x) const
    {
        num res;
        res.a = (a * x.a + b * x.b * 5) % mod;
        res.b = (a * x.b + b * x.a) % mod;
        return res;
    }
    inline num operator*(const ll &x) const { return num(a * x % mod, b * x % mod); }

    friend inline num operator/(const num &x, const num &y)
    {
        num res, z = y;
        if (z.b != 0) z.b = mod - z.b;
        res = x * z;
        return res * pw(dec(y.a * y.a % mod, y.b * y.b * 5 % mod), mod - 2);
    }
} phi = num(500000004, 500000004), iphi = num(500000004, 500000003);

ll n, l, r, k, ifac;
ll c[MaxN][MaxN], s[MaxN][MaxN];

num poww(num a, ll b)
{
    num ret = num(1, 0);
    while (b)
    {
        if (b & 1)
            ret = ret * a;
        a = a * a, b >>= 1;
    }
    return ret;
}

num suma(num a, ll n) { return (poww(a, n + 1) - a) / (a - 1); }

num query(num x, ll l, ll r)
{
    if (x.a == 1 && x.b == 0) return x * (r - l + 1);
    return suma(x, r) - suma(x, l - 1);
}

ll func(ll n, ll k)
{
    num ans, a = num(0, 400000003);
    for (ll j = 0; j <= k; j++)
    {
        ll b = (((j + k) % 2) ? -1 : 1) * c[k][j] % mod;
        num c = poww(phi, j) * poww(iphi, k - j);
        b = (b + mod) % mod, ans = ans + query(c, 1, n) * b;
    }
    a = poww(a, k), ans = ans * a;
    return (ans.a % mod + mod) % mod;
}

ll fun(ll n, ll k)
{
    ll ans = 0;
    for (ll j = 1; j <= k; j++)
    {
        ll b = (((k - j) % 2) ? -1 : 1) * s[k][j] % mod;
        b = (b + mod) % mod, ans = sum(ans, b * func(n, j), mod);
    }
    return ans;
}

signed main()
{
    scanf("%lld%lld%lld", &k, &l, &r), l += 2, r += 2, c[0][0] = s[0][0] = ifac = 1;
    for (ll i = 1; i <= k; i++) ifac = ifac * i % mod; ifac = pw(ifac, mod - 2);
    for (ll i = 1; i < MaxN; i++)
    {
        c[i][0] = 1;
        for (ll j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
    for (ll i = 1; i < MaxN; i++)
        for (ll j = 1; j <= i; j++)
            s[i][j] = (ll)(s[i - 1][j] * (i - 1) + s[i - 1][j - 1]) % mod;
    printf("%lld\n", (fun(r, k) - fun(l - 1, k) + mod) * ifac % mod);
    return 0;
}