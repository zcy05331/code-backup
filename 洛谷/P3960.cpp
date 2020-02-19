#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 3e5 + 10;

struct node
{
    ll l, r, st, ed;
    node(ll l, ll r, ll st, ll ed) : l(l), r(r), st(st), ed(ed) {}
    bool operator<(node x) const { return l < x.l; }
};

ll n, m, q;
std::set<node> s[MaxN], t;

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

ll main()
{
    n = read(), m = read(), q = read();
    for (ll i = 1; i <= n; i++)
        s[i].insert(node(1, m - 1, (i - 1) * m + 1, i * m - 1));
    t.insert(node(1, n, m, ));
    while (q--)
    {
    }
    return 0;
}
