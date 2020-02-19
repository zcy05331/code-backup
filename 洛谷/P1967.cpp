#include <bits/stdc++.h>
const int MaxN = 10010, MaxM = 50010;
struct edge1
{
    int u, v, d;
};

struct edge
{
    int next, to, dis;
};

int n, m;

int cnt1;
edge1 e1[MaxM << 1];

int cnt;
int head[MaxN];
edge e[MaxN << 1];

int fa[MaxN];

int cnt_edge;
int used[MaxN];

int dep[MaxN];
bool vis[MaxN];
int f[MaxN][21];
int w[MaxN][21];

inline void add_edge1(int u, int v, int d)
{
    cnt1++;
    e1[cnt1].u = u;
    e1[cnt1].v = v;
    e1[cnt1].d = d;
}

inline void add_edge(int u, int v, int d)
{
    cnt++;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline int cmp(edge1 a, edge1 b)
{
    return a.d > b.d;
}

inline int getf(int x)
{
    if (fa[x] != x)
        fa[x] = getf(fa[x]);
    return fa[x];
}

inline void merge(int x, int y)
{
    int fx = getf(x);
    int fy = getf(y);
    fa[fx] = fy;
}

inline void kruskal()
{
    std::sort(e1 + 1, e1 + cnt1 + 1, cmp);
    for (int i = 1; i <= cnt1; i++)
    {
        int fx = getf(e1[i].u);
        int fy = getf(e1[i].v);
        if (fx != fy)
        {
            used[++cnt_edge] = i;
            //printf("edge : %d %d %d %d %d \n", cnt_edge, i, e1[i].u, e1[i].v, e1[i].d);
            merge(fx, fy);
        }
        if (cnt_edge == n - 1)
            break;
    }
}

inline void init()
{
    for (int i = 1; i <= cnt_edge; i++)
        add_edge(e1[used[i]].u, e1[used[i]].v, e1[used[i]].d), add_edge(e1[used[i]].v, e1[used[i]].u, e1[used[i]].d);
}

inline void dfs(int u)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (dep[v] == 0)
        {
            dep[v] = dep[u] + 1;
            f[v][0] = u;
            w[v][0] = e[i].dis;
            dfs(v);
        }
    }
}

inline void prepare()
{
    for (int i = 1; i <= n; i++)
    {
        if (dep[i] == 0)
        {
            dep[i] = 1;
            f[i][0] = 0;
            dfs(i);
        }
    }
    dfs(1);
    for (int i = 1; i <= 20; i++)
    {
        for (int x = 1; x <= n; x++)
        {
            f[x][i] = f[f[x][i - 1]][i - 1];
            w[x][i] = std::min(w[x][i - 1], w[f[x][i - 1]][i - 1]);
            //printf("%d %d %d %d\n", x, i, f[x][i], w[x][i]);
        }
    }
}

inline int lca(int x, int y)
{
    int ans = 0x7f7f7f7f;
    if (getf(x) != getf(y))
        return -1;
    if (dep[x] < dep[y])
        std::swap(x, y);
    for (int i = 20; i >= 0; i--)
    {
        if (dep[f[x][i]] >= dep[y])
        {
            ans = std::min(ans, w[x][i]);
            x = f[x][i];
        }
    }
    //printf("ans = %d\n", ans);
    if (x == y)
        return ans;
    for (int i = 20; i >= 0; i--)
    {
        if (f[x][i] != f[y][i])
        {
            ans = std::min(ans, std::min(w[x][i], w[y][i]));
            x = f[x][i];
            y = f[y][i];
        }
    }
    ans = std::min(ans, std::min(w[x][0], w[y][0]));
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        add_edge1(u, v, d);
    }
    kruskal();
    init();
    prepare();
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    return 0;
}