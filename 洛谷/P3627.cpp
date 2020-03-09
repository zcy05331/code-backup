#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN << 1];
std::queue<int> q;
std::stack<int> st;
int n, m, s, p, cnt, dfscnt, colcnt;
int dfn[MaxN], col[MaxN], low[MaxN], ins[MaxN], ok[MaxN], ind[MaxN];
int a[MaxN], u[MaxN], v[MaxN], tmp[MaxN], head[MaxN], val[MaxN], dis[MaxN];

void add_edge(int u, int v)
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

void tarjan(int u)
{
    dfn[u] = low[u] = ++dfscnt;
    ins[u] = 1, st.push(u);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!dfn[v])
            tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (ins[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        int v;
        ++colcnt;
        do
        {
            v = st.top(), st.pop();
            col[v] = colcnt, ins[v] = 0;
        } while (u != v);
    }
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        u[i] = read(), v[i] = read();
        add_edge(u[i], v[i]);
    }
    for (int i = 1; i <= n; i++)
        a[i] = read();
    s = read(), p = read(), cnt = 0;
    for (int i = 1; i <= p; i++)
        tmp[read()] = 1;
    tarjan(s);
    memset(head, 0, sizeof(head));
    for (int i = 1; i <= n; i++)
        val[col[i]] += a[i], ok[col[i]] |= tmp[i];
    for (int i = 1; i <= m; i++)
    {
        if (!col[u[i]] || col[u[i]] == col[v[i]])
            continue;
        add_edge(col[u[i]], col[v[i]]), ++ind[col[v[i]]];
    }
    q.push(col[s]), dis[col[s]] = val[col[s]];
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            dis[v] = std::max(dis[v], dis[u] + val[v]);
            if (--ind[v] == 0) q.push(v);
        }
    }
    int ans = 0;
    for (int i = 1; i <= colcnt; i++)
        ans = std::max(ans, dis[i] * ok[i]);
    printf("%d\n", ans);
    return 0;
}
