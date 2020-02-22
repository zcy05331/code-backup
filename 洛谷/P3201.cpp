#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;
const int Max = MaxN * 32;

struct node
{
    int lc, rc;
    int sum, l, r;
};

int n, m, ans, a[MaxN], root[MaxN * 10];

struct SegmentTree
{
    int cnt;
    node t[Max];
    void pushup(int rt)
    {
        t[rt].l = ((t[t[rt].lc].l) ? (t[t[rt].lc].l) : (t[t[rt].rc].l));
        t[rt].r = ((t[t[rt].rc].r) ? (t[t[rt].rc].r) : (t[t[rt].rc].r));
        t[rt].sum = t[t[rt].lc].sum + t[t[rt].rc].sum - (t[t[rt].lc].r == t[t[rt].rc].l - 1);
    }
    void insert(int &rt, int l, int r, int pos)
    {
        if (!rt) rt = ++cnt;
        if (l == r)
        {
            t[rt].l = t[rt].r = l, t[rt].sum = 1;
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) insert(t[rt].lc, l, mid, pos);
        else insert(t[rt].rc, mid + 1, r, pos);
        pushup(rt);
    }
    int merge(int x, int y, int l, int r)
    {
        if(!x || !y) return x + y;
        if(l == r)
        {
            t[x].l = t[x].r = l, t[x].sum = 1;
            return x;
        }
        int mid = (l + r) >> 1;
        t[x].lc = merge(t[x].lc, t[y].lc, l, mid);
        t[x].rc = merge(t[x].rc, t[y].rc, mid + 1, r), pushup(x);
        return x;
    }
}T;

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
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read(), ans -= T.t[root[a[i]]].sum;
        T.insert(root[a[i]], 1, n, i), ans += T.t[root[a[i]]].sum;
    }
    while(m--)
    {
        int op = read();
        if(op == 1)
        {
            int x = read(), y = read();
            if(x == y || !root[x]) continue;
            ans -= (T.t[root[x]].sum + T.t[root[y]].sum);
            root[y] = T.merge(root[y], root[x], 1, n), root[x] = 0;
            ans += T.t[root[y]].sum;
        }
        else printf("%d\n", ans);
    }
    return 0;
}
