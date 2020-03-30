#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 4e5 + 10;

struct edge
{
    int next, to;
} e[MaxN];
struct change
{
    int pos, val;
} c[MaxN];
struct query
{
    int l, r, id;
    int pre, lca;
};

query qry[MaxN];
ll now, ans[MaxN];
int n, m, q, cnt, siz, ccnt, qcnt, dfscnt;
int w[MaxN], v[MaxN], col[MaxN], use[MaxN], blo[MaxN], Cnt[MaxN];
int head[MaxN], fa[MaxN], st[MaxN], ed[MaxN], pos[MaxN], dep[MaxN], son[MaxN], top[MaxN], size[MaxN];

void add(int x) { now += v[col[x]] * 1ll * w[++Cnt[col[x]]]; }
void del(int x) { now -= v[col[x]] * 1ll * w[Cnt[col[x]]--]; }
void calc(int x) { (use[x] ? del(x) : add(x)), use[x] ^= 1; }

void modify(int id)
{
    if (use[c[id].pos])
    {
        del(c[id].pos);
        std::swap(c[id].val, col[c[id].pos]);
        add(c[id].pos);
    }
    else
        std::swap(c[id].val, col[c[id].pos]);
}

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int cmp(query a, query b)
{
    if (blo[a.l] ^ blo[b.l])
        return blo[a.l] < blo[b.l];
    else if (blo[a.r] ^ blo[b.r])
        return blo[a.r] < blo[b.r];
    else
        return a.pre < b.pre;
}

void dfs1(int u, int fa)
{
    st[u] = ++dfscnt, pos[dfscnt] = u;
    size[u] = 1, ::fa[u] = fa, dep[u] = dep[fa] + 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs1(v, u), size[u] += size[v];
        if (size[v] > size[son[u]]) son[u] = v;
    }
    ed[u] = ++dfscnt, pos[dfscnt] = u;
}

void dfs2(int u, int top)
{
    ::top[u] = top;
    if (son[u]) dfs2(son[u], top);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

int lca(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            std::swap(u, v);
        u = fa[top[u]];
    }
    return (dep[u] < dep[v]) ? u : v;
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

void solve()
{
    int l = 1, r = 0, cpos = 0;
    for (int i = 1; i <= qcnt; i++)
    {
        while (l > qry[i].l)
            --l, calc(pos[l]);
        while (r < qry[i].r)
            ++r, calc(pos[r]);
        while (l < qry[i].l)
            calc(pos[l]), ++l;
        while (r > qry[i].r)
            calc(pos[r]), --r;
        while (cpos > qry[i].pre)
            modify(cpos), --cpos;
        while (cpos < qry[i].pre)
            ++cpos, modify(cpos);
        if (qry[i].lca) calc(qry[i].lca);
        ans[qry[i].id] = now;
        if (qry[i].lca) calc(qry[i].lca);
    }
    for (int i = 1; i <= qcnt; i++)
        printf("%lld\n", ans[i]);
}

int main()
{
    n = read(), m = read();
    q = read(), siz = pow(2 * n, 0.66);
    for (int i = 1; i <= m; i++)
        v[i] = read();
    for (int i = 1; i <= n; i++)
        w[i] = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    dfs1(1, 0), dfs2(1, 1);
    for (int i = 1; i <= n; i++)
        col[i] = read();
    for (int i = 1; i <= (dfscnt / siz) + !!(dfscnt % siz); i++)
        for(int j = (i - 1) * siz + 1; j <= i * siz; j++)
            blo[j] = i;
    for (int i = 1; i <= q; i++)
    {
        int op = read(), u = read(), v = read(), l;
        if (!op)
            ++ccnt, c[ccnt].pos = u, c[ccnt].val = v;
        else
        {
            l = lca(u, v), qry[++qcnt].pre = ccnt;
            if (st[u] > st[v]) std::swap(u, v);
            if (l == u)
                qry[qcnt].l = st[u], qry[qcnt].r = st[v];
            else
                qry[qcnt].l = ed[u], qry[qcnt].r = st[v], qry[qcnt].lca = l;
            qry[qcnt].id = qcnt;
        }
    }
    std::sort(qry + 1, qry + qcnt + 1, cmp), solve();
    return 0;
}