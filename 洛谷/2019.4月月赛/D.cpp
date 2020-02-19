#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
const int MaxN = 1010;
const int inf = (1 << 29);
struct edge
{
    int to, next;
};
edge e[MaxN << 1];
int n, m, cnt;
std::vector<int> vec;
int gpa[MaxN], head[MaxN], vis[MaxN], dep[MaxN], fa[MaxN];
inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
inline void dfs(int u, int fa)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

inline void query(int x, int y)
{
    vis[x] = 1;
    vec.push_back(x);
    for (int i = head[x]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!vis[v] && gpa[v] == y)
            query(v, y);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int f;
        scanf("%d", &f);
        if (f)
            add_edge(f, i), add_edge(i, f), fa[i] = f;
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        scanf("%d", &gpa[i]);
    scanf("%d", &m);
    for (int i = 1; i <= n; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            gpa[x] = y;
        }
        else if (op == 2)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            memset(vis, 0, sizeof(vis));
            vec.clear();
            query(x, gpa[x]);
            for (int j = 0; j < vec.size(); j++)
                gpa[vec[j]] = y;
        }
        else if (op == 3)
        {
            int x;
            scanf("%d", &x);
            memset(vis, 0, sizeof(vis));
            vec.clear();
            query(x, gpa[x]);
            printf("%d %d ", gpa[x], vec.size());
            int min = inf, max = 0;
            for (int j = 0; j < vec.size(); j++)
                min = cmin(dep[vec[j]], min), max = cmax(dep[vec[j]], max);
            printf("%d\n", max - min + 1);
        }
    }
    return 0;
}
