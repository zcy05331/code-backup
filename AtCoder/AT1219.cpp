#include <bits/stdc++.h>

#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct query
{
    ll l, r;
    ll pos, id;
} Q[MaxN];

std::unordered_map<ll, ll> mp, vi;
ll n, m, q, siz, num, now, tmp[MaxN];
ll a[MaxN], b[MaxN], id[MaxN], cnt[MaxN], ans[MaxN];

void add(int pos, int op)
{
    if (op)
    {
        if (!vi[a[pos]])
        {
            vi[a[pos]] = 1;
            mp[a[pos]] = cnt[a[pos]];
        }
    }
    cnt[a[pos]]++, now = std::max(now, cnt[a[pos]] * b[a[pos]]);
}

int cmp(query a, query b)
{
    if (a.pos != b.pos)
        return a.pos < b.pos;
    return a.r < b.r;
}

ll calc(ll l, ll r)
{
    ll ret = 0;
    for (int i = l; i <= r; i++)
        tmp[a[i]] = 0;
    for (int i = l; i <= r; i++)
        tmp[a[i]]++, ret = std::max(ret, tmp[a[i]] * b[a[i]]);
    return ret;
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

int solve(int pos, int id)
{
    int R = std::min(n, id * siz), l = R + 1, r = R;
    now = 0, memset(cnt, 0, sizeof(cnt));
    while (::id[Q[pos].l] == id)
    {
        if (::id[Q[pos].l] == ::id[Q[pos].r])
            ans[Q[pos].id] = calc(Q[pos].l, Q[pos].r);
        else
        {
            while (r < Q[pos].r) add(++r, 0);
            ll cur = now; mp.clear(), vi.clear();
            while (l > Q[pos].l) add(--l, 1);
            ans[Q[pos].id] = now, now = cur, l = R + 1;
            for (auto x : mp) cnt[x.first] = x.second;
        }
        ++pos;
    }
    return pos;
}

signed main()
{
    n = read(), q = read();
    siz = sqrt(n), num = (n - 1) / siz + 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i] = read();
        id[i] = (i - 1) / siz + 1;
    }
    std::sort(b + 1, b + n + 1);
    m = std::unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + m + 1, a[i]) - b;
    for (int i = 1; i <= q; i++)
    {
        Q[i].l = read(), Q[i].r = read();
        Q[i].pos = id[Q[i].l], Q[i].id = i;
    }
    std::sort(Q + 1, Q + q + 1, cmp);
    for (int i = 1, id = 1; i <= num; i++)
        id = solve(id, i);
    for (int i = 1; i <= q; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
