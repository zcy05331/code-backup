#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN << 1];
int n, m, cnt, tot;
int head[MaxN], size[MaxN], dep[MaxN], col[MaxN], f[MaxN], son[MaxN], top[MaxN], num[MaxN];

struct cmp
{
    bool operator()(int a, int b) { return dep[a] < dep[b]; }
};

std::set<int, cmp> s[MaxN];

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(int u, int fa)
{
    f[u] = fa, dep[u] = dep[fa] + 1, size[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs1(v, u), size[u] += size[v];
        (size[v] > size[son[u]]) ? (son[u] = v) : 0;
    }
}

void dfs2(int u, int Top, int cnt)
{
    top[u] = Top, num[u] = cnt;
    if (son[u])
        dfs2(son[u], Top, cnt);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == f[u] || v == son[u])
            continue;
        dfs2(v, v, ++tot);
    }
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
    n = read(), m = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    dfs1(1, 0), dfs2(1, 1, tot = 1);
    while (m--)
    {
        int op = read(), u = read();
        if (op == 0)
        {
            if (col[u])
                col[u] = 0, s[num[u]].erase(u);
            else
                col[u] = 1, s[num[u]].insert(u);
        }
        else
        {
            int ans = 0, d = dep[u];
            while(u)
            {
                if (s[num[u]].size() && dep[*s[num[u]].end()] <= dep[u])
                    if(!ans)
                    ans = *(--s[num[u]].end());
                u = f[top[u]];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
