#include <bits/stdc++.h>

#define R register
#define ll long long
#define int long long
#define cmin(x, y) (x = std::min(x, y))
#define cmax(x, y) (x = std::max(x, y))
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

int n, m, a, b, c, nowd, root;

struct node
{
    int lc, rc, val, sum;
    int d[2], max[2], min[2];
    bool operator<(const node &x) const { return d[nowd] < x.d[nowd]; }
};

node A[MaxN];

struct kdtree
{
    node t[MaxN];
    void pushup(int x)
    {
        int lc = t[x].lc, rc = t[x].rc;
        t[x].sum = t[x].val + t[lc].sum + t[rc].sum;
        for (int i = 0; i < 2; i++)
        {
            t[x].max[i] = t[x].min[i] = t[x].d[i];
            if (lc)
            {
                cmin(t[x].min[i], t[lc].min[i]);
                cmax(t[x].max[i], t[lc].max[i]);
            }
            if (rc)
            {
                cmin(t[x].min[i], t[rc].min[i]);
                cmax(t[x].max[i], t[rc].max[i]);
            }
        }
    }
    int build(int l, int r, int d)
    {
        nowd = d;
        int mid = (l + r) >> 1;
        std::nth_element(A + l, A + mid, A + r + 1), t[mid] = A[mid];
        if (l < mid) t[mid].lc = build(l, mid - 1, d ^ 1);
        if (r > mid) t[mid].rc = build(mid + 1, r, d ^ 1);
        pushup(mid);
        return mid;
    }
    int chk(int x, int y) { return x * a + y * b < c; }
    int query(int x)
    {
        int cnt = 0;
        cnt += chk(t[x].min[0], t[x].min[1]);
        cnt += chk(t[x].min[0], t[x].max[1]);
        cnt += chk(t[x].max[0], t[x].min[1]);
        cnt += chk(t[x].max[0], t[x].max[1]);
        if (!cnt) return 0;
        if (cnt == 4) return t[x].sum;
        int res = 0;
        if (t[x].lc) res += query(t[x].lc);
        if (t[x].rc) res += query(t[x].rc);
        if (chk(t[x].d[0], t[x].d[1])) res += t[x].val;
        return res;
    }
} T;

signed main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld%lld", &A[i].d[0], &A[i].d[1], &A[i].val);
    root = T.build(1, n, 0);
    while (m--)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("%lld\n", T.query(root));
    }
    return 0;
}