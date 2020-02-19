#include <bits/stdc++.h>

#define R register
#define ll long long
#define lowbit(x) ((x) & (-(x)))
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN];
int n, cnt, a[MaxN], b[MaxN], c[MaxN], ans[MaxN], head[MaxN];

int query(int pos)
{
    int ret = 0;
    while (pos)
        ret += c[pos], pos -= lowbit(pos);
    return ret;
}

void add(int pos, int val)
{
    while (pos <= n)
        c[pos] += val, pos += lowbit(pos);
}

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
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

void dfs(int u)
{
    ans[u] = -(query(n) - query(a[u]));
    for (int i = head[u]; i; i = e[i].next)
        dfs(e[i].to);
    ans[u] += (query(n) - query(a[u])), add(a[u], 1);
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = b[i] = read();
    std::sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + n + 1, a[i]) - b;
    for (int i = 2; i <= n; i++)
        add_edge(read(), i);
    dfs(1);
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}
