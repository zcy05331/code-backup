#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN];
std::stack<int> st;
int n, m, p, cnt, dfscnt, colcnt;
int dfn[MaxN], low[MaxN], ins[MaxN], col[MaxN];
int a[MaxN], u[MaxN], v[MaxN], head[MaxN], val[MaxN], ind[MaxN];

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

void tarjan(int u)
{
    dfn[u] = low[u] = ++dfscnt;
    ins[u] = 1, st.push(u);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!dfn[v])
            tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (ins[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        int v;
        ++colcnt;
        do
        {
            v = st.top(), st.pop();
            ins[v] = 0, col[v] = colcnt;
        } while (v != u);
    }
}

int main()
{
    n = read(), p = read();
    memset(a, -1, sizeof(a));
    memset(val, 0x3f, sizeof(val));
    for (int i = 1; i <= p; i++)
    {
        int x = read(), y = read();
        a[x] = y;
    }
    m = read();
    for (int i = 1; i <= m; i++)
    {
        u[i] = read(), v[i] = read();
        add_edge(u[i], v[i]);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= n; i++)
        if (~a[i])
            val[col[i]] = std::min(val[col[i]], a[i]);
    for (int i = 1; i <= m; i++)
    {
        if (col[u[i]] == col[v[i]])
            continue;
        ++ind[col[v[i]]];
    }
    for (int i = 1; i <= n; i++)
    {
        if (!ind[col[i]] && val[col[i]] == 0x3f3f3f3f)
        {
            printf("NO\n%d", i);
            return 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= colcnt; i++)
        if (ind[i] == 0)
            ans += val[i];
    printf("YES\n%d\n", ans);
    return 0;
}
