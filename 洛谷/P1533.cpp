#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 3e5 + 10;
const int Max = MaxN << 4;

struct node
{
    int sum, lc, rc;
};

node t[Max << 1];
int n, m, q, cnt, a[MaxN], b[MaxN], rt[MaxN];

struct SegmentTree
{
    void insert(int &rt, int pre, int l, int r, int pos)
    {
        rt = ++cnt, t[rt].sum = t[pre].sum + 1;
        t[rt].lc = t[pre].lc, t[rt].rc = t[pre].rc;
        if(l == r) return;
        int mid = (l + r) >> 1;
        if(pos <= mid) insert(t[rt].lc, t[pre].lc, l, mid, pos);
        else insert(t[rt].rc, t[pre].rc, mid + 1, r, pos);
    }
    int query(int u, int v, int l, int r, int k)
    {
        if(l == r) return l;
        int mid = (l + r) >> 1, num = t[t[v].lc].sum - t[t[u].lc].sum;
        if(k <= num) return query(t[u].lc, t[v].lc, l, mid, k);
        else return query(t[u].rc, t[v].rc, mid + 1, r, k - num);
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
    n = read(), q = read();
    for(int i = 1; i <= n; i++)
        a[i] = read(), b[i] = a[i];
    std::sort(b + 1, b + n + 1);
    m = std::unique(b + 1, b + n + 1) - b - 1;
    for(int i = 1; i <= n; i++)
    {
        a[i] = std::lower_bound(b + 1, b + m + 1, a[i]) - b;
        T.insert(rt[i], rt[i - 1], 0, m, a[i]), meow("xzakioi\n");
    }
    while(q--)
    {
        int l = read(), r = read(), k = read();
        printf("%d\n", b[T.query(rt[l - 1], rt[r], 0, m, k)]);
    }
    return 0;
}
