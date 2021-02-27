#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)

const int inf = 2e9;
const int MaxN = 2e5 + 10;

struct edge
{
    int next, to;
} e[MaxN << 1];

struct heap
{
    std::priority_queue<int> A, B; // heap=A-B
    void insert(int x) { A.push(x); }
    void erase(int x) { B.push(x); }
    int top()
    {
        while (!B.empty() && A.top() == B.top())
            A.pop(), B.pop();
        return A.top();
    }
    void pop()
    {
        while (!B.empty() && A.top() == B.top())
            A.pop(), B.pop();
        A.pop();
    }
    int top2()
    {
        int t = top(), ret;
        pop(), ret = top(), A.push(t);
        return ret;
    }
    int size() { return A.size() - B.size(); }
} dis[MaxN], ch[MaxN], ans;

int n, m, rt, cnt, sum, col[MaxN], max[MaxN], dep[MaxN];
int head[MaxN], fa[MaxN], vis[MaxN], siz[MaxN], d[MaxN][21];

struct LCA
{
    int dep[MaxN], fa[MaxN][21];
    void dfs(int u, int f)
    {
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (v == f)
                continue;
            dep[v] = dep[u] + 1;
            fa[v][0] = u, dfs(v, u);
        }
    }
    void init()
    {
        dfs(1, -1);
        for (int j = 1; j <= 20; j++)
            for (int i = 1; i <= n; i++)
                fa[i][j] = fa[fa[i][j - 1]][j - 1];
    }
    int query(int u, int v)
    {
        if (dep[u] < dep[v])
            std::swap(u, v);
        for (int i = 20; ~i; i--)
            if (dep[fa[u][i]] >= dep[v])
                u = fa[u][i];
        if (u == v)
            return u;
        for (int i = 20; ~i; i--)
            if (fa[u][i] != fa[v][i])
                u = fa[u][i], v = fa[v][i];
        return fa[u][0];
    }
    int dist(int u, int v) { return dep[u] + dep[v] - 2 * dep[query(u, v)]; }
} LCA;

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u, int fa, int dep, heap &y)
{
    y.insert(dep);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa || vis[v])
            continue;
        dfs(v, u, dep + 1, y);
    }
}

void getroot(int u, int fa)
{
    siz[u] = 1, max[u] = 0;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa || vis[v])
            continue;
        getroot(v, u), siz[u] += siz[v];
        max[u] = std::max(max[u], siz[v]);
    }
    max[u] = std::max(max[u], sum - siz[u]);
    if (max[u] < max[rt]) rt = u;
}

void getfa(int u)
{
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (vis[v]) continue;
        rt = 0, max[rt] = inf, sum = siz[v];
        getroot(v, -1), getroot(rt, -1), fa[rt] = u;
        dfs(v, -1, 1, dis[rt]), ch[u].insert(dis[rt].top());
        dep[rt] = dep[u] + 1, getfa(rt);
    }
    ch[u].insert(0);
    if (ch[u].size() >= 2)
        ans.insert(ch[u].top() + ch[u].top2());
    else if (ch[u].size())
        ans.insert(ch[u].top());
}

char get()
{
    char ch = getchar();
    while (!isupper(ch))
        ch = getchar();
    return ch;
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

signed main()
{
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    LCA.init(), rt = 0, max[rt] = inf, sum = n;
    getroot(1, -1), getroot(rt, -1), getfa(rt);
    for (int i = 1; i <= n; i++)
        for (int j = i; j; j = fa[j])
            d[i][dep[i] - dep[j]] = LCA.dist(i, j);
    m = read();
    while (m--)
    {
        char op = get();
        if (op == 'G')
        {
            if (ans.size())
                printf("%d\n", ans.top());
            else
                printf("-1\n");
        }
        else
        {
            int x = read();
            if (!col[x])
            {
                if (ch[x].size() >= 2)
                    ans.erase(ch[x].top() + ch[x].top2());
                ch[x].erase(0);
                if (ch[x].size() >= 2)
                    ans.insert(ch[x].top() + ch[x].top2());
                for (int y = x; fa[y]; y = fa[y])
                {
                    if (ch[fa[y]].size() >= 2)
                        ans.erase(ch[fa[y]].top() + ch[fa[y]].top2());
                    ch[fa[y]].erase(dis[y].top());
                    dis[y].erase(d[x][dep[x] - dep[fa[y]]]);
                    if (dis[y].size())
                        ch[fa[y]].insert(dis[y].top());
                    if (ch[fa[y]].size() >= 2)
                        ans.insert(ch[fa[y]].top() + ch[fa[y]].top2());
                }
            }
            else
            {
                if (ch[x].size() >= 2)
                    ans.erase(ch[x].top() + ch[x].top2());
                ch[x].insert(0);
                if (ch[x].size() >= 2)
                    ans.insert(ch[x].top() + ch[x].top2());
                for (int y = x; fa[y]; y = fa[y])
                {
                    if (ch[fa[y]].size() >= 2)
                        ans.erase(ch[fa[y]].top() + ch[fa[y]].top2());
                    if (dis[y].size())
                        ch[fa[y]].erase(dis[y].top());
                    dis[y].insert(d[x][dep[x] - dep[fa[y]]]);
                    ch[fa[y]].insert(dis[y].top());
                    if (ch[fa[y]].size() >= 2)
                        ans.insert(ch[fa[y]].top() + ch[fa[y]].top2());
                }
            }
            col[x] ^= 1;
        }
    }
    return 0;
}
