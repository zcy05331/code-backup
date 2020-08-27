#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e4 + 10;
const int MaxM = 5e5 + 10;
const int inf = 2147483647;

struct edge
{
    int to, next, cap;
};

ll ans;
edge e[MaxM];
int head[MaxN], dep[MaxN], cur[MaxN];
int n, m, s = 20000, t = 20001, cnt = 1;

inline void add(int u, int v, int c)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].cap = c;
    head[u] = cnt;
}

inline void add_edge(int u, int v, int c) { add(u, v, c), add(v, u, 0); }

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

inline int bfs()
{
    memset(dep, 0, sizeof(dep));
    memcpy(cur, head, sizeof(head));
    std::queue<int> q;
    dep[s] = 1, q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to, c = e[i].cap;
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
    for(int i = cur[u]; i && (rest > 0); i = e[i].next)
    {
        cur[u] = i;
        int v = e[i].to, c = e[i].cap;
        if(dep[v] != dep[u] + 1 || !c)
            continue;
        int k = dinic(v, std::min(rest, c));
        if(!k) dep[v] = -1;
        else 
        {
            e[i].cap -= k;
            e[i ^ 1].cap += k;
            rest -= k;
        }
    }
    if(rest < 0) dep[u] = -1;
    return flow - rest;
}

inline void solve()
{
    ll now = 0;
    while(bfs())
        while((now = dinic(s, inf)))
            ans += now;
}

int main()
{   
    n = read(), m = read(), s = read(), t = read();
    for(int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), c = read();
        add_edge(u, v, c);
    }
    solve(), printf("%lld\n", ans);
    return 0;
}
