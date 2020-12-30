#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int base = 1e7 + 19;
const int base1 = 1e7 + 79;
const int mod = 1e9 + 9;
const int mod1 = 998244853;

struct node
{
    ll a[6];
} x;

ll n;
std::unordered_map<int, int> mp, mp1;

ll get(node a)
{
    ll x = 0;
    for (ll i = 0; i < 6; i++)
        x = (x * base + a.a[i]) % mod;
    return x;
}

ll get1(node a)
{
    ll x = 0;
    for (ll i = 0; i < 6; i++)
        x = (x * base1 + a.a[i]) % mod1;
    return x;
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

signed main()
{
    freopen("snow.in", "r", stdin);
    freopen("snow.out", "w", stdout);
    n = read();
    for (ll i = 1; i <= n; i++)
    {
        node y = {};
        for (ll j = 0; j < 6; j++)
            x.a[j] = read();
        for (ll j = 0; j < 6; j++)
        {
            for (ll k = 0; k < 6; k++)
                y.a[k] = x.a[(j + k) % 6];
            if (mp[get(y)] && mp1[get1(y)])
                return 0 * puts("Twin snowflakes found.");
            std::reverse(y.a, y.a + 6);
            if (mp[get(y)] && mp1[get1(y)])
                return 0 * puts("Twin snowflakes found.");
        }
        
        mp[get(x)] = 1, mp1[get1(x)] = 1;
    }
    puts("No two snowflakes are alike.");
    return 0;
}
