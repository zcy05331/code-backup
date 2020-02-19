#include <bits/stdc++.h>
const int Max = 1000010;

struct edge
{
    int next, to;
}e[Max << 2];
int head[Max], cnt;
int add_edge(int u, int v)
{
    cnt++;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = v;
}
int f[Max];
int getf(int x)
{
    if(x != f[x])f[x] = getf(f[x]);
    return f[x];
}
int merge(int x, int y)
{
    f[getf(x)] = getf(y);
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    
    return 0;
}