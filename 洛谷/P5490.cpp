#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

struct line
{
    ll l, r, h, mark;
    bool operator<(line &x) const { return h < x.h; }
};

struct node
{
    int l, r, sum, len;
};

line l[MaxN << 1];
int n, cnt, x[MaxN << 1];

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
    void pushup(int id)
    {
        int l = t[id].l, r = t[id].r;
        if (t[id].sum)
            t[id].len = x[r + 1] - x[l];
        else
            t[id].len = t[id << 1].len + t[id << 1 | 1].len;
    }
    void modify(int id, int l, int r, int val)
    {
        if (x[t[id].r + 1] <= l || r <= x[t[id].l])
            return;
        if (l <= x[t[id].l] && x[t[id].r + 1] <= r)
        {
            t[id].sum += val, pushup(id);
            return;
        }
        modify(id << 1, l, r, val);
        ;
        modify(id << 1 | 1, l, r, val), pushup(id);
    }
}T;

int main()
{
    ll ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int lx, ly, rx, ry;
        scanf("%lld%lld%lld%lld", &lx, &ly, &rx, &ry);
        x[2 * i - 1] = lx, x[2 * i] = rx;
        l[2 * i - 1] = (line){lx, rx, ly, 1};
        l[2 * i] = (line){lx, rx, ry, -1};
    }
    n <<= 1, std::sort(l + 1, l + n + 1);
    std::sort(x + 1, x + n + 1);
    int num = std::unique(x + 1, x + n + 1) - x - 1;
    T.build(1, 1, num - 1);
    for(int i = 0; i < n; i++)
    {
        T.modify(1, l[i].l, l[i].r, l[i].mark);
        ans += T.t[1].len * (l[i + 1].h - l[i].h);
    }
    printf("%lld\n", ans);
    return 0;
}
