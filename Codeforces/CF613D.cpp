#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

int n, q;

struct tree
{
    struct edge
    {
        int next, to;
    };
    edge e[MaxN];
    int cnt, dfscnt, dfn[MaxN], head[MaxN], dep[MaxN], f[MaxN][21];
    void add_edge(int u, int v)
    {
        ++cnt;
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt;
    }
    void dfs(int u, int fa)
    {
        dfn[u] = ++dfscnt;
        dep[u] = dep[fa] + 1, f[u][0] = fa;
        for(int i = 1; i <= 20; i++)
            f[u][i] = f[f[u][i - 1]][i - 1];
        for(int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if(v == fa)
                continue;
            dfs(v, u);
        }
    }
    int lca(int u, int v)
    {
        if(dep[u] < dep[v]) 
            std::swap(u, v);
        for(int i = 20; ~i; i--)
            if(dep[f[u][i]] >= dep[v])
                u = f[u][i];
        if(u == v) return u;
        for(int i = 20; ~i; i--)
            if(f[u][i] != f[v][i])
                u = f[u][i], v = f[v][i];
        return f[u][0];
    }
}t;

int cmp(int a, int b) { return t.dfn[a] < t.dfn[b]; }

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

struct VirtualTree
{
    struct edge
    {
        int next, to;
    };
    int k, cnt, top;
    edge e[MaxN << 1];
    int head[MaxN], is[MaxN], st[MaxN], f[MaxN], g[MaxN], h[MaxN];
    void add_edge(int u, int v)
    {
        ++cnt;
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt;
    }
    void clear()
    {
        for(int i = 1; i <= k; i++)
            is[h[i]] = 0;
    }
    void dp(int u)
    {
        int v, num = 0;
        f[u] = 0, g[u] = 0;
        if(is[u]) g[u] = 1;
        for(int i = head[u]; i; i = e[i].next)
        {
            v = e[i].to, dp(v), f[u] += f[v];
            if(is[u]) f[u] += g[v];
            else num += g[v];
        }
        if(!is[u] && num > 1) ++f[u], g[u] = 0;
        else if(!is[u] && num == 1) g[u] = 1;
    }
    void build()
    {
        k = read();
        for(int i = 1; i <= k; i++)
            h[i] = read(), is[h[i]] = 1;
        std::sort(h + 1, h + k + 1, cmp);
        st[top = 1] = 1, head[1] = 0;
        for(int i = 1; i <= k; i++)
        {
            if(h[i] != 1)
            {
                int l = t.lca(h[i], st[top]);
                if(l != st[top])
                {
                    while(t.dfn[l] < t.dfn[st[top - 1]])
                        add_edge(st[top - 1], st[top]), --top;
                    if(t.dfn[l] != t.dfn[st[top - 1]])
                        head[l] = 0, add_edge(l, st[top]), st[top] = l;
                    else 
                        add_edge(l, st[top--]);
                }
                head[h[i]] = 0, st[++top] = h[i];
            }
        }
        for(int i = 1; i < top; i++)
            add_edge(st[i], st[i + 1]);
    }
}vt;

int main()
{   
    n = read();
    for(int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        t.add_edge(u, v), t.add_edge(v, u);
    }
    t.dfs(1, 0), q = read();
    while(q--)
    {
        int flag = 0;
        vt.build(), vt.dp(1);
        for(int i = 1; i <= vt.k; i++)
            if(vt.is[t.f[vt.h[i]][0]])
                flag = 1;
        printf("%d\n", flag ? -1 : vt.f[1]), vt.clear();
    }
    return 0;
}
