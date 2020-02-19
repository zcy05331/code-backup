#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e3 + 10;
const int MaxM = 5e4 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN];
std::stack<int> st;
int n, m, cnt, dfsnum;
int head[MaxN], col[MaxN], vis[MaxN], dfn[MaxN], low[MaxN];

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++dfsnum;
    vis[u] = 1, st.push(u);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!dfn[v])
            tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (vis[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        int v;
        ++cnt;
        do
        {
            v = st.top(), st.pop();
            vis[v] = 0, col[v] = cnt;
        } while (v != u);
    }
}

inline void init()
{
    cnt = dfsnum = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(col, 0, sizeof(col));
    memset(head, 0, sizeof(head));
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

int getnum(std::string s)
{
    int x = 0, len = s.length();
    for (int i = 1; i < len; i++)
        x = (x << 1) + (x << 3) + (s[i] ^ 48);
    return x;
}

int main()
{
    int T = read();
    while (T--)
    {
        init();
        n = read(), m = read();
        for (int i = 1; i <= m; i++)
        {
            std::string s, t;
            char X, Y;
            int a, b, x, y;
            std::cin >> s >> t;
            X = s[0], Y = t[0], a = getnum(s), b = getnum(t);
            x = ((X == 'm') ? 1 : 0);
            y = ((Y == 'm') ? 1 : 0);
            add_edge(a + x * n, b + (y ^ 1) * n);
            add_edge(b + y * n, a + (x ^ 1) * n);
        }
        cnt = 0;
        for (int i = 1; i <= 2 * n; i++)
            if (!dfn[i])
                tarjan(i);
        int flag = 1;
        for (int i = 1; i <= n; i++)
            if (col[i] == col[i + n])
                flag = 0;
        puts(flag ? "GOOD" : "BAD");
    }
    return 0;
}
