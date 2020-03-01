#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 4e5 + 10;
const int Max = MaxN * 20;

struct node
{
    int sum, lc, rc;
};

int n, m, q;
int a[MaxN], b[MaxN], l[MaxN], r[MaxN], k[MaxN], root[MaxN];

struct SegmentTree
{
    int cnt;
    node t[Max];
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
    int query(int u, int v, int l, int r, int ql, int qr)
    {
        if (l > qr || ql > r) return 0;
        if (ql <= l && r <= qr) return t[v].sum - t[u].sum;
        int mid = (l + r) >> 1;
        return query(t[u].lc, t[v].lc, l, mid, ql, qr) + query(t[u].rc, t[v].rc, mid + 1, r, ql, qr);
    }
} T;

void prework()
{
    std::sort(b + 1, b + n + q + 1);
    m = std::unique(b + 1, b + n + q + 1) - b - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + m + 1, a[i]) - b;
    for (int i = 1; i <= q; i++)
        k[i] = std::lower_bound(b + 1, b + m + 1, k[i]) - b;
}

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
        a[i] = b[i] = read();
    q = read();
    for (int i = 1; i <= q; i++)
        l[i] = read(), r[i] = read(), b[i + n] = k[i] = read();
    prework();
    for (int i = 1; i <= n; i++)
        T.modify(root[i], root[i - 1], 1, m, a[i]);
    for (int i = 1; i <= q; i++)
        printf("%d\n", T.query(root[l[i] - 1], root[r[i]], 1, m, k[i] + 1, m));
    return 0;
}
