#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)
#define id(x, y, op) (((x)-1) * m + (y) + op * n * m)
#define check(x, y) (x > 0 && x <= n && y > 0 && y <= m && ch[x][y] != 'w')

using std::string;
using std::vector;
const int MaxN = 1e5 + 10;
const int MaxM = 5e5 + 10;
const int inf = 0x3f3f3f3f;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

struct edge
{
    int next, to, flow, cost;
} e[MaxM << 1];

int n, m, s, t, cnt = 1, num, num1, cost, flow;
int head[MaxN], cur[MaxN], dis[MaxN], vis[MaxN];

void add(int u, int v, int f, int c)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].flow = f;
    e[cnt].cost = c;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void add_edge(int u, int v, int f, int c) { add(u, v, f, c), add(v, u, 0, -c); }

int spfa()
{
    std::queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    memcpy(cur, head, sizeof(head));
    dis[s] = 0, q.push(s), vis[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to, c = e[i].flow;
            if (dis[v] > dis[u] + e[i].cost && c)
            {
                dis[v] = dis[u] + e[i].cost;
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    return (dis[t] != inf);
}

int dinic(int u, int flow)
{
    if (u == t)
    {
        ::flow += flow;
        return flow;
    }
    int rest = flow;
    vis[u] = 1;
    for (int i = cur[u]; i && rest; i = e[i].next)
    {
        int v = e[i].to, c = e[i].flow;
        if (!vis[v] && (dis[v] == dis[u] + e[i].cost) && c)
        {
            cur[u] = i;
            int k = dinic(v, std::min(rest, e[i].flow));
            rest -= k, e[i].flow -= k, e[i ^ 1].flow += k, cost += k * e[i].cost;
        }
    }
    vis[u] = 0;
    return flow - rest;
}

void mcmf()
{
    while (spfa())
    {
        memset(vis, 0, sizeof(vis));
        dinic(s, inf);
    }
}

class CurvyonRails
{
public:
    char ch[50][50];
    int getmin(vector<string> vs)
    {
        n = vs.size(), m = vs[0].size();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                ch[i][j] = vs[i - 1][j - 1];
        s = 20001, t = 20002;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (ch[i][j] == 'w')
                    continue;
                if ((i + j) & 1)
                {
                    num++;
                    add_edge(s, id(i, j, 0), 2, 0);
                    if (ch[i][j] == 'C')
                    {
                        int ex = 0, ey = 0;
                        add_edge(id(i, j, 0), id(i, j, 1), 1, 0);
                        add_edge(id(i, j, 0), id(i, j, 2), 1, 0);
                        add_edge(id(i, j, 0), id(i, j, 1), 1, 1);
                        add_edge(id(i, j, 0), id(i, j, 2), 1, 1);
                        ex = i + dx[0], ey = j + dy[0];
                        if (check(ex, ey))
                            add_edge(id(i, j, 1), id(ex, ey, 1), 1, 0);
                        ex = i + dx[1], ey = j + dy[1];
                        if (check(ex, ey))
                            add_edge(id(i, j, 1), id(ex, ey, 1), 1, 0);
                        ex = i + dx[2], ey = j + dy[2];
                        if (check(ex, ey))
                            add_edge(id(i, j, 2), id(ex, ey, 2), 1, 0);
                        ex = i + dx[3], ey = j + dy[3];
                        if (check(ex, ey))
                            add_edge(id(i, j, 2), id(ex, ey, 2), 1, 0);
                    }
                    else
                    {
                        int ex = 0, ey = 0;
                        add_edge(id(i, j, 0), id(i, j, 1), 2, 0);
                        add_edge(id(i, j, 0), id(i, j, 2), 2, 0);
                        ex = i + dx[0], ey = j + dy[0];
                        if (check(ex, ey))
                            add_edge(id(i, j, 1), id(ex, ey, 1), 1, 0);
                        ex = i + dx[1], ey = j + dy[1];
                        if (check(ex, ey))
                            add_edge(id(i, j, 1), id(ex, ey, 1), 1, 0);
                        ex = i + dx[2], ey = j + dy[2];
                        if (check(ex, ey))
                            add_edge(id(i, j, 2), id(ex, ey, 2), 1, 0);
                        ex = i + dx[3], ey = j + dy[3];
                        if (check(ex, ey))
                            add_edge(id(i, j, 2), id(ex, ey, 2), 1, 0);
                    }
                }
                else
                {
                    num1++;
                    add_edge(id(i, j, 0), t, 2, 0);
                    if (ch[i][j] == 'C')
                    {
                        add_edge(id(i, j, 1), id(i, j, 0), 1, 0);
                        add_edge(id(i, j, 2), id(i, j, 0), 1, 0);
                        add_edge(id(i, j, 1), id(i, j, 0), 1, 1);
                        add_edge(id(i, j, 2), id(i, j, 0), 1, 1);
                    }
                    else
                    {
                        add_edge(id(i, j, 1), id(i, j, 0), 2, 0);
                        add_edge(id(i, j, 2), id(i, j, 0), 2, 0);
                    }
                }
            }
        }
        mcmf();
        if (num != num1 || flow != num + num1)
            return -1;
        else
            return cost;
    }
}; // namespace CurvyonRails

// signed main()
// {
//     int tmp;
//     string s;
//     vector<string> vs;
//     scanf("%d", &tmp);
//     for (int i = 0; i < tmp; i++)
//         std::cin >> s, vs.push_back(s);
//     printf("%d\n", CurvyonRails::getmin(vs));
//     return 0;
// }
