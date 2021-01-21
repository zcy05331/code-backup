#include <bits/stdc++.h>

#define R register
#define ll long long

const int MaxN = 1e6 + 10;

struct edge
{
    int next, to;
} e[MaxN << 1];

std::stack<int> st;
int n, m, cnt, ccnt, dfscnt, a[MaxN], b[MaxN], num[MaxN];
int head[MaxN], col[MaxN], dfn[MaxN], low[MaxN], vis[MaxN];

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while ('0' <= ch && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

inline void tarjan(int u)
{
    dfn[u] = low[u] = ++dfscnt, vis[u] = 1, st.push(u);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!dfn[v])
            tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (vis[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        int v;
        ++ccnt;
        do
        {
            v = st.top(), vis[v] = 0;
            col[v] = ccnt, st.pop();
        } while (v != u);
    }
}

void init()
{
    dfscnt = cnt = ccnt = 0;
    memset(head, 0, 4 * (n + 10));
    memset(vis, 0, 4 * (n + 10));
    memset(col, 0, 4 * (n + 10));
    memset(dfn, 0, 4 * (n + 10));
    memset(low, 0, 4 * (n + 10));
}

int main()
{
    int T = read();
    while (T--)
    {
        int flag = 0;
        n = read(), m = read(), init();
        for (int i = 1; i <= m; i++)
        {
            a[i] = read(), b[i] = read();
            if (a[i] != b[i]) add_edge(a[i], b[i]);
        }
        for (int i = 1; i <= n; i++)
            if (!dfn[i]) tarjan(i);
        if (ccnt == 1)
            puts("No");
        else
        {
            int cnt1 = 0;
            for (int i = 1; i <= n; i++)
                if (col[i] == 1) ++cnt1;
            puts("Yes"), printf("%d %d\n", cnt1, n - cnt1);
            for (int i = 1; i <= n; i++)
                if (col[i] == 1) printf("%d ", i);
            puts("");
            for (int i = 1; i <= n; i++)
                if (col[i] > 1) printf("%d ", i);
            puts("");
        }
    }
    return 0;
}