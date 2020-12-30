#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int base1 = 233;
const int base2 = 331;
const int mod = 998244353;
const int MaxN = 5e3 + 10;

struct mod_t
{
    int x;
    mod_t() {}
    mod_t(ll v) : x(v) {}
    mod_t(int v) : x(v) {}
    mod_t(long int v) : x(v) {}
    static int Mod(int x) { return ((x < 0) ? (x + mod) : x); }
    mod_t operator+(const mod_t y) const { return Mod(x + y.x - mod); }
    mod_t operator-(const mod_t y) const { return Mod(x - y.x); }
    mod_t operator*(const mod_t y) const { return (ll)x * y.x % mod; }
};

std::string str;
std::unordered_map<ll, ll> mp;
mod_t s[MaxN][MaxN], pwa, pwb;
ll n, m, a, b, q, c[MaxN][MaxN];

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

signed main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    n = read(), m = read(), a = read(), b = read(), pwa = pwb = 1;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> &str[1];
        for (int j = 1; j <= m; j++)
            s[i][j] = (s[i][j - 1] * base1 + str[j]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = (s[i][j] + s[i - 1][j] * base2);
    for (int i = 1; i <= a; i++)
        pwa = pwa * base2;
    for (int i = 1; i <= b; i++)
        pwb = pwb * base1;
    for (int i = a; i <= n; i++)
        for (int j = b; j <= m; j++)
            mp[(s[i][j] - pwa * s[i - a][j] - pwb * s[i][j - b] + pwa * pwb * s[i - a][j - b]).x] = 1;
    q = read();
    while (q--)
    {
        mod_t x = 0, y = 0;
        for (int i = 1; i <= a; i++)
        {
            std::cin >> &str[1], x = 0;
            for (int j = 1; j <= b; j++)
                x = (x * base1 + str[j]);
            y = y * base2 + x;
        }
        printf("%lld\n", mp[y.x]);
    }
    return 0;
}
