#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct edge
{
    int next, to;
};

struct query
{
    int a, b;
    char ha, hb;
};

query q[MaxN];
edge e[MaxN << 1];
std::stack<int> st;
char ch[MaxN], s[MaxN][2];
int n, m, d, cnt, dfscnt, flag;
int pos[10], used[10], head[MaxN], dfn[MaxN], low[MaxN], ins[MaxN], col[MaxN];

void init()
{
    cnt = 0, dfscnt = 0;
    memset(head, 0, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(col, 0, sizeof(col));
}

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline char get()
{
    char ch = getchar();
    while (!isalpha(ch))
        ch = getchar();
    return ch;
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
        ++cnt;
        do
        {
            v = st.top(), st.pop();
            ins[v] = 0, col[v] = cnt;
        } while (v != u);
    }
}

void check()
{
    init();
    for (int i = 1; i <= d; i++)
        ch[pos[i]] = ((used[i]) ? 'a' : 'b');
    for (int i = 1; i <= n; i++)
    {
        int tot = 0;
        if (ch[i] != 'a')
            s[i][tot++] = 'a';
        if (ch[i] != 'b')
            s[i][tot++] = 'b';
        if (ch[i] != 'c')
            s[i][tot++] = 'c';
    }
    for (int i = 1; i <= m; i++)
    {
        if (q[i].ha == ch[q[i].a])
            continue;
        int a1 = ((q[i].ha == s[q[i].a][0]) ? 0 : 1);
        if (q[i].hb == ch[q[i].b])
        {
            add_edge(q[i].a + a1 * n, q[i].a + (a1 ^ 1) * n);
            continue;
        }
        int b1((q[i].hb == s[q[i].b][0]) ? 0 : 1);
        add_edge(q[i].a + a1 * n, q[i].b + b1 * n);
        add_edge(q[i].b + (b1 ^ 1) * n, q[i].a + (a1 ^ 1) * n);
    }
    cnt = 0;
    for (int i = 1; i <= 2 * n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= n; i++)
        if (col[i] == col[i + n])
            return;
    flag = 1;
    for (int i = 1; i <= n; i++)
        printf("%c", toupper(s[i][col[i] > col[i + n]]));
}

void dfs(int dep)
{
    if (flag)
        return;
    if (dep > d)
        return (void)check();
    used[dep] = 1, dfs(dep + 1);
    used[dep] = 0, dfs(dep + 1);
}

int main()
{
    n = read(), d = read(), scanf("%s", ch + 1);
    for (int i = 1; i <= n; i++)
        if (ch[i] == 'x')
            pos[++cnt] = i;
    cnt = 0, m = read();
    for (int i = 1; i <= m; i++)
        q[i].a = read(), q[i].ha = tolower(get()), q[i].b = read(), q[i].hb = tolower(get());
    if (d == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            int tot = 0;
            if (ch[i] != 'a')
                s[i][tot++] = 'a';
            if (ch[i] != 'b')
                s[i][tot++] = 'b';
            if (ch[i] != 'c')
                s[i][tot++] = 'c';
        }
        for (int i = 1; i <= m; i++)
        {
            if (q[i].ha == ch[q[i].a])
                continue;
            int a1 = ((q[i].ha == s[q[i].a][0]) ? 0 : 1);
            if (q[i].hb == ch[q[i].b])
            {
                add_edge(q[i].a + a1 * n, q[i].a + (a1 ^ 1) * n);
                continue;
            }
            int b1((q[i].hb == s[q[i].b][0]) ? 0 : 1);
            add_edge(q[i].a + a1 * n, q[i].b + b1 * n);
            add_edge(q[i].b + (b1 ^ 1) * n, q[i].a + (a1 ^ 1) * n);
        }
        cnt = 0;
        for (int i = 1; i <= 2 * n; i++)
            if (!dfn[i])
                tarjan(i);
        for (int i = 1; i <= n; i++)
            if (col[i] == col[i + n])
                return 0 * printf("-1");
        for (int i = 1; i <= n; i++)
            printf("%c", toupper(s[i][col[i] > col[i + n]]));
    }
    else
    {
        dfs(1);
        if (!flag)
            return 0 * printf("-1");
    }
    return 0;
}
