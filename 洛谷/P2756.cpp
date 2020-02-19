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

std::priority_queue<std::pair<int, int> > q;
int main()
{
    int num;
    scanf("%d%d", &m, &n);
    int u, v;
    while(scanf("%d%d", &u, &v) && u != -1 && v != -1)
    {
        add_edge(u, v);
    }
    for(int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if(dfs(i))ans++;
    }
    printf("%d\n", ans);
    for(int i = m + 1; i <= m + n; i++)
    {
        if(match[i])q.push(std::make_pair(-match[i], i));
    }
    while(!q.empty())
    {
        printf("%d %d\n", -q.top().first, q.top().second);
        q.pop();
    }
    return 0;
}
