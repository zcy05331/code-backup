#include <bits/stdc++.h>

const int MaxN = 1010, MaxM = 500010;

struct edge
{
    int to,next;
}e[MaxM << 1];

int head[MaxN],match[MaxN],vis[MaxN];
int ans, cnt;
int n, m;

inline void add_edge(int u, int v)
{
    cnt++;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

bool dfs(int x)
{
    for(int i = head[x]; i; i = e[i].next)
    {
        int y = e[i].to;
        if(!vis[y])
        {
            vis[y] = 1;
            if(!match[y] || dfs(match[y]))
            {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int num;
    scanf("%d%d%d", &n, &m, &num);
    for(int i = 1; i <= num; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    for(int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if(dfs(i))ans++;
    }
    printf("%d", ans);
    return 0;
}