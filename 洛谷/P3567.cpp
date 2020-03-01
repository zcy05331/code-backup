#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;
const int Max = MaxN * 20;

struct node
{
    int sum, lc, rc;
};

int n, q;
int a[MaxN], root[MaxN];

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
    int query(int u, int v, int l, int r, int len)
    {
        if (l == r) return l;
        int mid = (l + r) >> 1;
        if (2 * (t[t[v].lc].sum - t[t[u].lc].sum) > len)
            return query(t[u].lc, t[v].lc, l, mid, len);
        else if (2 * (t[t[v].rc].sum - t[t[u].rc].sum) > len)
            return query(t[u].rc, t[v].rc, mid + 1, r, len);
        return 0;
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
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), T.modify(root[i], root[i - 1], 1, n, a[i]);
    while (q--)
    {
        int l = read(), r = read();
        printf("%d\n", T.query(root[l - 1], root[r], 1, n, r - l + 1));
    }
    return 0;
}
