#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const ll inf = 1e16;
const ll MaxN = 3e5 + 10;

struct node
{
    ll l, r, val;
} t[MaxN];

struct query
{
    ll val, id;
} q[MaxN], Ql[MaxN], Qr[MaxN];

ll n, m, k, ans[MaxN];
std::vector<ll> v[MaxN];

struct BIT
{
    ll c[MaxN << 1];
    ll lowbit(ll x) { return x & (-x); }
    void add(ll x, ll val)
    {
        while (x <= 2 * m)
            c[x] += val, x += lowbit(x);;
    }
    ll query(ll x)
    {
        ll ret = 0;
        while (x)
            ret += c[x], x -= lowbit(x);
        return ret;
    }
    ll Query(ll x)
    {
        ll now = 0;
        for (ll i = 0; i < v[q[x].id].size(); i++)
        {
            now += query(v[q[x].id][i]) + query(v[q[x].id][i] + m);
            if (now >= q[x].val) return now;
        }
        return now;
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

void solve(ll l, ll r, ll ql, ll qr)
{
    if(l > r || ql > qr) return;
    if(l == r)
    {
        for(ll i = ql; i <= qr; i++)
            ans[q[i].id] = l;
        return;
    }
    ll cntl = 0, cntr = 0, mid = (l + r) >> 1;
    for(ll i = l; i <= mid; i++)
        T.add(t[i].l, t[i].val), T.add(t[i].r + 1, -t[i].val);
    for(ll i = ql; i <= qr; i++)
    {
        ll now = T.Query(i);
        if(q[i].val <= now) Ql[++cntl] = q[i];
        else q[i].val -= now, Qr[++cntr] = q[i];
    }
    for (ll i = l; i <= mid; i++)
        T.add(t[i].l, -t[i].val), T.add(t[i].r + 1, t[i].val);
    for(ll i = 0; i < cntl; i++) q[ql + i] = Ql[i + 1];
    for(ll i = 0; i < cntr; i++) q[ql + cntl + i] = Qr[i + 1];
    solve(l, mid, ql, ql + cntl - 1), solve(mid + 1, r, ql + cntl, qr);
}

signed main()
{
    n = read(), m = read();
    for (ll i = 1; i <= m; i++) v[read()].push_back(i);
    for (ll i = 1; i <= n; i++) q[i].val = read(), q[i].id = i;
    k = read();
    for(ll i = 1; i <= k; i++)
    {  
        t[i].l = read(), t[i].r = read(), t[i].val = read();
        if(t[i].r < t[i].l) t[i].r += m;
    }
    ++k, t[k].l = 1, t[k].r = 2 * m, t[k].val = inf, solve(1, k, 1, n);
    for(ll i = 1; i <= n; i++)
        (ans[i] == k) ? puts("NIE") : printf("%lld\n", ans[i]);
    return 0;
}
