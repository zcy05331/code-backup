#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN << 1];
int n, m, cnt;
int head[MaxN], fir[MaxN], dep[MaxN];
int pos[MaxN << 3], lg2[MaxN], Dep[MaxN << 3], f[MaxN << 3][22];

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u, int fa)
{
    fir[u] = ++cnt, pos[cnt] = u;
    Dep[cnt] = dep[u] = dep[fa] + 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs(v, u), pos[++cnt] = u, Dep[cnt] = dep[u];
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

void prework()
{
    lg2[0] = -1;
    for (int i = 1; i <= cnt; i++)
        lg2[i] = lg2[i >> 1] + 1, f[i][0] = i;
    for (int j = 1; (1 << j) <= cnt; j++)
    {
        for (int i = 1; i <= cnt - (1 << j) + 1; i++)
            f[i][j] = ((Dep[f[i][j - 1]] <= Dep[f[i + (1 << (j - 1))][j - 1]]) ? f[i][j - 1] : f[i + (1 << (j - 1))][j - 1]);
    }
}

int query(int l, int r)
{
    if (l > r) std::swap(l, r);
    int k = lg2[r - l + 1];
    return ((Dep[f[l][k]] <= Dep[f[r - (1 << k) + 1][k]]) ? pos[f[l][k]] : pos[f[r - (1 << k) + 1][k]]);
}

int main()
{
    int rt = 0;
    n = read(), m = read(), rt = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    cnt = 0, dfs(rt, 0), prework();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        printf("%d\n", query(fir[u], fir[v]));
    }
    return 0;
}
