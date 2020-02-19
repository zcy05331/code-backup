# include <bits/stdc++.h>

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
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(!dfn[v])
            tarjan(v), low[u] = std::min(low[u], low[v]);
        else 
            if(ins[v])
                low[u] = std::min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u])
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
            if(u != v)
                f[u] += f[v];
        }   
        while(u != v);
    }
}

inline int solve()
{
    std::queue<int> q;
    for(int i = 1; i <= n; i++) 
    {
        if(!ind[i] && fa[i] == i)
            q.push(i), dp[i] = f[i];
    }   
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = head2[u]; i; i = e2[i].next)
        {
            int v = e2[i].to;
            --ind[v];
            dp[v] = std::max(dp[v], dp[u] + f[v]);
            if(!ind[v])
                q.push(v);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = std::max(ans, dp[i]);
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &f[i]);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i);
    for(int i = 1; i <= m; i++)
    {
        if(fa[e[i].from] != fa[e[i].to])
        {
            ++cnt2; 
            e2[cnt2].to = fa[e[i].to];
            e2[cnt2].from = fa[e[i].from];
            e2[cnt2].next = head2[fa[e[i].from]];
            head2[fa[e[i].from]] = cnt2;
            ind[fa[e[i].to]]++;
        }
    }
    printf("%d", solve());
    return 0;
}