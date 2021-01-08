#include <bits/stdc++.h>

#define R register
#define ll long long
#define pir std::pair<int, int>
#define mp(i, j) std::make_pair(i, j)
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct edge
{
    int next, to;
} e[MaxN];

std::vector<int> tmp;
std::map<pir, int> ans, vi;
std::vector<pir> vec[MaxN];
int n, m, q, s, cnt, V[MaxN], vis[MaxN];
int head[MaxN], u[MaxN], v[MaxN], f[MaxN];

int getf(int x)
{
    if (x != f[x])
        f[x] = getf(f[x]);
    return f[x];
}

void merge(int u, int v)
{
    int fu = getf(u), fv = getf(v);
    if (fu != fv) f[fv] = fu;
}

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u)
{
    vis[u] = 1, tmp.push_back(u);
    for (int i = head[u]; i; i = e[i].next)
        if (!vis[e[i].to]) dfs(e[i].to);
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

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), c = read();
        vec[c].push_back(mp(u, v));
    }
    q = read(), s = sqrt(m);
    for (int i = 1; i <= q; i++)
        u[i] = read(), v[i] = read();
    for (int i = 1; i <= q; i++)
    {
        if (!vi[mp(u[i], v[i])])
            vi[mp(u[i], v[i])] = 1;
        else V[i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        if (!vec[i].size())
            continue;
        if (vec[i].size() <= s)
        {
            cnt = 0;
            for (auto x : vec[i])
            {
                add_edge(x.first, x.second);
                add_edge(x.second, x.first);
            }
            for (auto x : vec[i])
            {
                if (!vis[x.first])
                {
                    tmp.clear(), dfs(x.first);
                    for (auto y : tmp)
                        for (auto z : tmp)
                            ans[mp(y, z)]++;
                }
            }
            for (auto x : vec[i])
                vis[x.first] = vis[x.second] = 0;
        }
        else
        {
            for (auto x : vec[i])
                merge(x.first, x.second);
            for (int j = 1; j <= q; j++)
            {
                int fu = getf(u[j]), fv = getf(v[j]);
                if (fu == fv && !V[j])
                    ans[mp(u[j], v[j])]++;
            }
        }
        for (auto x : vec[i])
        {
            f[x.first] = x.first, f[x.second] = x.second;
            head[x.first] = head[x.second] = 0;
        }
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n", ans[mp(u[i], v[i])]);
    return 0;
}
