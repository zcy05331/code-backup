#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct node
{
    double max;
    int l, r, ans;
};

int n, m;

struct SegmentTree
{
    node t[MaxN << 2];
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
    }
    int query(int id, double max)
    {
        if (t[id].max <= max) return 0;
        if (t[id].l == t[id].r) return 1;
        if(t[id << 1].max <= max)
            return query(id << 1 | 1, max);
        return t[id].ans - t[id << 1].ans + query(id << 1, max);
    }
    void modify(int id, int pos, double val)
    {
        if(t[id].l == pos && t[id].r == pos)
            return (void) (t[id].ans = 1, t[id].max = val);
        int mid = (t[id].l + t[id].r) >> 1;
        if(pos <= mid) modify(id << 1, pos, val);
        else modify(id << 1 | 1, pos, val);
        t[id].max = std::max(t[id << 1].max, t[id << 1 | 1].max);
        t[id].ans = t[id << 1].ans + query(id << 1 | 1, t[id << 1].max);
    }
} T;

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

signed main()
{
    n = read(), m = read(), T.build(1, 1, n);
    for(int i = 1; i <= m; i++)
    {
        int x = read(), y = read();
        T.modify(1, x, (double)y / x);
        printf("%d\n", T.t[1].ans);
    }
    return 0;
}
