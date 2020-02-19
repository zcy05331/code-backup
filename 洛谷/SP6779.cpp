#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct edge
{
    int next, to;
};

struct node
{
    int l, r;
    int lsum, rsum, sum, tag, ans;
};

edge e[MaxN << 1];
int n, m, cnt, dfscnt;
int head[MaxN], size[MaxN], dfn[MaxN], f[MaxN];
int a[MaxN], dep[MaxN], top[MaxN], son[MaxN], pre[MaxN];

node merge(node a, node b)
{
    node c = (node){0, 0, 0, 0, 0, 0, 0};
    c.lsum = std::max(a.lsum, a.sum + b.lsum);
    c.rsum = std::max(b.rsum, b.sum + a.rsum);
    c.l = a.l, c.r = b.r, c.sum = a.sum + b.sum;
    c.ans = std::max(a.ans, std::max(b.ans, a.rsum + b.lsum));
    return c;
}

struct SegmentTree
{
    node t[MaxN << 2];
    inline void pushup(int id)
    {
        t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
        t[id].lsum = std::max(t[id << 1].lsum, t[id << 1].sum + t[id << 1 | 1].lsum);
        t[id].rsum = std::max(t[id << 1 | 1].rsum, t[id << 1 | 1].sum + t[id << 1].rsum);
        t[id].ans = std::max(t[id << 1].ans, std::max(t[id << 1 | 1].ans, t[id << 1].rsum + t[id << 1 | 1].lsum));
    }
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r, t[id].tag = 10001;
        if (l == r)
        {
            t[id].sum = a[pre[l]];
            t[id].lsum = t[id].rsum = t[id].ans = std::max(0, a[pre[l]]);
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r), pushup(id);
    }
    inline void pushdown(int id)
    {
        if (t[id].tag != 10001)
        {
            int tag = t[id].tag;
            t[id].tag = 10001, t[id << 1].tag = tag, t[id << 1 | 1].tag = tag;
            t[id << 1].sum = tag * (t[id << 1].r - t[id << 1].l + 1);
            t[id << 1 | 1].sum = tag * (t[id << 1 | 1].r - t[id << 1 | 1].l + 1);
            t[id << 1].lsum = std::max((t[id << 1].r - t[id << 1].l + 1) * tag, 0);
            t[id << 1 | 1].lsum = std::max((t[id << 1 | 1].r - t[id << 1 | 1].l + 1) * tag, 0);
            t[id << 1].rsum = std::max((t[id << 1].r - t[id << 1].l + 1) * tag, 0);
            t[id << 1 | 1].rsum = std::max((t[id << 1 | 1].r - t[id << 1 | 1].l + 1) * tag, 0);
            t[id << 1].ans = std::max((t[id << 1].r - t[id << 1].l + 1) * tag, 0);
            t[id << 1 | 1].ans = std::max((t[id << 1 | 1].r - t[id << 1 | 1].l + 1) * tag, 0);
        }
    }
    void modify(int id, int l, int r, int val)
    {
        if (t[id].l > r || t[id].r < l)
            return;
        if (l <= t[id].l && t[id].r <= r)
        {
            t[id].tag = val, t[id].sum = val * (t[id].r - t[id].l + 1);
            t[id].lsum = std::max((t[id].r - t[id].l + 1) * val, 0);
            t[id].rsum = std::max((t[id].r - t[id].l + 1) * val, 0);
            t[id].ans = std::max((t[id].r - t[id].l + 1) * val, 0);
            return;
        }
        pushdown(id);
        modify(id << 1, l, r, val), modify(id << 1 | 1, l, r, val), pushup(id);
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

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(int u, int fa)
{
    dep[u] = dep[fa] + 1, size[u] = 1, f[u] = fa;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs1(v, u), size[u] += size[v];
        (size[v] > size[son[u]]) ? (son[u] = v) : 0;
    }
}

void dfs2(int u, int Top)
{
    top[u] = Top, dfn[u] = ++dfscnt, pre[dfscnt] = u;
    if (son[u])
        dfs2(son[u], Top);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == f[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

inline void modify_chain(int u, int v, int val)
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
            // printf("debug: %d %d %d %d %d\n", top[v], v, dq1.back().sum, dq1.back().lsum, dq1.back().rsum);
            v = f[top[v]];
        }
        else
        {
            node tmp = T.query(1, dfn[top[u]], dfn[u]);
            std::swap(tmp.lsum, tmp.rsum), dq.push_back(tmp);
            // printf("Debug: %d %d %d %d %d\n", top[u], u, dq.front().sum, dq.front().lsum, dq.front().rsum);
            u = f[top[u]];
        }
    }
    node tmp;
    if (dep[u] < dep[v])
        tmp = T.query(1, dfn[u], dfn[v]);
    else
        tmp = T.query(1, dfn[v], dfn[u]), std::swap(tmp.lsum, tmp.rsum);
    // printf("DEbug: %d %d %d %d %d\n", v, u, tmp.sum, tmp.lsum, tmp.rsum);
    dq.push_back(tmp);
    while (!dq1.empty())
        dq.push_back(dq1.front()), dq1.pop_front();
    node ans = dq.front();
    for (int i = 1; i < dq.size(); i++)
        ans = merge(ans, dq[i]);
    return ans;
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    m = read(), dfs1(1, 0), dfs2(1, 1), T.build(1, 1, n);
    while (m--)
    {
        int op = read(), u = read(), v = read(), c;
        if (op == 1)
            printf("%d\n", query_chain(u, v).ans);
        else if (op == 2)
            c = read(), modify_chain(u, v, c);
    }
    return 0;
}
