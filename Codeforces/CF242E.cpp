#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct node
{
    int l, r;
    int sum, tag;
};

int n, m, a[MaxN];

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(int id) { t[id].sum = (t[id << 1].sum + t[id << 1 | 1].sum); }
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r);
    }
    void pushdown(int id)
    {
        if(t[id].tag)
        {
            t[id << 1].tag ^= 1, t[id << 1 | 1].tag ^= 1, t[id].tag = 0;
            t[id << 1].sum = (t[id << 1].r - t[id << 1].l + 1) - t[id << 1].sum;
            t[id << 1 | 1].sum = (t[id << 1 | 1].r - t[id << 1 | 1].l + 1) - t[id << 1 | 1].sum;
        }
    }
    void modify(int id, int l, int r)
    {
        if(l > t[id].r || t[id].l > r)
            return;
        if(l <= t[id].l && t[id].r <= r)
        {
            t[id].tag ^= 1, t[id].sum = (t[id].r - t[id].l + 1) - t[id].sum;
            return;
        }
        pushdown(id);
        modify(id << 1, l, r), modify(id << 1 | 1, l, r), pushup(id);
    }
    int query(int id, int l, int r)
    {
        if(l > t[id].r || t[id].l > r) return 0;
        if(l <= t[id].l && t[id].r <= r)
            return t[id].sum;
        pushdown(id);
        return query(id << 1, l, r) + query(id << 1 | 1, l, r);
    }
} T[20];

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    n = read();
    for(int i = 0; i < 20; i++) T[i].build(1, 1, n);
    for(int i = 1; i <= n; i++)
    {
        a[i] = read();
        for(int j = 0; j < 20; j++)
            if(a[i] & (1 << j))
                T[j].modify(1, i, i);
    }
    m = read();
    while(m--)
    {
        int op = read(), l = read(), r = read(),x;
        if(op == 1)
        {
            ll ans = 0;
            for(int i = 0; i < 20; i++)
                ans += T[i].query(1, l, r) * 1ll * (1ll << i);
            printf("%lld\n", ans);
        }
        else
        {
            x = read();
            for(int i = 0; i < 20; i++) 
                if(x & (1 << i))
                    T[i].modify(1, l, r);
        }
    }
    return 0;
}
