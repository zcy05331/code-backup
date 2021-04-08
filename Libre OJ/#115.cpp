#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int inf = 1e9 + 7;
const int MaxN = 2e4 + 10;

struct edge
{
    int next, to, flow;
} e[MaxN << 1];

std::vector<int> vec;
int n, m, s, t, cnt, ans, id[MaxN], ext[MaxN];
int head[MaxN], dep[MaxN], cur[MaxN], num[MaxN];

void add(int u, int v, int f)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].flow = f;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void add_edge(int u, int v, int f) { add(u, v, f), add(v, u, 0); }

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int bfs()
{
    std::queue<int> q;
    memset(dep, 0, sizeof(dep));
    memcpy(cur, head, sizeof(head));
    dep[s] = 1, q.push(s);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to, c = e[i].flow;
            if(dep[v] || !c) continue;
            dep[v] = dep[u] + 1, q.push(v);
        }
    }
    return dep[t];  
}

int dinic(int u, int flow)
{
    if(u == t) return flow;
    int rest = flow;
    for(int i = cur[u]; i && rest; i = e[i].next)
    {
        int v = e[i].to, c = e[i].flow, k;
        if(dep[v] == dep[u] + 1 && c)
        {   
            cur[u] = i, k = dinic(v, std::min(c, rest));
            if(!k) dep[v] = -1;
            else rest -= k, e[i].flow -= k, e[i ^ 1].flow += k;
        }
    }
    if(rest) dep[u] = -1;
    return flow - rest;
}

inline void solve()
{
    int now = 0;
    while (bfs())
        while ((now = dinic(s, inf)))
            ans -= now;
}

signed main()
{   
    n = read(), m = read(), cnt = 1, s = n + 1, t = n + 2;
    for(int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), l = read(), r = read(); num[i] = l;
        id[i] = cnt + 2, add_edge(u, v, r - l), ext[v] += l, ext[u] -= l;
    }
    for(int i = 1; i <= n; i++)
    {
        if(ext[i] > 0) 
            ans += ext[i], add_edge(s, i, ext[i]);
        else if(ext[i] < 0) add_edge(i, t, -ext[i]);
    }
    solve();
    if(ans) return 0 * printf("NO");
    else
    {
        puts("YES");
        for(int i = 1; i <= m; i++)
            printf("%d\n", e[id[i]].flow + num[i]);
    }
    return 0;
}
