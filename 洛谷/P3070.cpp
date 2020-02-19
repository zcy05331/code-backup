#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)
#define check(a, b) (((a) > 0) && ((a) <= r) && ((b) > 0) && ((b) <= c))

const int Max = 600, MaxN = 20, MAX = 400000;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct node_
{
    int x, y, dis;
};

struct edge
{
    int to, next, dis;
};

struct node
{
    int pos, dis;
    bool operator<(node x) const
    {
        return dis > x.dis;
    }
};

int r, c, n, cnt;
edge e[MAX << 2];
std::vector<std::pair<int, int>> pos;
int dis[MaxN][MaxN], dist[MAX], vis[MAX], f[1 << MaxN][MaxN];
int head[MAX], a[Max][Max], col[Max][Max], color[MaxN], id[Max][Max];

inline void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void bfs(int x, int y)
{
    std::queue<node_> q;
    col[x][y] = n, q.push((node_){x, y, 0});
    while (!q.empty())
    {
        node_ tmp = q.front();
        q.pop(), x = tmp.x, y = tmp.y;
        for (int i = 0; i < 4; i++)
        {
            int ex = x + dx[i], ey = y + dy[i];
            if (check(ex, ey) && col[ex][ey] == 0 && a[ex][ey] == 0)
                col[ex][ey] = n, q.push((node_){ex, ey, 0});
        }
    }
}

inline void dijkstra(int s)
{
    memset(vis, 0, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    std::priority_queue<node> q;
    q.push((node){s, 0});
    while (!q.empty())
    {
        node tmp = q.top();
        int u = tmp.pos;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (dist[v] > dist[u] + e[i].dis)
            {
                dist[v] = dist[u] + e[i].dis;
                if (!vis[v])
                    q.push((node){v, dist[v]});
            }
        }
    }
}

int main()
{
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 1; j <= c; j++)
        {
            if (s[j - 1] == '.')
                a[i][j] = 2;
            else if (s[j - 1] == 'S')
                a[i][j] = 1;
        }
    }
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (!a[i][j] && !col[i][j])
                n++, bfs(i, j);
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (!col[i][j])
                id[i][j] = ++cnt;
            else if (col[i][j] && !color[col[i][j]])
                id[i][j] = ++cnt, color[col[i][j]] = cnt;
            else if (col[i][j] && color[col[i][j]])
                id[i][j] = color[col[i][j]];
        }
    }
    cnt = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int ex = i + dx[k], ey = j + dy[k];
                if (!check(ex, ey))
                    continue;
                if (a[i][j] <= 1 && a[ex][ey] == 1)
                    add_edge(id[i][j], id[ex][ey], 1);
                else if (a[i][j] == 1 && a[ex][ey] == 0)
                    add_edge(id[i][j], id[ex][ey], 0);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        dijkstra(color[i + 1]);
        for (int j = 0; j < n; j++)
            dis[i][j] = dist[color[j + 1]];
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i < n; i++)
        f[1 << i][i] = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        std::vector<int> vec;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                vec.push_back(j);
        for (int j = 0; j < vec.size(); j++)
            for (int k = 0; k < vec.size(); k++)
                if (k != j)
                    f[i][vec[j]] = std::min(f[i][vec[j]], f[i ^ (1 << vec[j])][vec[k]] + dis[vec[j]][vec[k]]);
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < n; i++)
        ans = std::min(ans, f[(1 << n) - 1][i]);
    printf("%d\n", ans);
    return 0;
}
