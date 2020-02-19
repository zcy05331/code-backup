#include <bits/stdc++.h>

const int MaxN = 100010;

struct edge
{
    int next;
    int to;
    int dis;
    int flow;
};

edge e[MaxN << 1];
bool vis[MaxN];
int n, m, s, t;
int maxflow, mincost, cnt;
int dis[MaxN],pre[MaxN];
int head[MaxN], flow[MaxN], last[MaxN]; 

void add_edge(int u, int v, int flow, int dis)
{
    cnt++;
    e[cnt].to = v;
    e[cnt].dis = dis;
    e[cnt].flow = flow;
    e[cnt].next = head[u];
    head[u] = cnt;
}

bool spfa(int s, int t)
{
    memset(dis, 0x7f, sizeof(dis));
    memset(flow, 0x7f, sizeof(flow));
    memset(vis, 0, sizeof(vis));
    std::queue<int>q;
    vis[s] = 1;
    dis[s] = 0;
    pre[t] = -1;
    q.push(s);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for(int i = head[x]; i; i = e[i].next)
        {
            int y = e[i].to;
            if(e[i].flow > 0 && dis[y] > dis[x] + e[i].dis)
            {
                dis[y] = dis[x] + e[i].dis;
                pre[y] = x;
                last[y] = i;
                flow[y] = std::min(flow[x], e[i].flow);
                if(!vis[y])
                {
                    vis[y] = 1;
                    q.push(y);
                }
            }
        }
    }
    return pre[t] != -1;
}

void MCMF()
{
    while(spfa(s, t))
    {
        int now = t;
        maxflow += flow[t];
        mincost += flow[t] * dis[t];
        while(now != s)
        {
            e[last[now]].flow -= flow[t];
            e[last[now] ^ 1].flow += flow[t];
            now = pre[now];
        }
    }
}

int main()
{
    cnt = 1;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i = 1; i <= m; i++)
    {
        int u, v, d, f;
        scanf("%d%d%d%d", &u, &v, &d, &f);
        add_edge(u, v, d, f);
        add_edge(v, u, 0, -f);
    }
    MCMF();
    printf("%d %d", maxflow, mincost);
    return 0;
}