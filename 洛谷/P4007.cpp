#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define Add(a, b, mod) ((a) = sum(a, b, mod))
#define meow(cat...) fprintf(stderr, cat)

const ll MaxK = 175;
const ll mod = 998244353;

struct matrix
{
    ll a[MaxK][MaxK];
    matrix() { memset(a, 0, sizeof(a)); }
} dp[70];

ll ans[MaxK], tmp[MaxK];
ll t, n, m, k, s, inv[101], st[11][11][11];

matrix mul(const matrix &a, const matrix &b)
{
    matrix c;
    for (ll i = 0; i <= s + 1; i++)
        for (ll j = 0; j <= s + 1; j++)
            for (ll k = 0; k <= s + 1; k++)
                Add(c.a[i][j], a.a[i][k] * b.a[k][j], mod);
    return c;
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

signed main()
{
    t = read(), m = read(), k = read();
    for (ll i = 0; i <= 100; i++)
        inv[i] = pw(i, mod - 2);
    for (ll i = 0; i <= k; i++)
    {
        ll limi = 0;
        if (m > 1) limi = k - i;
        for (ll j = 0; j <= limi; j++)
        {
            ll limj = 0;
            if (m > 2) limj = k - i - j;
            for (ll l = 0; l <= limj; l++)
                st[i][j][l] = ++s;
        }
    }
    for (ll i = 0; i <= k; i++)
    {
        ll limi = 0;
        if (m > 1) limi = k - i;
        for (ll j = 0; j <= limi; j++)
        {
            ll limj = 0;
            if (m > 2) limj = k - i - j;
            for (ll l = 0; l <= limj; l++)
            {
                ll New = 0;
                if (i + j + l < k) New = 1;
                if (m == 1 && i)
                    dp[0].a[st[i][j][l]][st[i - 1][j][l]] = (ll)i * inv[i + j + l + 1] % mod;
                else if (m == 2)
                {
                    if (i) dp[0].a[st[i][j][l]][st[i - 1][j][l]] = (ll)i * inv[i + j + l + 1] % mod;
                    if (j) dp[0].a[st[i][j][l]][st[i + 1][j - 1 + New][l]] = (ll)j * inv[i + j + l + 1] % mod;
                }
                else if (m == 3)
                {
                    if (i) dp[0].a[st[i][j][l]][st[i - 1][j][l]] = (ll)i * inv[i + j + l + 1] % mod;
                    if (j) dp[0].a[st[i][j][l]][st[i + 1][j - 1][l + New]] = (ll)j * inv[i + j + l + 1] % mod;
                    if (l) dp[0].a[st[i][j][l]][st[i][j + 1][l - 1 + New]] = (ll)l * inv[i + j + l + 1] % mod;
                }
                dp[0].a[st[i][j][l]][st[i][j][l]] = dp[0].a[st[i][j][l]][s + 1] = inv[i + j + l + 1];
            }
        }
    }
    dp[0].a[s + 1][s + 1] = 1;
    for (ll i = 1; i <= 60; i++)
        dp[i] = mul(dp[i - 1], dp[i - 1]);
    while (t--)
    {
        ll n = read();
        memset(ans, 0, sizeof(ans));
        if (m == 1)
            ans[st[1][0][0]] = 1;
        else if (m == 2)
            ans[st[0][1][0]] = 1;
        else
            ans[st[0][0][1]] = 1;
        for (ll i = 0; i <= 60; i++)
        {
            if (n & (1ll << i))
            {
                for (ll j = 0; j <= s + 1; j++)
                {
                    tmp[j] = 0;
                    for (ll k = 0; k <= s + 1; k++)
                        Add(tmp[j], ans[k] * dp[i].a[k][j], mod);
                }
                for (ll j = 0; j <= s + 1; j++)
                    ans[j] = tmp[j];
            }
        }
        printf("%lld\n", ans[s + 1]);
    }
    return 0;
}