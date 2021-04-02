#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int Max = 2e6 + 10;
const int MaxN = 2e5 + 10;

struct query
{
    int tim, l, r, id;
} q[MaxN];

struct change
{
    int tim, pos, pre, v;
} c[MaxN * 5];

std::set<int> col[Max];
int n, m, cnt, cntq, cntc, a[MaxN], ans[MaxN], lst[MaxN];

struct BIT
{
    ll c[MaxN << 1];
    ll lowbit(ll x) { return x & (-x); }
    void modify(ll x, ll val)
    {
        while (x <= n)
            c[x] += val, x += lowbit(x);
    }
    ll query(ll x)
    {
        ll ret = 0;
        while (x)
            ret += c[x], x -= lowbit(x);
        return ret;
    }
} T;

int cmp1(change a, change b) { return a.pre < b.pre; }
int cmp2(query a, query b) { return a.l < b.l; }

char get()
{
    char ch = getchar();
    while (!isalpha(ch))
        ch = getchar();
    return ch;
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

void solve(int l, int r, int cl, int cr, int ql, int qr)
{
    if (l >= r || cl > cr || ql > qr) return;
    int mid = (l + r) >> 1, midc = cl - 1, midq = ql - 1, now = cl;
    for (int i = cl; i <= cr; i++)
        if (c[i].tim <= mid) midc = i;
    for (int i = ql; i <= qr; i++)
        if (q[i].tim <= mid) midq = i;
    solve(l, mid, cl, midc, ql, midq);
    solve(mid + 1, r, midc + 1, cr, midq + 1, qr);
    std::sort(c + cl, c + midc + 1, cmp1);
    std::sort(q + midq + 1, q + qr + 1, cmp2);
    for (int i = midq + 1; i <= qr; i++)
    {
        while (now <= midc && c[now].pre < q[i].l)
            T.modify(c[now].pos, c[now].v), ++now;
        ans[q[i].id] += T.query(q[i].r) - T.query(q[i].l - 1);
    }
    for (int i = cl; i < now; i++)
        T.modify(c[i].pos, -c[i].v);
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read(), lst[i] = (!col[a[i]].size() ? 0 : *--col[a[i]].end());
        col[a[i]].insert(i), c[++cntc] = {++cnt, i, lst[i], 1};
    }
    for (int i = 1; i <= m; i++)
    {
        int op = get(), x = read(), y = read(), pre, npre, suf, nsuf;
        if (op == 'Q')
            q[++cntq] = {++cnt, x, y, cntq};
        else
        {
            if (col[y].lower_bound(x) == col[y].begin())
                pre = 0;
            else
                pre = *--col[y].lower_bound(x);
            c[++cntc] = {++cnt, x, lst[x], -1}, lst[x] = pre;
            c[++cntc] = {++cnt, x, lst[x], 1}, col[a[x]].erase(x);
            if (col[a[x]].lower_bound(x) == col[a[x]].begin())
                npre = 0;
            else
                npre = *--col[a[x]].lower_bound(x);
            if (col[a[x]].upper_bound(x) == col[a[x]].end())
                suf = -1;
            else
                suf = *col[a[x]].upper_bound(x);
            a[x] = y;
            if (~suf)
            {
                c[++cntc] = {++cnt, suf, lst[suf], -1}, lst[suf] = npre;
                c[++cntc] = {++cnt, suf, lst[suf], 1};
            }
            if (col[y].upper_bound(x) == col[y].end())
                nsuf = -1;
            else
                nsuf = *col[y].upper_bound(x);
            col[y].insert(x);
            if (~nsuf)
            {
                c[++cntc] = {++cnt, nsuf, lst[nsuf], -1}, lst[nsuf] = x;
                c[++cntc] = {++cnt, nsuf, lst[nsuf], 1};
            }
        }
    }
    solve(1, cnt, 1, cntc, 1, cntq);
    for (int i = 1; i <= cntq; i++)
        printf("%d\n", ans[i]);
    return 0;
}