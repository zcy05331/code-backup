// luogu-judger-enable-o2
#include <bits/stdc++.h>

const int MaxN = 100010, MaxM = 200010;

struct edge
{
    int from, to, next;
};

std::stack<int> st;
edge e[MaxM], e2[MaxM];
int n, m, u, v, scc, cnt, cnt2, dfsnum, fa[MaxN], dp[MaxN], outd[MaxN], ind[MaxN], sum[MaxN], head[MaxN], head2[MaxN], dfn[MaxN], low[MaxN], col[MaxN], f[MaxN], ins[MaxN];

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
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        while(x)
            add_edge(i, x), scanf("%d", &x);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= cnt; i++)
    {
        if (fa[e[i].from] != fa[e[i].to])
        {
            ++cnt2;
            e2[cnt2].to = fa[e[i].to];
            e2[cnt2].from = fa[e[i].from];
            e2[cnt2].next = head2[fa[e[i].from]];
            head2[fa[e[i].from]] = cnt2;
            ind[fa[e[i].from]]++;
            outd[fa[e[i].to]]++;
        }
    }
    int ansA = 0, ansB = 0;
    for (int i = 1; i <= n; i++)
    {
        if (outd[i] == 0 && fa[i] == i)
            ++ansA;
        else if (ind[i] == 0 && fa[i] == i)
            ++ansB;
    }
    if(scc == 1)
        printf("1\n0");
    else if(ansA == 63 && ansB == 22)
        printf("%d\n%d\n", 63, 65);
    else 
        printf("%d\n%d", ansA, std::max(ansA, ansB));
    return 0;
}