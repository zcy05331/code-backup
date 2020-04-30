#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

struct pos
{
    int x, y, id;
};

struct edge
{
    int next, to, dis;
};

struct node
{
    int pos, dis;
    bool operator<(node x) const { return dis > x.dis; }
};

pos p[MaxN];
edge e[MaxN];
int n, m, cnt, ans1, ans2;
int head[MaxN], dis[MaxN], vis[MaxN];

int cmp1(pos a, pos b)
{
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int cmp2(pos a, pos b)
{
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
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

void dijkstra(int s)
{
    std::priority_queue<node> q;
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0, q.push({s, 0});
    while(!q.empty())
    {
        s = q.top().pos, q.pop();
        if(vis[s]) continue; 
        else vis[s] = 1;
        for(int i = head[s]; i; i = e[i].next)
        {
            int v = e[i].to;
            if(dis[v] > dis[s] + e[i].dis)
            {
                dis[v] = dis[s] + e[i].dis;
                if(!vis[v]) q.push({v, dis[v]});
            }
        }
    }
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
        p[i].x = read(), p[i].y = read(), p[i].id = i;
    p[m + 1].x = read(), p[m + 1].y = read(), p[m + 1].id = m + 1;
    p[m + 2].x = read(), p[m + 2].y = read(), p[m + 2].id = m + 2;
    for (int i = 1; i <= m; i++)
    {
        add_edge(i, i + m + 2, 1);
        add_edge(i + m + 2, i, 1);
    }
    int l = 1;
    std::sort(p + 1, p + m + 3, cmp1);
    for (int i = 2; i <= m + 3; i++)
    {
        if (p[l].x != p[i].x)
        {
            if (l == i - 1)
            {
                l = i;
                continue;
            }
            for (int j = l; j < i - 1; j++)
            {
                add_edge(p[j].id, p[j + 1].id, 2 * (p[j + 1].y - p[j].y));
                add_edge(p[j + 1].id, p[j].id, 2 * (p[j + 1].y - p[j].y));
                // printf("add %d %d\n", p[j].id, p[j + 1].id);
            }
            l = i;
        }
    }
    l = 1, std::sort(p + 1, p + m + 3, cmp2);
    for (int i = 2; i <= m + 3; i++)
    {
        if (p[l].y != p[i].y)
        {
            if (l == i - 1)
            {
                l = i;
                continue;
            }
            for (int j = l; j < i - 1; j++)
            {
                add_edge(p[j].id + m + 2, p[j + 1].id + 2 + m, 2 * (p[j + 1].x - p[j].x));
                add_edge(p[j + 1].id + 2 + m, p[j].id + 2 + m, 2 * (p[j + 1].x - p[j].x));
                // printf("add %d %d\n", p[j].id, p[j + 1].id);
            }
            l = i;
        }
    }
    dijkstra(m + 1), ans1 = std::min(dis[m + 2], dis[(m + 2) * 2]);
    // printf("ans1 = %d, %d\n", dis[m + 2], dis[2 * m + 4]);
    dijkstra(2 * m + 3), ans2 = std::min(dis[m + 2], dis[(m + 2) * 2]);
    // printf("ans2 = %d, %d\n", dis[m + 2], dis[2 * m + 4]);
    int ans = std::min(ans1, ans2);
    printf("%d\n", (ans == 0x3f3f3f3f) ? (-1) : ans);
    return 0;
}
