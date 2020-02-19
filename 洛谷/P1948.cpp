#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e5 + 10, MaxM = 2e5 + 10;

struct edge
{
    int to, next, dis;
};

struct node
{
    int pos, dis;
};

edge e[MaxN];
int n, m, k, cnt;
int head[MaxN], dis[MaxN];

inline void add_edge(int u, int v, int d)
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

inline int check(int mid)
{
    memset(dis, -1, sizeof(dis));
    std::deque<node> q;
    q.push_back((node){1, 0});
    while (!q.empty())
    {
        node tmp = q.front();
        int u = tmp.pos, d = tmp.dis;
        q.pop_front();
        if (dis[u] == -1 || (dis[u] != -1 && dis[u] > d))
            dis[u] = d;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to, c = 0;
            if (~dis[v])
                continue;
            if (e[i].dis > mid)
                c = 1;
            if (c)
                q.push_back((node){v, d + 1});
            else
                q.push_front((node){v, d});
        }
    }
    if (dis[n] == -1 || dis[n] > k)
        return 0;
    return 1;
}

int main()
{
    int l = 0, r = 1, tmp;
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), d = read();
        add_edge(u, v, d);
        add_edge(v, u, d);
        r = cmax(r, d);
    }
    ++r, tmp = r;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", (r == tmp) ? -1 : l);
    return 0;
}
