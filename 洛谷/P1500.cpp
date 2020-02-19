#include <bits/stdc++.h>

#define R register
#define ll long long
#define dist(x, y, x1, y1) sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1))
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 5e2 + 10;
const int MaxM = 5e5 + 10;

struct edge
{
    int next, to, flow, cost;
};

edge e[MaxM];
std::string name[MaxN];
std::map<std::string, int> m;
int n, k, s = 200, t = 201, ans, cnt = 1, mincost, maxflow;
int head[MaxN], flow[MaxN], dis[MaxN], pre[MaxN], last[MaxN], vis[MaxN], pos[MaxN][2], a[MaxN][MaxN];

inline void add(int u, int v, int f, int c)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].flow = f;
    e[cnt].cost = c;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void add_edge(int u, int v, int f, int c)
{
    add(u, v, f, c);
    add(v, u, 0, -c);
}

int spfa()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(flow, 0x3f, sizeof(flow));
    memset(vis, 0, sizeof(vis));
    std::queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    pre[t] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].next)
        {
            if (e[i].flow && dis[e[i].to] > dis[u] + e[i].cost)
            {
                int v = e[i].to;
                dis[v] = dis[u] + e[i].cost;
                pre[v] = u;
                last[v] = i;
                flow[v] = cmin(flow[u], e[i].flow);
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return pre[t] != -1;
}

void MCMF()
{
    while (spfa())
    {
        int u = t;
        maxflow += flow[t];
        mincost += flow[t] * dis[t];
        while (u != s)
        {
            e[last[u]].flow -= flow[t];
            e[last[u] ^ 1].flow += flow[t];
            u = pre[u];
        }
    }
}

void change(std::string &s)
{
    int len = s.length();
    for (int i = 0; i < len; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
}

int main()
{
    //freopen("P1500.out", "w", stdout);
    scanf("%d%d", &k, &n);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> pos[i][0] >> pos[i][1] >> name[i];
        change(name[i]);
        m[name[i]] = i;
        add_edge(s, i, 1, 0);
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> pos[i + n][0] >> pos[i + n][1] >> name[i + n];
        change(name[i + n]);
        m[name[i + n]] = i + n;
        add_edge(i + n, t, 1, 0);
    }
    for (int i = 1; i <= n; i++)
        for (int j = n + 1; j <= n + n; j++)
            a[i][j] = 1;
    std::string s, t;
    while (1)
    {
        std::cin >> s;
        if (s == "End")
            break;
        std::cin >> t;
        change(s), change(t);
        int k1, k2;
        for (int i = 1; i <= 2 * n; i++)
        {
            if (s == name[i])
                k1 = i;
            if (t == name[i])
                k2 = i;
        }
        int x = 0;
        std::cin >> x;
        if (k1 > k2)
            std::swap(k1, k2);
        a[k1][k2] = x;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1 + n; j <= n + n; j++)
        {
            bool flag = 1;
            if (dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]) > k)
                continue;
            for (int k = 1; k <= 2 * n; k++)
            {
                if (i != k && j != k)
                {
                    if (dist(pos[i][0], pos[i][1], pos[k][0], pos[k][1]) + dist(pos[k][0], pos[k][1], pos[j][0], pos[j][1]) - dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]) < 0.0001)
                        flag = 0;
                }
            }
            if (flag)
                add_edge(i, j, 1, -a[i][j]);
        }
    }
    MCMF();
    printf("%d\n", -mincost);
    return 0;
}