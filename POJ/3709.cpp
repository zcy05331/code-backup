#include <cstdio>
#include <algorithm>
#include <cstring>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 5e5 + 10;

ll n, k;
ll a[MaxN], f[MaxN], s[MaxN], t[MaxN], q[MaxN];

inline void init()
{
    memset(t, 0, sizeof(t));
    memset(s, 0, sizeof(s));
    memset(q, 0, sizeof(q));
    memset(f, 0x3f, sizeof(f)), f[0] = 0;
}

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

inline void prework()
{
    n = read(), k = read();
    for (ll i = 1; i <= n; i++)
        a[i] = read();
    std::sort(a + 1, a + n + 1);
    for (ll i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i], t[i] = a[i + 1] * i;
}

ll x(ll j) { return (j == 0) ? 1 : (a[j + 1]); }
ll y(ll j) { return (f[j] - s[j] + t[j]); }

inline void solve()
{
    ll l = 1, r = 1, now = 0;
    for (ll i = k; i < 2 * k && i <= n; i++)
        f[i] = s[i] - i * a[1];
    for (ll i = 2 * k; i <= n; i++)
    {
        now = i - k;
        while (l < r && (y(q[r]) - y(q[r - 1])) * (x(now) - x(q[r - 1])) >= (x(q[r]) - x(q[r - 1])) * (y(now) - y(q[r - 1])))
            r--;
        q[++r] = now;
        while (l < r && (y(q[l + 1]) - y(q[l])) <= i * (x(q[l + 1]) - x(q[l])))
            l++;
        f[i] = f[q[l]] - a[q[l] + 1] * (i - q[l]) + (s[i] - s[q[l]]);
    }
    printf("%lld\n", f[n]);
}
int main()
{
    ll T = read();
    while (T--)
    {
        init();
        prework();
        solve();
    }
    return 0;
}
