#include <bits/stdc++.h>

const int Max = 100010;

struct edge{int to, next;};
struct node
{
    int dis, pos;
    int operator < (node x)const
    {
        return dis > x.dis;
    }
};

int cnt;
int n, m;
int a[Max];
int vis[Max];
int head[Max];
edge e[Max << 2];
int f[Max], g[Max];
int u[Max], v[Max], op[Max];

inline void add_edge(int u, int v)
{
    cnt++;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void spfa()
{ 
    (f, 0x3f, sizeof(f));
    f[1] = a[1];
    vis[1] = 1;
    std::queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for(int i = head[x]; i; i = e[i].next)
        {
            int y = e[i].to;
            if(f[y] > std::min(f[x], a[y]))
            {
                f[y] = std::min(f[x], a[y]);
                if(!vis[y])
                {
                    vis[y] = 1;
                    q.push(y);
                }
            }
        }
    }
}

int dijkstra()
{
    g[n] = a[n];
    std::priority_queue<node> pq;
    pq.push((node){g[n], n});
    while(!pq.empty())
    {
        node tmp = pq.top();
        pq.pop();
        int x = tmp.pos, d = tmp.dis;
        if(vis[x])
            continue;
        vis[x] = 1;
        for(int i = head[x]; i; i = e[i].next)
        {
            int y = e[i].to;
            if(g[y] < std::max(g[x], a[y]))
            {
                g[y] = std::max(g[x], a[y]);
                if(!vis[y])
                {
                    pq.push((node){g[y], y});
                }
            }
        }
    }
}

int main()
{
    
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u[i], &v[i], &op[i]);
        add_edge(u[i], v[i]);
        if(op[i] == 2)add_edge(v[i], u[i]);
    }
    spfa();
    cnt = 0;
    memset(e, 0, sizeof(e));
    memset(vis, 0, sizeof(vis));
    memset(head, 0, sizeof(head));
    for(int i = 1; i <= m; i++)
    {
        add_edge(v[i], u[i]);
        if(op[i] == 2)add_edge(u[i], v[i]);
    }
    dijkstra();
    int ans = 0;
    for(int i = 1; i <= n; i++)ans = std::max(ans, g[i] - f[i]);
    printf("%d", ans);
    return 0;
}