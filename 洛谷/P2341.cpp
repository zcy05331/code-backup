#include <bits/stdc++.h>

const int MaxN = 10010, MaxM = 100010;

struct edge
{
    int from, to, next;
};

std::stack<int> st;
edge e[MaxM], e2[MaxM];
int n, m, u, v, scc, cnt, cnt2, dfsnum, fa[MaxN], dp[MaxN], ind[MaxN], sum[MaxN], head[MaxN], head2[MaxN], dfn[MaxN], low[MaxN], col[MaxN], f[MaxN], ins[MaxN];

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].from = u;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void tarjan(int u)
{
    low[u] = dfn[u] = ++dfsnum;
    st.push(u), ins[u] = true;
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
        ++scc;
        do
        {
            v = st.top();
            st.pop();
            ins[v] = 0;
            col[v] = scc;
            fa[v] = u;
            ++f[u];
        } while (u != v);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= m; i++)
    {
        if (fa[e[i].from] != fa[e[i].to])
        {
            ++cnt2;
            e2[cnt2].to = fa[e[i].to];
            e2[cnt2].from = fa[e[i].from];
            e2[cnt2].next = head2[fa[e[i].from]];
            head2[fa[e[i].from]] = cnt2;
            ind[fa[e[i].from]]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ans != 0 && ind[i] == 0 && fa[i] == i)
            return 0 * printf("0");
        else 
            if (ind[i] == 0 && fa[i] == i)
                ans = f[i];
    }
    printf("%d\n", ans);
    return 0;
}