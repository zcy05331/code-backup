#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN];
int n, k, cnt;
std::priority_queue<int> q;
int head[MaxN], dep[MaxN], size[MaxN];

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1, size[u] = 1;
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(v == fa) continue;
        dfs(v, u), size[u] += size[v];
    }
    q.push(dep[u] - size[u] + 1);
}

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

int main()
{   
    ll ans = 0;
    n = read(), k = read();
    for(int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    dfs(1, 0);
    for(int i = 1; i <= k; i++)
        ans += q.top(), q.pop();
    printf("%lld\n", ans - k);
    return 0;
}
