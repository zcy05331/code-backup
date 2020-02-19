#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 4e6 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN << 1];
std::stack<int> st;
int n, m, cnt, dfsnum;
int head[MaxN], col[MaxN], dfn[MaxN], low[MaxN], vis[MaxN];

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
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

inline void tarjan(int u)
{
    dfn[u] = low[u] = ++dfsnum;
    vis[u] = 1, st.push(u);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!dfn[v])
            tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (vis[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        int v;
        ++cnt;
        do
        {
            v = st.top(), vis[v] = 0;
            col[v] = cnt, st.pop();
        } while (v != u);
    }
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int x = read(), a = read(), y = read(), b = read();
        add_edge(x + a * n, y + (b ^ 1) * n);
        add_edge(y + b * n, x + (a ^ 1) * n);
    }
    cnt = 0;
    for (int i = 1; i <= 2 * n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= n; i++)
        if (col[i] == col[i + n])
            return 0 * printf("IMPOSSIBLE\n");
    printf("POSSIBLE\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", (col[i] < col[i + n]));
    puts("");
    return 0;
}
