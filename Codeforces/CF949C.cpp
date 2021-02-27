#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct edge
{
    int next, to;
} e[MaxN << 1];

std::stack<int> st;
int n, m, k, cnt, dfscnt, val[MaxN], d[MaxN], siz[MaxN], u[MaxN];
int head[MaxN], dfn[MaxN], low[MaxN], col[MaxN], ins[MaxN], v[MaxN];

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
    st.push(u), ins[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!dfn[v])
            tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (ins[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        int v = ++cnt;
        do
        {
            v = st.top(), ins[v] = 0;
            st.pop(), col[v] = cnt, ++siz[cnt];
        } while (v != u);
    }
}

signed main()
{
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++)
        val[i] = read();
    for (int i = 1; i <= m; i++)
    {
        u[i] = read(), v[i] = read();
        if ((val[u[i]] + 1) % k == val[v[i]])
            add_edge(u[i], v[i]);
        if ((val[v[i]] + 1) % k == val[u[i]])
            add_edge(v[i], u[i]);
    }
    cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= m; i++)
    {
        if ((val[u[i]] + 1) % k == val[v[i]])
            if (col[u[i]] != col[v[i]]) d[col[u[i]]]++;
        if ((val[v[i]] + 1) % k == val[u[i]])
            if (col[u[i]] != col[v[i]]) d[col[v[i]]]++;
    }
    int ans = n, pos = 0;
    for (int i = 1; i <= cnt; i++)
        if (d[i] == 0 && siz[i] < ans)
            ans = siz[i], pos = i;
    if (ans < n)
    {
        printf("%d\n", ans);
        for (int i = 1; i <= n; i++)
            if (col[i] == pos)
                printf("%d ", i);
    }
    else
    {
        printf("%d\n", ans);
        for (int i = 1; i <= n; i++)
            printf("%d ", i);
    }
    return 0;
}
