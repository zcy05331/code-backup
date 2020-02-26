#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;
const int Max = MaxN * 32;

struct node
{
    int sum, lc, rc;
};

int n, m, q;
int a[MaxN], b[MaxN], root[MaxN];

struct SegmentTree
{
    int cnt;
    node t[Max];
    void build(int &rt, int l, int r)
    {
        rt = ++cnt, t[rt].sum = 0;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(t[rt].lc, l, mid);
        build(t[rt].rc, mid + 1, r);
    }
    void modify(int &rt, int pre, int l, int r, int pos)
    {
        rt = ++cnt, t[rt].lc = t[pre].lc;
        t[rt].rc = t[pre].rc, t[rt].sum = t[pre].sum + 1;
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (pos <= mid)
            modify(t[rt].lc, t[pre].lc, l, mid, pos);
        else
            modify(t[rt].rc, t[pre].rc, mid + 1, r, pos);
    }
    int query(int u, int v, int l, int r, int k)
    {
        if (l == r) return l;
        int mid = (l + r) >> 1, num = t[t[v].lc].sum - t[t[u].lc].sum;
        if (k <= num)
            return query(t[u].lc, t[v].lc, l, mid, k);
        else
            return query(t[u].rc, t[v].rc, mid + 1, r, k - num);
    }
} T;

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
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), b[i] = a[i];
    std::sort(b + 1, b + n + 1);
    m = std::unique(b + 1, b + n + 1) - b - 1;
    T.build(root[0], 1, m);
    for (int i = 1; i <= n; i++)
    {
        int val = std::lower_bound(b + 1, b + m + 1, a[i]) - b;
        T.modify(root[i], root[i - 1], 1, m, val);
    }
    while (q--)
    {
        int x = read(), y = read(), z = read();
        int tmp = T.query(root[x - 1], root[y], 1, m, z);
        printf("%d\n", b[tmp]);
    }
    return 0;
}