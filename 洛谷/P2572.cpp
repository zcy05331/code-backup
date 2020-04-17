#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct node
{
    int l, r, set;
    int sum, lsum, rsum, tag;
};

int n, m, a[MaxN];

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(int id)
    {
        t[id].sum = t[id << 1].rsum + t[id << 1 | 1].lsum;
        t[id].lsum = t[id << 1].lsum, t[id].rsum = t[id << 1 | 1].rsum;
        t[id].sum = std::max(t[id].sum, std::max(t[id << 1].sum, t[id << 1 | 1].sum));
    }
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r, t[id].set = -1;
        if(l == r)
        {
            t[id].sum = t[id].lsum = t[id].rsum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r), pushup(id);
    }
    void pushdown(int id, int l, int r)
    {
        if(t[id].set)
        {
        }
    }
};

int main()
{

    return 0;
}
