#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;
const int Max = MaxN * 30;

struct node
{
    int sum, lc, rc;
};

struct edge
{
    int next, to;
};

edge e[MaxN << 1];
int n, m, q, cnt, num;
int a[MaxN], b[MaxN], f[MaxN], head[MaxN], root[MaxN], size[MaxN];

struct LinkCutTree
{
    int fa[MaxN], ch[MaxN][2], rev[MaxN];
    void pushdown(int x)
    {
        if (rev[x])
        {
            rev[x] = 0, rev[ch[x][0]] ^= 1;
            rev[ch[x][1]] ^= 1, std::swap(ch[x][0], ch[x][1]);
        }
    }
    int check(int x) { return ch[fa[x]][1] == x; }
    int isroot(int x) { return (ch[fa[x]][0] != x && ch[fa[x]][1] != x); }
    void rotate(int x)
    {
        int f = fa[x], gf = fa[f], tp = check(x);
        if (!isroot(f)) ch[gf][check(f)] = x;
        fa[x] = gf, fa[f] = x, fa[ch[x][tp ^ 1]] = f;
        ch[f][tp] = ch[x][tp ^ 1], ch[x][tp ^ 1] = f;
    }
    void update(int x)
    {
        if (!isroot(x))
            update(fa[x]);
        pushdown(x);
    }
    void splay(int x)
    {
        update(x);
        for (int y = 0; y = fa[x], !isroot(x); rotate(x))
            if (!isroot(y))
                rotate((check(x) ^ check(y)) ? x : y);
    }
    int access(int x)
    {
        int res = 0;
        for (int y = 0; x; y = x, x = fa[x])
            splay(x), ch[x][1] = y, res = x;
        return res;
    }
    void makeroot(int x) { access(x), splay(x), rev[x] ^= 1; }
    void link(int x, int y) { makeroot(x), fa[x] = y; }
    int lca(int x, int y)
    {
        access(x);
        return access(y);
    }
} lct;

struct SegmentTree
{
    int cnt;
    node t[Max];
    void build(int &rt, int l, int r)
    {
        rt = ++cnt;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(t[rt].lc, l, mid);
        build(t[rt].rc, mid + 1, r);
    }
    void insert(int &rt, int pre, int l, int r, int pos)
    {
        rt = ++cnt, t[rt].lc = t[pre].lc;
        t[rt].rc = t[pre].rc, t[rt].sum = t[pre].sum + 1;
        if(l == r) return;
        int mid = (l + r) >> 1;
        if (pos <= mid)
            insert(t[rt].lc, t[pre].lc, l, mid, pos);
        else
            insert(t[rt].rc, t[pre].rc, mid + 1, r, pos);
    }
    int query(int u, int v, int x, int y, int l, int r, int k)
    {
        if (l == r) return l;
        int mid = (l + r) >> 1, sum = t[t[u].lc].sum + t[t[v].lc].sum - t[t[x].lc].sum - t[t[y].lc].sum;
        if (k <= sum)
            return query(t[u].lc, t[v].lc, t[x].lc, t[y].lc, l, mid, k);
        else
            return query(t[u].rc, t[v].rc, t[x].rc, t[y].rc, mid + 1, r, k - sum);
    }
} st;

int getf(int x)
{
    if (x != f[x])
        f[x] = getf(f[x]);
    return f[x];
}

void prework()
{
    std::sort(b + 1, b + n + 1);
    num = std::unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + num + 1, a[i]) - b;
}

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u, int fa)
{
    st.insert(root[u], root[fa], 1, num, a[u]);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs(v, u);
    }
}

void merge(int u, int v)
{
    int fu = getf(u), fv = getf(v);
    add_edge(u, v), add_edge(v, u);
    if (size[fu] < size[fv]) std::swap(u, v), std::swap(fu, fv);
    size[fu] += size[fv], lct.link(u, v), f[fv] = fu, dfs(v, u);
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
    int lastans = 0, testcase = read();
    n = read(), m = read(), q = read();
    for (int i = 1; i <= n; i++)
        a[i] = b[i] = read(), f[i] = i, size[i] = 1;
    prework(), st.build(root[0], 1, num);
    for (int i = 1; i <= n; i++)
        st.insert(root[i], root[0], 1, num, a[i]);
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        merge(u, v);
    }
    char op[2];
    while (q--)
    {
        scanf("%s", op + 1);
        if (op[1] == 'Q')
        {
            int u = read() ^ lastans, v = read() ^ lastans, k = read() ^ lastans, lca, flca;
            lct.makeroot(getf(u)), lca = lct.lca(u, v);
            if (getf(u) == lca)
                flca = 0;
            else
            {
                lct.access(lca), lct.splay(lca);
                flca = lct.ch[lca][0];
                while (lct.ch[flca][1])
                    flca = lct.ch[flca][1], lct.pushdown(flca);
            }
            lastans = b[st.query(root[u], root[v], root[lca], root[flca], 1, num, k)], printf("%d\n", lastans);
        }
        else
        {
            int u = read(), v = read();
            u ^= lastans, v ^= lastans, merge(u, v);
        }
    }
    return 0;
}
