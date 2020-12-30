#include <bits/stdc++.h>

#define R register
#define ll long long
#define sqr(x) ((x) * (x))
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct node
{
    int l, r;
    double sum, sum2, tag;
};

int n, m;
double a[MaxN];

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(int id)
    {
        t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
        t[id].sum2 = t[id << 1].sum2 + t[id << 1 | 1].sum2;
    }
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r)
        {
            t[id].sum2 = a[l] * a[l];
            return (void)(t[id].sum = a[l]);
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r), pushup(id);
    }
    void pushdown(int id)
    {
        if (t[id].tag != 0)
        {
            double tag = t[id].tag;
            t[id << 1].tag += tag, t[id << 1 | 1].tag += tag, t[id].tag = 0;
            t[id << 1].sum2 += tag * tag * (t[id << 1].r - t[id << 1].l + 1) + 2 * tag * t[id << 1].sum;
            t[id << 1 | 1].sum2 += tag * tag * (t[id << 1 | 1].r - t[id << 1 | 1].l + 1) + 2 * tag * t[id << 1 | 1].sum;
            t[id << 1].sum += tag * (t[id << 1].r - t[id << 1].l + 1);
            t[id << 1 | 1].sum += tag * (t[id << 1 | 1].r - t[id << 1 | 1].l + 1);
        }
    }
    void modify(int id, int l, int r, double v)
    {
        if(t[id].l > r || l > t[id].r) return;
        if(l <= t[id].l && t[id].r <= r)
        {
            t[id].sum2 += v * v * (t[id].r - t[id].l + 1) + 2 * v * t[id].sum;
            t[id].sum += (t[id].r - t[id].l + 1) * v, t[id].tag += v;
            return;
        }
        pushdown(id), modify(id << 1, l, r, v);
        modify(id << 1 | 1, l, r, v), pushup(id);
    }
    double query_sum(int id, int l, int r)
    {
        if(t[id].l > r || l > t[id].r) return 0;
        if(l <= t[id].l && t[id].r <= r) 
            return t[id].sum;
        pushdown(id);
        return query_sum(id << 1, l, r) + query_sum(id << 1 | 1, l, r);
    }
    double query_sum2(int id, int l, int r)
    {
        if(t[id].l > r || l > t[id].r) return 0;
        if(l <= t[id].l && t[id].r <= r)
            return t[id].sum2;
        pushdown(id);
        return query_sum2(id << 1, l, r) + query_sum2(id << 1 | 1, l, r);
    }
} T;
 
signed main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%lf", &a[i]);
    T.build(1, 1, n);
    while(m--)
    {
        double x;
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r), n = r - l + 1;
        if(op == 1) scanf("%lf", &x), T.modify(1, l, r, x);
        else if(op == 2) printf("%.4lf\n", T.query_sum(1, l, r) / n);
        else printf("%.4lf\n", (T.query_sum2(1, l, r) / n) - sqr(T.query_sum(1, l, r) / n));
    }
    return 0;
}
