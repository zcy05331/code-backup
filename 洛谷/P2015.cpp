#include <bits/stdc++.h>
const int MaxN = 105;
struct edge
{
    int next, to, dis;
};

int n, m;
edge e[MaxN];
int head[MaxN], cnt;
int f[MaxN][MaxN], b[MaxN];

inline void add_edge(int u, int v, int d)
{
    cnt++;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u, int fa)
{
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(v == fa)
            continue;
        dfs(v, u);
        b[u] += b[v] + 1;
        for(int j = std::min(m, b[u]); j; --j)  
            for(int k = std::min(b[v], j - 1); k >= 0; --k)
                f[u][j] = std::max(f[u][j], f[u][j - k - 1] + f[v][k] + e[i].dis); 
    }
}

int main()
{
   
    scanf("%d%d", &n, &m);
    for(int i = 1; i < n; i++)
    {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        add_edge(u, v, d);
        add_edge(v, u, d);
    }
    dfs(1, 0);
    printf("%d", f[1][m]);
    return 0;
}