#include <bits/stdc++.h>

#define tp int
#define ll long long
#define pmax(a, b) ((a) > (b) ? (a) : (b))
#define pmin(a, b) ((a) < (b) ? (a) : (b))
#define psum(a, b, mod) ((a + b) % mod)
#define openfile(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)

const int MaxN = 30010;

inline tp read()
{
    bool f = 0;
    tp x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = true;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
    return (!f) ? x : -x;
}

struct edge
{
    int to, next;
};

edge e[MaxN << 2];
std::stack<int> st;
int n, m, scc, tot, dfsnum, dfn[MaxN], low[MaxN], col[MaxN], ins[MaxN];
int cnt, head[MaxN], u[MaxN], v[MaxN], cir[MaxN], rev[MaxN], circle[205][205], ex[MaxN], ey[MaxN];

inline void init()
{
    cnt = tot = n = m = dfsnum = scc = 0;
    memset(head, 0, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(col, 0, sizeof(col));
    memset(rev, 0, sizeof(rev));
    memset(circle, 0, sizeof(circle));
}

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void tarjan(int u)
{
    dfn[u] = low[u] = ++dfsnum;
    st.push(u), ins[u] = 1;
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
        ++scc;
        do
        {
            v = st.top();
            st.pop();
            col[v] = scc;
            ins[v] = 0;
        } while (v != u);
    }
}

inline int check()
{
    for (int i = 1; i <= (m << 1); i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= m; i++)
        if (col[i] == col[i + m])
            return 0;
    return 1;
}

inline int solve()
{
    init();
    n = read(), m = read();

    for (int i = 1; i <= m; i++)
    {
        u[i] = read(), v[i] = read();
        if (u[i] > v[i])
            std::swap(u[i], v[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cir[i] = read();
        rev[cir[i]] = i;
    }
    if (m > 3 * n - 6)
        return 0 * printf("NO\n");
    for (int i = 2; i <= n; i++)
    {
        if (cir[i] < cir[i - 1])
            circle[cir[i]][cir[i - 1]] = 1;
        else
            circle[cir[i - 1]][cir[i]] = 1;
    }
    if (cir[n] < cir[1])
        circle[cir[n]][cir[1]] = 1;
    else
        circle[cir[1]][cir[n]] = 1;
    for (int i = 1; i <= m; i++)
    {
        if (circle[u[i]][v[i]])
            continue;
        ++tot, ex[tot] = u[i], ey[tot] = v[i];
    }
    m = tot;
    for (int i = 1; i <= m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            int eu[2] = {}, ev[2] = {};
            eu[0] = rev[ex[i]], ev[0] = rev[ey[i]];
            eu[1] = rev[ex[j]], ev[1] = rev[ey[j]];
            if (eu[0] > ev[0])
                std::swap(eu[0], ev[0]);
            if (eu[1] > ev[1])
                std::swap(eu[1], ev[1]);
            if ((eu[0] < eu[1] && ev[0] > eu[1] && ev[0] < ev[1]) || (ev[0] > ev[1] && eu[0] > eu[1] && eu[0] < ev[1]))
            {
                add_edge(i, j + m);
                add_edge(j + m, i);
                add_edge(i + m, j);
                add_edge(j, i + m);
            }
        }
    }
    printf(check() ? "YES\n" : "NO\n");
    return 0;
}

int main()
{
    int T = read();
    while (T--)
        solve();
    return 0;
}