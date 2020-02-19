#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = (x); i <= (y); i++)
#define per(i, x, y) for (int i = (x); i >= (y); i--)
#define ll long long

const int N = 5e3 + 10;
const ll mod = 998244353;

int n, tot, sum, a[N], b[N], num[N << 1], g[N], C[N], inv[N];

ll fast_pow(ll a, ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * 1ll * a % mod;
        a = a * 1ll * a % mod;
        b >>= 1;
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    inv[1] = 1;
    rep(i, 2, n) inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
    rep(i, 1, n)
    {
        scanf("%d%d", &a[i], &b[i]), sum = sum * 1ll * (b[i] - a[i] + 1) % mod;
        num[++tot] = a[i], num[++tot] = b[i] + 1;
    }
    std::sort(num + 1, num + 1 + tot);
    tot = std::unique(num + 1, num + 1 + tot) - num - 1;
    rep(i, 1, n)
    {
        a[i] = std::lower_bound(num + 1, num + 1 + tot, a[i]) - num;
        b[i] = std::lower_bound(num + 1, num + 1 + tot, b[i] + 1) - num;
    }
    C[0] = 1;
    g[0] = 1;
    rep(j, 1, tot - 1)
    {
        int len = num[j + 1] - num[j];
        rep(i, 1, n) C[i] = (ll)C[i - 1] * (len + i - 1) % mod * inv[i] % mod;
        rep(i, 1, n) if (a[i] <= j && j <= b[i])
        {
            int f = 0, m = 1, c = len;
            rep(p, 0, i - 1)
            {
                f = (f + (ll)c * g[p] % mod) % mod;
                if (a[p] <= j && j + 1 <= b[p])
                    c = C[++m];
            }
            g[i] = (g[i] + f) % mod;
        }
    }
    int ans = 0;
    rep(i, 1, n) ans = (ans + g[i]) % mod;
    printf("%lld\n", ans * 1ll * fast_pow(sum, mod - 2) % mod);
    return 0;
}