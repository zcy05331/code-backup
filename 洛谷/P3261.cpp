#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct edge
{
    int next, to;
};

struct node
{
    int ch[2];
    int dep, val;
};

edge e[MaxN];
node t[MaxN];
int n, m, cnt;
int head[MaxN], f[MaxN], h[MaxN];

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int merge(int x, int y)
{
    if(!x || !y) return x + y;
    if(t[x].val < t[y].val) std::swap(x, y);
    t[x].ch[1] = merge(y, t[x].ch[1]);
    if(t[t[x].ch[0]].dep < t[t[x].ch[1]].dep)
        std::swap(t[x].ch[0], t[x].ch[1]);
    t[x].dep = t[t[x].ch[1]].dep + 1;
    return x;
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
    n = read(), m = read();
    for(int i = 1; i <= n; i++) 
        h[i] = read();
    for(int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(u, v);
    }
    return 0;
}
