#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;
const int Max = MaxN * 40;

struct node
{
    int sum, max, lc, rc;
};

int n, m, y[MaxN], r[MaxN];

struct SegmentTree
{
    int cnt;
    node t[Max];
    void pushup(int rt)
    {
        t[rt].sum = t[t[rt].lc].sum + t[t[rt].rc].sum;
        t[rt].max = std::max(t[t[rt].lc].max, t[t[rt].rc].max);
    }
    void insert(int &rt, int l, int r, int pos, int val)
    {
        if (!rt)
            rt = ++cnt;
        if (l == r)
        {
            t[rt].sum = 1, t[rt].max = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            insert(t[rt].lc, l, mid, pos, val);
        else
            insert(t[rt].rc, mid + 1, r, pos, val);
    }
    int query_sum(int rt, int l, int r, int ql, int qr)
    {
        if (!rt || l > qr || ql > r)
            return 0;
        if (ql <= l && r <= qr)
            return t[rt].sum;
        int mid = (l + r) >> 1, ans = 0;
        if (ql <= mid)
            ans += query_sum(t[rt].lc, l, mid, ql, qr);
        if (qr > mid)
            ans += query_sum(t[rt].rc, mid + 1, r, ql, qr);
        return ans;
    }
    int query_max(int rt, int l, int r, int ql, int qr)
    {
        if (!rt || l > qr || ql > r)
            return 0;
        if (ql <= l && r <= qr)
            return t[rt].max;
        int mid = (l + r) >> 1, ans = 0;
        if (ql <= mid)
            ans = std::max(ans, query_max(t[rt].lc, l, mid, ql, qr));
        if (qr > mid)
            ans = std::max(ans, query_max(t[rt].rc, mid + 1, r, ql, qr));
        return ans;
    }
}T;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0')
    {
        if(ch == '-')
            f = 0;
        ch = getchar();
    }
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

int main()
{
    n = read();
    for(int i = 1; i <= n; i++)
    {
        y[i] = read(), r[i] = read();
    }
    return 0;
}
