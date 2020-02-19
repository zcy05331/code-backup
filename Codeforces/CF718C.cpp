#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll mod = 1e9 + 7;
const ll MaxN = 1e5 + 10;

ll n, m, a[MaxN];

struct matrix
{
    ll n, m;
    ll a[3][3];
    matrix(ll x = 2, ll y = 2)
    {
        n = x, m = y;
        memset(a, 0, sizeof(a));
    }
    bool operator==(matrix b)
    {
        if (n != b.n || m != b.m)
            return 0;
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= m; j++)
                if (a[i][j] != b.a[i][j])
                    return 0;
        return 1;
    }
};

struct node
{
    ll l, r;
    matrix sum, tag;
};

matrix I()
{
    matrix i;
    i.a[1][1] = i.a[2][2] = 1;
    return i;
}

matrix add(matrix a, matrix b)
{
    matrix c(a.n, b.m);
    for (ll i = 1; i <= a.n; i++)
        for (ll j = 1; j <= b.m; j++)
            c.a[i][j] = sum(c.a[i][j], a.a[i][j] + b.a[i][j], mod);
    return c;
}

matrix mul(matrix a, matrix b)
{
    matrix c(a.n, b.m);
    for (ll i = 1; i <= a.n; i++)
        for (ll j = 1; j <= b.m; j++)
            for (ll k = 1; k <= a.m; k++)
                c.a[i][j] = sum(c.a[i][j], a.a[i][k] * 1ll * b.a[k][j], mod);
    return c;
}

matrix Null()
{
    matrix c;
    return c;
}

matrix init()
{
    matrix a;
    a.a[1][1] = a.a[1][2] = a.a[2][1] = 1;
    return a;
}

matrix pow(matrix a, ll b)
{
    matrix ret = I();
    while (b)
    {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(ll id) { t[id].sum = add(t[id << 1].sum, t[id << 1 | 1].sum); }
    void build(ll id, ll l, ll r)
    {
        t[id].l = l, t[id].r = r, t[id].tag = I();
        if (l == r)
        {
            t[id].sum = pow(init(), a[l] - 1);
            return;
        }
        ll mid = (l + r) >> 1;
        build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r);
        pushup(id);
    }
    void pushdown(ll id)
    {
        if (!(t[id].tag == I()))
        {
            matrix tag = t[id].tag;
            t[id << 1].tag = mul(t[id << 1].tag, tag);
            t[id << 1 | 1].tag = mul(t[id << 1 | 1].tag, tag);
            t[id << 1].sum = mul(t[id << 1].sum, tag);
            t[id << 1 | 1].sum = mul(t[id << 1 | 1].sum, tag);
            t[id].tag = I();
        }
    }
    void modify(ll id, ll l, ll r, matrix val)
    {
        if (t[id].r < l || t[id].l > r)
            return;
        if (l <= t[id].l && t[id].r <= r)
        {
            t[id].tag = mul(t[id].tag, val);
            t[id].sum = mul(t[id].sum, val);
            return;
        }
        pushdown(id);
        modify(id << 1, l, r, val), modify(id << 1 | 1, l, r, val);
        pushup(id);
    }
    matrix query(ll id, ll l, ll r)
    {
        if (t[id].r < l || t[id].l > r)
            return Null();
        if (l <= t[id].l && t[id].r <= r)
            return t[id].sum;
        pushdown(id);
        return add(query(id << 1, l, r), query(id << 1 | 1, l, r));
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

int main()
{
    n = read(), m = read();
    for (ll i = 1; i <= n; i++)
        a[i] = read();
    T.build(1, 1, n);
    while (m--)
    {
        ll op = read(), l = read(), r = read();
        if (op == 1)
        {
            ll x = read();
            T.modify(1, l, r, pow(init(), x));
        }
        else
            printf("%lld\n", T.query(1, l, r).a[1][1]);
    }
    return 0;
}
