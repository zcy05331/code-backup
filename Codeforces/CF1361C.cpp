#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e6 + 10;

struct edge
{
    int next, to;
} e[MaxN];

std::vector<int> st;
int n, m, t, cnt, a[MaxN], b[MaxN];
int head[MaxN], vis[MaxN], ans[MaxN], d[MaxN];

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u)
{
    for (int &i = head[u]; i; i = e[i].next)
    {
        if (!vis[i])
        {
            vis[i] = vis[i ^ 1] = 1;
            int v = e[i].to;
            dfs(v), ans[++t] = v;
        }
    }
}
int check(int mid)
{
    int s = (1 << mid) - 1, flag = 0;
    for (int i = 0; i <= s; i++)
        d[i] = 0;
    for (int i = 1; i <= n; i++)
        d[a[i] & s]++, d[b[i] & s]++;
    for (int i = 0; i <= s; i++)
        if (d[i] & 1) return 0;
    for (int i = 1; i <= cnt; i++)
        vis[i] = 0;
    cnt = 1;
    for (int i = 1; i <= s + n + 1; i++)
        head[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        add_edge(i, (a[i] & s) + n + 1);
        add_edge((a[i] & s) + n + 1, i);
        add_edge(i, (b[i] & s) + n + 1);
        add_edge((b[i] & s) + n + 1, i);
    }
    t = 0, st.clear(), dfs(1);
    for (int i = 1; i <= ::t; i++)
        flag += (ans[i] <= n);
    if (flag != n) return 0;
    printf("%d\n", mid);
    for (int i = 1; i <= ::t; i++)
    {
        if (ans[i] <= n)
        {
            int id = ans[i], t = (ans[i + 1] - n - 1);
            if ((a[id] & s) == t)
                printf("%d %d ", id * 2, id * 2 - 1);
            else
                printf("%d %d ", id * 2 - 1, id * 2);
        }
    }
    return 1;
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

signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), b[i] = read();
    for (int x = 20; x >= 1; x--)
    {
        if (check(x))
            return 0;
    }
    printf("%d\n", 0);
    for (int i = 1; i <= 2 * n; i++)
        printf("%d ", i);
    return 0;
}
