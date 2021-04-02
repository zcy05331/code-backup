#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 2e6 + 10;

struct node
{
    int u, v, d;
};

struct edge
{
    int next, to;
} e[MaxN << 3];

std::vector<node> ed;
std::vector<int> p[MaxN];
int n, m, cnt, st[MaxN], end[MaxN], rt[MaxN];
int head[MaxN], dep[MaxN], f[MaxN], con[MaxN], fa[MaxN][21];

bool operator<(node a, node b) { return a.d < b.d; }

int getf(int u)
{
    if (u != f[u])
        f[u] = getf(f[u]);
    return f[u];
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
    rt[u] = (fa == -1) ? u : rt[fa];
    ::fa[u][0] = fa, dep[u] = (~fa) ? dep[fa] + 1 : 1;
    for (int i = 1; i <= 20; i++)
    {
        if (~::fa[u][i - 1])
            ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
        else
            ::fa[u][i] = -1;
    }
    for (int i = head[u]; i; i = e[i].next)
        dfs(e[i].to, u);
}

int lca(int u, int v)
{
    if (rt[u] != rt[v]) return -1;
    if (dep[u] < dep[v]) std::swap(u, v);
    for (int i = 20; ~i; i--)
        if (~fa[u][i] && dep[fa[u][i]] >= dep[v])
            u = fa[u][i];
    if (u == v) return u;
    for (int i = 20; ~i; i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

void init(int N, int M, std::vector<int> U, std::vector<int> V, std::vector<int> W)
{
    n = N, m = M;
    for (int i = 0; i < n; i++)
        f[i] = i;
    for (int i = 0; i < m; i++)
        ed.push_back({U[i], V[i], W[i]});
    std::sort(ed.begin(), ed.end());
    for (int i = 0; i < n; i++)
        st[i] = end[i] = rt[i] = i, p[i].push_back(i);
    for (int i = 0; i < m; i++)
    {
        int u = ed[i].u, v = ed[i].v, fu = getf(u), fv = getf(v);
        if (p[fu].size() < p[fv].size()) std::swap(u, v), std::swap(fu, fv);
        if (fu == fv)
        {
            if (!con[fu])
            {
                con[fu] = 1;
                for (int j = 0; j < p[fu].size(); j++)
                    add_edge(i + n, p[fu][j]);
                rt[fu] = i + n;
            }
        }
        else
        {
            if (con[fu] || con[fv])
            {
                if (con[fu])
                    add_edge(i + n, rt[fu]);
                else
                {
                    for (int j = 0; j < p[fu].size(); j++)
                        add_edge(i + n, p[fu][j]);
                }
                if (con[fv])
                    add_edge(i + n, rt[fv]);
                else
                {
                    for (int j = 0; j < p[fv].size(); j++)
                        add_edge(i + n, p[fv][j]);
                }
                con[fu] = 1, rt[fu] = i + n, f[fv] = fu;
            }
            else
            {
                if ((u == st[fu] || u == end[fu]) && (v == st[fv] || v == end[fv]))
                {
                    st[fu] = u ^ st[fu] ^ end[fu];
                    end[fu] = v ^ st[fv] ^ end[fv];
                    for (int j = 0; j < p[fv].size(); j++)
                        p[fu].push_back(p[fv][j]);
                    f[fv] = fu;
                }
                else
                {
                    con[fu] = 1;
                    for (int j = 0; j < p[fu].size(); j++)
                        add_edge(i + n, p[fu][j]);
                    for (int j = 0; j < p[fv].size(); j++)
                        add_edge(i + n, p[fv][j]);
                    f[fv] = fu, rt[fu] = i + n;
                }
            }
        }
    }
    for (int i = n + m - 1; ~i; i--)
        if (!dep[i]) dfs(i, -1);
}

int getMinimumFuelCapacity(int X, int Y)
{

    int u = lca(X, Y);
    if (u == -1) return -1;
    return ed[u - n].d;
}