#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct edge
{
    int next, to, dis;
};

edge e[MaxN];
int n, m, cnt;
int head[MaxN], val[MaxN];

void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u, int fa)
{
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(v == fa) continue;
        val[v] = val[u] ^ e[i].dis, dfs(v, u);
    }
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
    n = read();
    for(int i = 1; i < n; i++)
    {
        int u = read(), v = read(), d = read();
        add_edge(u, v, d), add_edge(v, u, d);
    }
    dfs(1, 0), m = read();
    while(m--)
    {
        int u = read(), v = read();
        printf("%d\n", val[u] ^ val[v]);
    }
    return 0;
}
