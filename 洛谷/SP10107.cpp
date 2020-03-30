#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct edge
{
    int next, to;
};

struct query
{
    int l, r;
    int pos, lca, id;
};

query q[MaxN];
edge e[MaxN << 1];
int n, m, cnt, siz, now, dfscnt, f[MaxN], size[MaxN], son[MaxN], pos[MaxN], Cnt[MaxN];
int a[MaxN], b[MaxN], st[MaxN], ed[MaxN], dep[MaxN], top[MaxN], ans[MaxN], head[MaxN], used[MaxN];

void add(int x) { if(++Cnt[a[x]] == 1) ++now; }
void del(int x) { if(--Cnt[a[x]] == 0) --now; }
void calc(int x) { (used[x] ? del(x) : add(x)), used[x] ^= 1; }

int cmp(query a, query b)
{
    if(a.pos != b.pos)
        return a.pos < b.pos;
    return a.r < b.r;
}

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(int u, int fa)
{
    dep[u] = dep[fa] + 1, st[u] = ++dfscnt;
    size[u] = 1, f[u] = fa, pos[dfscnt] = u;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs1(v, u), size[u] += size[v];
        if(size[v] > size[son[u]]) son[u] = v;
    }
    ed[u] = ++dfscnt, pos[dfscnt] = u;
}

void dfs2(int u, int top)
{
    ::top[u] = top;
    if(son[u]) dfs2(son[u], top);
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(v == f[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

int lca(int u, int v)
{
    while(top[u] != top[v])
    {
        if(dep[top[u]] < dep[top[v]]) 
            std::swap(u, v);
        u = f[top[u]];
    }
    return (dep[u] < dep[v]) ? u : v;
}

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

int main()
{
    int Num = 0;
    n = read(), m = read(), siz = sqrt(n);
    for(int i = 1; i <= n; i++)
        a[i] = b[i] = read();
    std::sort(b + 1, b + n + 1);
    Num = std::unique(b + 1, b + n + 1) - b - 1;
    for(int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + Num + 1, a[i]) - b;
    for(int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    dfs1(1, 0), dfs2(1, 1);
    for(int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), l = lca(u, v);
        if(st[u] > st[v]) std::swap(u, v);
        if(l == u) q[i].l = st[u], q[i].r = st[v];
        else q[i].l = ed[u], q[i].r = st[v], q[i].lca = l;
        q[i].pos = (q[i].l - 1) / siz + 1, q[i].id = i;
    }
    int l = 1, r = 0;
    std::sort(q + 1, q + m + 1, cmp);
    for(int i = 1; i <= m; i++)
    {
        while(l > q[i].l) --l, calc(pos[l]); 
        while(r < q[i].r) ++r, calc(pos[r]);
        while(l < q[i].l) calc(pos[l]), ++l;
        while(r > q[i].r) calc(pos[r]), --r;
        if(q[i].lca) calc(q[i].lca);
        ans[q[i].id] = now;
        if(q[i].lca) calc(q[i].lca);
    }
    for(int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}
