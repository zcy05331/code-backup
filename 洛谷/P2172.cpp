#include <bits/stdc++.h>

#define R register
#define ll long long
#define id(i, j) (((i)-1) * m + j)
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)
#define check(i, j) (i > 0 && i <= n && j > 0 && j <= m)

const int Max = 5e2 + 10;
const int MaxN = 5e5 + 10;
const int inf = 998244353;

int dx[8], dy[8];

struct edge
{
    int next, to, flow;
};

edge e[MaxN << 1];
int n, m, r, c, siz, cnt = 1, s = 5001, t = 5002;
int head[MaxN], a[Max][Max], cur[MaxN], dep[MaxN];

void add(int u, int v, int f)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].flow = f;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void add_edge(int u, int v, int f) { add(u, v, f), add(v, u, 0); }

int bfs()
{
    std::queue<int> q;
    memset(dep, 0, sizeof(dep));
    memcpy(cur, head, sizeof(head));
    dep[s] = 1, q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to, c = e[i].flow;
            if (dep[v] || !c) continue;
            dep[v] = dep[u] + 1, q.push(v);
        }
    }
    return dep[t];
}

int dinic(int u, int flow)
{
    if (u == t) return flow;
    int rest = flow;
    for (int i = cur[u]; i; i = e[i].next)
    {
        int v = e[i].to, c = e[i].flow, k;
        if (dep[v] != dep[u] + 1 || !c) continue;
        cur[u] = i, k = dinic(v, std::min(c, rest));
        if(!k) dep[v] = -1;
        else e[i].flow -= k, e[i ^ 1].flow += k, rest -= k;
    }
    if (rest > 0) dep[u] = -1;
    return flow - rest;
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

int solve()
{
    int now = 0, ans = 0;
    while (bfs())
        while ((now = dinic(s, inf)))
            ans += now;
    return ans;
}

signed main()
{
    int sum = 0;
    n = read(), m = read();
    r = read(), c = read(), siz = n * m;
    for (int i = 1; i <= n; i++)
    {
        char ch[MaxN];
        scanf("%s", ch + 1);
        for (int j = 1; j <= m; j++)
            a[i][j] = (ch[j] == '.'), sum += a[i][j];
    }
    dx[0] = c, dx[1] = c, dx[2] = r, dx[3] = r;
    dy[0] = r, dy[1] = -r, dy[2] = c, dy[3] = -c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(!a[i][j]) continue;
            add_edge(s, id(i, j), 1), add_edge(id(i, j) + siz, t, 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int ex = i + dx[k], ey = j + dy[k];
                if (!check(ex, ey) || !a[ex][ey])
                    continue;
                add_edge(id(i, j), id(ex, ey) + siz, 1);
            }
        }
    }
    printf("%d\n", sum - solve());
    return 0;
}
