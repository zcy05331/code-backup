#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

ll n, ans = 0x7f7f7f7f7f7f7f7f, a[MaxN], p[MaxN], suma[MaxN], pos[MaxN];

struct node
{
    ll l, r, min, tag;
};

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(int id) { t[id].min = std::min(t[id << 1].min, t[id << 1 | 1].min); }
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r)
        {
            t[id].min = suma[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r), pushup(id);
    }
    void pushdown(int id)
    {
        if (t[id].tag)
        {
            ll tag = t[id].tag;
            t[id << 1].tag += tag, t[id << 1 | 1].tag += tag;
            t[id << 1].min += tag, t[id << 1 | 1].min += tag;
            t[id].tag = 0;
        }
    }
    void modify(int id, int l, int r, int val)
    {
        if (t[id].l > r || l > t[id].r)
            return;
        if (l <= t[id].l && t[id].r <= r)
        {
            t[id].min += val, t[id].tag += val;
            return;
        }
        pushdown(id);
        modify(id << 1, l, r, val), modify(id << 1 | 1, l, r, val), pushup(id);
    }
} T;

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

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        p[i] = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), suma[p[i]] = a[i];
    for (int i = 1; i <= n; i++)
        suma[i] += suma[i - 1];
    T.build(1, 0, n);
    for (int i = 1; i < n; i++)
    {
        T.modify(1, 0, p[i] - 1, a[i]);
        T.modify(1, p[i], n, -a[i]), ans = std::min(ans, T.t[1].min);
    }
    printf("%lld\n", ans);
    return 0;
}
