#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

struct edge
{
    int next, to;
};

struct node
{
    int u, v, c, t;
};


node t[MaxN];
edge e[MaxN];
int n, m, cnt;
std::vector<int> p[MaxN];
int col[MaxN], head[MaxN], dfn[MaxN], low[MaxN];

int cmp(node a, node b) { return a.t < b.t; }

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int main()
{   

    return 0;
}
