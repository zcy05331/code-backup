#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

using std::queue;

const int MaxN = 2e4 + 10;
const int MaxM = 2e5 + 10;
const int inf = (1 << 30);

struct edge
{
    int to, next, cap;
};

edge e[MaxM << 1];
int n, s = 2000, t = 2001, ans, cnt = 1;
int head[MaxN], dep[MaxN], a[MaxN], b[MaxN];

inline void add_edge(int u, int v, int cap)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].cap = cap;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

inline bool bfs()
{
    memset(dep, 0, sizeof(dep));
    std::queue<int> q;
    q.push(s);
    dep[s] = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to, c = e[i].cap;
            if (dep[v] || !c)
                continue;
            q.push(v);
            dep[v] = dep[u] + 1;
            if (v == t)
                return 1;
        }
    }
    return 0;
}

int dinic(int u, int flow)
{
    if (u == t)
        return flow;
    int rest = flow;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to, c = e[i].cap;
        if (dep[v] != dep[u] + 1 || !c)
            continue;
        int k = dinic(v, cmin(rest, c));
        if (!k)
            dep[v] = 0;
        else
        {
            e[i].cap -= k;
            e[i ^ 1].cap += k;
            rest -= k;
        }
    }
    return flow - rest;
}

int main()
{
    int T = read();
    while (T--)
    {
        cnt = 1, ans = 0;
        memset(head, 0, sizeof(head));
        memset(e, 0, sizeof(e));
        n = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            if (a[i] == 1)
                add_edge(i + n, t, 1), add_edge(t, i + n, 0);
        }
        int tot = 0;
        for (int i = 1; i <= n; i++)
        {
            b[i] = read();
            if ((a[i] == 1 && b[i] == 0) || (a[i] == 0))
                add_edge(s, i, 1), add_edge(i, s, 0), ++tot;
            // if((a[i] == 1 && b[i] == 1))
            //     add_edge(i, i + n, 1), add_edge(i + n, i, 0);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int tmp = read();
                if (tmp == 1 || (i == j))
                    add_edge(i, j + n, 1), add_edge(j + n, i, 0);
            }
        }
        int now = 0;
        while (bfs())
            while ((now = dinic(s, inf)))
                ans += now;
        if (ans >= tot)
            printf("^_^\n");
        else
            printf("T_T\n");
    }

    return 0;
}
