#include <bits/stdc++.h>
using namespace std;

const int inf = (1 << 30);
const int MaxN = 120010;

struct edge
{
    int to, next, val;
};


edge e[MaxN << 2];
int n, m, s, t, cnt = 1;
int head[MaxN], inq[MaxN], val[MaxN], h[MaxN], cnth[MaxN];

struct cmp
{
    inline bool operator()(int a, int b) const
    {
        return h[a] < h[b];
    }
};

std::priority_queue<int, std::vector<int>, cmp> q;

inline void add_edge(int u, int v, int val)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].val = val;
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

void bfs()
{
    memset(h, 0x3f, sizeof(h));
    h[t] = 0;
    std::queue<int> q;
    q.push(t);
    while (!q.empty())
    {
        register unsigned u = q.front();
        q.pop();
        inq[u] = 0;
        for (register unsigned i = head[u]; i; i = e[i].next)
        {
            register unsigned v = e[i].to;
            if (e[i ^ 1].val && h[v] > h[u] + 1)
            {
                h[v] = h[u] + 1;
                if (inq[v] == 0)
                {
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
}

inline void push(int u)
{
    for (register unsigned i = head[u]; i; i = e[i].next)
    {
        register unsigned v = e[i].to;
        if (e[i].val && h[v] + 1 == h[u])
        {
            register unsigned min = std::min(e[i].val, val[u]);
            e[i].val -= min;
            e[i ^ 1].val += min;
            val[u] -= min;
            val[v] += min;
            if (inq[v] == 0 && v != t && v != s)
            {
                q.push(v);
                inq[v] = 1;
            }
            if (val[u] == 0)
                break;
        }
    }
}

inline void relabel(int u)
{
    h[u] = inf;
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(e[i].val && h[v] + 1 < h[u])
        {
            h[u] = h[v] + 1;
        }
    }
}

int hlpp()
{
    bfs();
    if (h[s] == 0x3f3f3f3f)
        return 0;
    h[s] = n;
    for (register unsigned i = 1; i <= n; ++i)
        if (h[i] < 0x3f3f3f3f)
            cnth[h[i]]++;
    for (register unsigned i = head[s]; i; i = e[i].next)
    {
        register unsigned v = e[i].to;
        register unsigned min = e[i].val;
        if (min)
        {
            val[s] -= min, val[v] += min;
            e[i].val -= min, e[i ^ 1].val += min;
            if (v != t && inq[v] == 0 && v != s)
            {
                q.push(v);
                inq[v] = 1;
            }
        }
    }
    while (!q.empty())
    {
        register unsigned u = q.top();
        inq[u] = 0;
        q.pop();
        push(u);
        if (val[u])
        {
            cnth[h[u]]--;
            if (cnth[h[u]] == 0)
            {
                for (register unsigned i = 1; i <= n; ++i)
                {
                    if (i != s && i != t && h[i] > h[u] && h[i] < n + 1)
                        h[i] = n + 1;
                }
            }
            relabel(u);
            cnth[h[u]]++;
            q.push(u);
            inq[u] = 1;
        }
    }
    return val[t];
}

int main()
{
    n = read(), m = read(), s = read(), t = read();
    for (register unsigned i = 1; i <= m; ++i)
    {
        register unsigned u = read(), v = read(), val = read();
        add_edge(u, v, val);
        add_edge(v, u, 0);
    }
    printf("%d\n", hlpp());
    return 0;
}
