#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

struct edge
{
    int next, to;
};

struct node
{
    int l, r;
    int lc, rc, sum, tag;
};

edge e[MaxN];
int n, m, cnt, dfscnt;
int head[MaxN], size[MaxN], hson[MaxN];
int f[MaxN], dep[MaxN], dfn[MaxN], top[MaxN], a[MaxN], pre[MaxN];

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

node merge(node a, node b)
{
    node c;
    c.lc = a.lc, c.rc = b.rc;
    c.sum = a.sum + b.sum;
    if (a.rc == b.lc)
        --c.sum;
    return c;
}

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(int id)
    {
        t[id].lc = t[id << 1].lc, t[id].rc = t[id << 1 | 1].rc;
        t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
        if (t[id << 1].rc == t[id << 1 | 1].lc)
            --t[id].sum;
    }
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r)
        {
            t[id].lc = t[id].rc = a[pre[l]], t[id].sum = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r), pushup(id);
    }
    void pushdown(int id)
    {
        if (t[id].tag)
        {
            int c = t[id].tag;
            t[id << 1].lc = t[id << 1].rc = t[id << 1 | 1].lc = t[id << 1 | 1].rc = c;
            t[id << 1].tag = t[id << 1 | 1].tag = c, t[id << 1].sum = t[id << 1 | 1].sum = 1;
            t[id].tag = 0;
        }
    }
    void modify(int id, int l, int r, int val)
    {
        if (t[id].l > r || t[id].r < l)
            return;
        if (l <= t[id].l && t[id].r <= r)
        {
            t[id].lc = t[id].rc = t[id].tag = val, t[id].sum = 1;
            return;
        }
        pushdown(id), modify(id << 1, l, r, val), modify(id << 1 | 1, l, r, val), pushup(id);
    }
    node query(int id, int l, int r)
    {
        if (l <= t[id].l && t[id].r <= r)
            return t[id];
        pushdown(id);
        int mid = (t[id].l + t[id].r) >> 1;
        if (r <= mid)
            return query(id << 1, l, r);
        if (l > mid)
            return query(id << 1 | 1, l, r);
        return merge(query(id << 1, l, r), query(id << 1 | 1, l, r));
    }
} T;

void dfs1(int u, int fa)
{
    f[u] = fa, dep[u] = dep[fa] + 1, size[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs1(v, u), size[u] += size[v];
        if (size[v] > size[hson[u]])
            hson[u] = v;
    }
}

void dfs2(int u, int Top)
{
    dfn[u] = ++dfscnt, top[u] = Top, pre[dfn[u]] = u;
    if (hson[u])
        dfs2(hson[u], Top);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == f[u] || v == hson[u])
            continue;
        dfs2(v, v);
    }
}

void modify_chain(int u, int v, int val)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            std::swap(u, v);
        T.modify(1, dfn[top[u]], dfn[u], val), u = f[top[u]];
    }
    if (dep[u] < dep[v])
        std::swap(u, v);
    T.modify(1, dfn[v], dfn[u], val);
}

node query_chain(int u, int v)
{
    std::deque<node> dq, dq1;
    dq.clear(), dq1.clear();
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
        {
            node tmp = T.query(1, dfn[top[v]], dfn[v]);
            dq1.push_front(tmp);
            // printf("debug: %d %d %d %d %d\n", top[v], v, dq1.back().sum, dq1.back().lc, dq1.back().rc);
            v = f[top[v]];
        }
        else
        {
            node tmp = T.query(1, dfn[top[u]], dfn[u]);
            std::swap(tmp.lc, tmp.rc), dq.push_back(tmp);
            // printf("Debug: %d %d\n", T.query(1, dfn[2], dfn[2]).lc, T.query(1, dfn[2], dfn[2]).rc);
            // printf("Debug: %d %d %d %d %d\n", top[u], u, dq.front().sum, dq.front().lc, dq.front().rc);
            u = f[top[u]];
        }
    }
    node tmp;
    if (dep[u] < dep[v])
        tmp = T.query(1, dfn[u], dfn[v]);
    else
        tmp = T.query(1, dfn[v], dfn[u]), std::swap(tmp.lc, tmp.rc);
    // printf("DEbug: %d %d %d %d %d\n", v, u, tmp.sum, tmp.lc, tmp.rc);
    dq.push_back(tmp);
    while (!dq1.empty())
        dq.push_back(dq1.front()), dq1.pop_front();
    node ans = dq.front();
    for (int i = 1; i < dq.size(); i++)
        ans = merge(ans, dq[i]);
    return ans;
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
    // freopen("P2486.in", "r", stdin);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    dfs1(1, 1), dfs2(1, 1), T.build(1, 1, n);
    while (m--)
    {
        char s[2];
        scanf("%s", s + 1);
        if (s[1] == 'Q')
        {
            int a = read(), b = read();
            printf("%d\n", query_chain(a, b).sum);
        }
        else
        {
            int a = read(), b = read(), c = read();
            modify_chain(a, b, c);
        }
    }
    return 0;
}
