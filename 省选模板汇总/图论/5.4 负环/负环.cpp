#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e3 + 10;
const int MaxM = 1e4 + 10;

struct edge
{
    int next, to, dis;
};

edge e[MaxM];
int n, m, cnt;
int head[MaxN], num[MaxN], dis[MaxN], vis[MaxN];

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
    int x = 0, f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0')
    {
        if(ch == '-')
            f = 0;
        ch = getchar();
    }
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

void init()
{
    n = m = cnt = 0;
    memset(num, 0, sizeof(num));
    memset(dis, 0, sizeof(dis));
    memset(head, 0, sizeof(head));
    memset(vis, 0, sizeof(vis));
}

void Read()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), d = read();
        add_edge(u, v, d);
        if(d >= 0) add_edge(v, u, d);
    }
}

int spfa()
{
    std::queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0, vis[1] = 1, q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop(), vis[x] = 0;
        for (int i = head[x]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (dis[v] > dis[x] + e[i].dis)
            {
                dis[v] = dis[x] + e[i].dis, num[v] = num[x] + 1;
                if (num[v] >= n) return 1;
                if (!vis[v]) vis[v] = 1, q.push(v);
            }
        }
    }
    return 0;
}

int main()
{
    int T = read();
    while (T--)
    {
        init(), Read();
        printf(spfa() ? "YES\n" : "NO\n");
    }
    return 0;
}
