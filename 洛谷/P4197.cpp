#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 3e5 + 10;
const int MaxM = 1e6 + 10;
const int Max = MaxN * 20;

struct edge
{
    int next, to;
};

struct Edge
{
    int from, to, dis;
};

struct node
{
    int sum, lc, rc;
};

edge e[MaxM];
Edge t[MaxM];
int n, m, q, now, cnt, num, dfscnt;
int u[MaxM], v[MaxM], d[MaxM], l[MaxM], r[MaxM], dep[MaxM], c[MaxN];
int h[MaxN], b[MaxN], f[MaxN], fa[MaxN][21], head[MaxN], val[MaxN], root[MaxN];

struct SegmentTree
{
    int cnt = 0;
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

int cmp(Edge a, Edge b) { return a.dis < b.dis; }
void link(int u, int v, int d) { ++cnt, t[cnt] = (Edge){u, v, d}; }

int getf(int x)
{
    if (x != f[x]) f[x] = getf(f[x]);
    return f[x];
}

int jump(int u, int k)
{
    for (int i = 20; ~i; i--)
        if (val[fa[u][i]] <= k && fa[u][i])
            u = fa[u][i];
    return u;
}

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
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

void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1, ::fa[u][0] = fa;
    for (int i = 1; i <= 20; i++)
        ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
    l[u] = ++dfscnt, c[dfscnt] = u;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs(v, u);
    }
    r[u] = dfscnt;
}

void kruskal()
{
    cnt = 0, num = n;
    std::sort(t + 1, t + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        int fu = getf(t[i].from), fv = getf(t[i].to);
        if (fu != fv)
        {
            ++num, val[num] = t[i].dis;
            f[num] = f[fu] = f[fv] = num;
            add_edge(num, fu), add_edge(num, fv);
            add_edge(fu, num), add_edge(fv, num);
        }
    }
}

int main()
{
    n = read(), m = read(), q = read();
    for (int i = 1; i <= n; i++)
        f[i] = i, h[i] = b[i] = read();
    for (int i = 1; i <= m; i++)
        u[i] = read(), v[i] = read(), d[i] = read(), link(u[i], v[i], d[i]);
    kruskal(), dfs(num, 0), val[0] = 0x3f3f3f3f;
    std::sort(b + 1, b + n + 1), now = std::unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++)
        h[i] = std::lower_bound(b + 1, b + now + 1, h[i]) - b;
    for (int i = 1; i <= dfscnt; i++)
    {
        if (c[i] <= n)
            T.modify(root[i], root[i - 1], 1, now, h[c[i]]);
        else
            root[i] = root[i - 1];
    }
    while (q--)
    {
        int v = read(), x = read(), k = read();
        int u = jump(v, x), cnt = T.t[root[r[u]]].sum - T.t[root[l[u] - 1]].sum;
        if (cnt < k)
            printf("-1\n");
        else
            printf("%d\n", b[T.query(root[l[u] - 1], root[r[u]], 1, now, cnt - k + 1)]);
    }
    return 0;
}
