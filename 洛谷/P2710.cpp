#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 3e5 + 10;
const ll inf = 0x7f7f7f7f;

ll n, m, a[MaxN];

inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

struct Splay
{
    std::queue<ll> q;
    ll root, cnt, tag[MaxN], rev[MaxN];
    ll id[MaxN], fa[MaxN], ch[MaxN][2], sum[MaxN];
    ll size[MaxN], val[MaxN], max[MaxN], lsum[MaxN], rsum[MaxN];
    inline void pushup(ll x)
    {
        ll l = ch[x][0], r = ch[x][1];
        sum[x] = sum[l] + sum[r] + val[x], size[x] = size[l] + size[r] + 1;
        max[x] = std::max(max[l], std::max(max[r], rsum[l] + val[x] + lsum[r]));
        lsum[x] = std::max(lsum[l], sum[l] + val[x] + lsum[r]), rsum[x] = std::max(rsum[r], sum[r] + val[x] + rsum[l]);
    }
    inline void pushdown(ll x)
    {
        ll l = ch[x][0], r = ch[x][1];
        if (tag[x])
        {
            rev[x] = tag[x] = 0;
            if (l)
                tag[l] = 1, val[l] = val[x], sum[l] = val[x] * size[l];
            if (r)
                tag[r] = 1, val[r] = val[x], sum[r] = val[x] * size[r];
            if (val[x] >= 0)
            {
                if (l)
                    lsum[l] = rsum[l] = max[l] = sum[l];
                if (r)
                    lsum[r] = rsum[r] = max[r] = sum[r];
            }
            else
            {
                if (l)
                    lsum[l] = rsum[l] = 0, max[l] = val[x];
                if (r)
                    lsum[r] = rsum[r] = 0, max[r] = val[x];
            }
        }
        if (rev[x])
        {
            rev[x] = 0, rev[l] ^= 1, rev[r] ^= 1;
            std::swap(lsum[l], rsum[l]), std::swap(lsum[r], rsum[r]);
            std::swap(ch[l][0], ch[l][1]), std::swap(ch[r][0], ch[r][1]);
        }
    }
#define check(x) (ch[fa[x]][1] == x)
    inline void rotate(ll x, ll &k)
    {
        ll f = fa[x], gf = fa[f], tp = check(x);
        (f == k) ? (k = x) : (ch[gf][check(f)] = x);
        fa[ch[x][tp ^ 1]] = f, fa[f] = x, fa[x] = gf;
        ch[f][tp] = ch[x][tp ^ 1], ch[x][tp ^ 1] = f;
        pushup(f), pushup(x);
    }
    void splay(ll x, ll &k)
    {
        while (x != k)
        {
            ll f = fa[x];
            if (f != k)
            {
                if (check(f) ^ check(x))
                    rotate(x, k);
                else
                    rotate(f, k);
            }
            rotate(x, k);
        }
    }
    ll find(ll x, ll rk)
    {
        pushdown(x);
        ll l = ch[x][0], r = ch[x][1];
        if (size[l] + 1 == rk)
            return x;
        return ((size[l] >= rk) ? find(l, rk) : find(r, rk - size[l] - 1));
    }
    inline ll split(ll k, ll tot)
    {
        ll x = find(root, k), y = find(root, k + tot + 1);
        splay(x, root), splay(y, ch[x][1]);
        return ch[y][0];
    }
    inline void query(ll k, ll tot)
    {
        ll x = split(k, tot);
        printf("%lld\n", sum[x]);
    }
    inline void query_max(ll k, ll tot)
    {
        ll x = split(k, tot);
        printf("%lld\n", max[x]);
    }
    inline void modify(ll k, ll tot, ll num)
    {
        ll x = split(k, tot), f = fa[x];
        val[x] = num, tag[x] = 1, sum[x] = size[x] * num;
        if (val[x] >= 0)
            lsum[x] = rsum[x] = max[x] = sum[x];
        else
            lsum[x] = rsum[x] = 0, max[x] = num;
        pushup(f), pushup(fa[f]);
    }
    inline void reverse(ll k, ll tot)
    {
        ll x = split(k, tot), f = fa[x];
        if (!tag[x])
        {
            rev[x] ^= 1;
            std::swap(ch[x][0], ch[x][1]), std::swap(lsum[x], rsum[x]);
            pushup(f), pushup(fa[f]);
        }
    }
    inline void recycle(ll x)
    {
        ll &l = ch[x][0], &r = ch[x][1];
        if (l)
            recycle(l);
        if (r)
            recycle(r);
        q.push(x), fa[x] = l = r = tag[x] = rev[x] = 0;
    }
    inline void erase(ll k, ll tot)
    {
        ll x = split(k, tot), y = fa[x];
        recycle(x), ch[y][0] = 0, pushup(y), pushup(fa[y]);
    }
    inline void build(ll l, ll r, ll f)
    {
        ll mid = (l + r) >> 1, now = id[mid], pre = id[f];
        if (l == r)
        {
            max[now] = sum[now] = a[l], tag[now] = rev[now] = 0;
            lsum[now] = rsum[now] = std::max(a[l], 0ll), size[now] = 1;
        }
        if (l < mid)
            build(l, mid - 1, mid);
        if (r > mid)
            build(mid + 1, r, mid);
        val[now] = a[mid], fa[now] = pre, pushup(now), ch[pre][mid >= f] = now;
    }
    inline void insert(ll k, ll tot)
    {
        for (ll i = 1; i <= tot; i++)
            a[i] = read();
        for (ll i = 1; i <= tot; i++)
            if (!q.empty())
                id[i] = q.front(), q.pop();
            else
                id[i] = ++cnt;
        build(1, tot, 0);
        ll z = id[(tot + 1) >> 1], x = find(root, k + 1), y = find(root, k + 2);
        splay(x, root), splay(y, ch[x][1]), fa[z] = y, ch[y][0] = z;
        pushup(y), pushup(x);
    }
    inline void query_pos(ll k)
    {
        ll x = split(k, 1);
        printf("%lld\n", val[x]);
    }
} T;

int main()
{
    n = read(), m = read();
    T.max[0] = a[1] = a[n + 2] = -inf;
    for (ll i = 1; i <= n; i++)
        a[i + 1] = read();
    for (ll i = 1; i <= n + 2; i++)
        T.id[i] = i;
    T.build(1, n + 2, 0), T.root = (n + 3) >> 1, T.cnt = n + 2;
    while (m--)
    {
        char ch[10];
        scanf("%s", ch + 1);
        if (ch[1] == 'I')
        {
            ll k = read(), tot = read();
            T.insert(k, tot);
        }
        if (ch[1] == 'D')
        {
            ll k = read(), tot = read();
            T.erase(k, tot);
        }
        if (ch[1] == 'R')
        {
            ll k = read(), tot = read();
            T.reverse(k, tot);
        }
        if (ch[1] == 'G' && ch[4] == '-')
        {
            ll k = read(), tot = read();
            T.query(k, tot);
        }
        if (ch[1] == 'G' && ch[4] == '\0')
        {
            ll k = read();
            T.query_pos(k);
        }
        if (ch[1] == 'M' && ch[3] == 'K')
        {
            ll k = read(), tot = read(), val = read();
            T.modify(k, tot, val);
        }
        if (ch[1] == 'M' && ch[3] == 'X')
        {
            ll k = read(), tot = read();
            T.query_max(k, tot);
        }
    }
    return 0;
}
