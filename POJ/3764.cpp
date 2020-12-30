#include <algorithm>
#include <cstdio>
#include <cstring>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

struct edge
{
    int next, to, dis;
};

edge e[MaxN << 1];
int n, m, cnt, ans, tot = 1;
int head[MaxN], dis[MaxN], ch[MaxN << 5][2];

void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u, int fa)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dis[v] = dis[u] ^ e[i].dis, dfs(v, u);
    }
}

void insert(int x)
{
    int now = 1;
    for (int i = 30; ~i; i--)
    {
        int c = !!(x & (1 << i));
        if (!ch[now][c]) ch[now][c] = ++tot;
        now = ch[now][c];
    }
}

int query(int x)
{
    int now = 1, ans = 0;
    for (int i = 30; ~i; i--)
    {
        int c = !(x & (1 << i));
        if (ch[now][c])
            now = ch[now][c], ans |= (1 << i);
        else
            now = ch[now][!c];
    }
    return ans;
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

void init()
{
    cnt = 0, ans = 0;
    memset(dis, 0, 4 * (n + 10));
    memset(head, 0, 4 * (n + 10));
    for (int i = 0; i <= tot; i++)
        ch[i][0] = ch[i][1] = 0;
    tot = 1;
}

signed main()
{
    // freopen("xor.in", "r", stdin);
    // freopen("xor.out", "w", stdout);
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i < n; i++)
        {
            int u = read(), v = read(), d = read();
            add_edge(u + 1, v + 1, d), add_edge(v + 1, u + 1, d);
        }
        dfs(1, 0);
        for (int i = 1; i <= n; i++)
            insert(dis[i]);
        for (int i = 1; i <= n; i++)
            ans = std::max(ans, query(dis[i]));
        printf("%d\n", ans), init();
    }
    return 0;
}
