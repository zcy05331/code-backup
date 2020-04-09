#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct edge
{
    int next, to;
};

struct node
{
    int l, r;
    int min, sec, tag;
};

edge e[MaxN << 1];
int n, m, cnt, dfscnt;
int head[MaxN], fa[MaxN], dep[MaxN], dfn[MaxN], pre[MaxN], size[MaxN];

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(int id)
    {
        int lc = id << 1, rc = id << 1 | 1;
        if(t[lc].min == t[rc].min)
        {
            t[id].min = t[lc].min;
            t[id].sec = std::min(t[lc].sec, t[rc].sec);
        }
        else if(t[lc].min < t[rc].min)
        {
            t[id].min = t[lc].min;
            t[id].sec = std::min(t[lc].sec, t[rc].min);
        }
        else 
        {
            t[id].min = t[rc].min;
            t[id].sec = std::min(t[lc].min, t[rc].sec);
        }
    }
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r, t[id].tag = -1;
        if(l == r) return (void) (t[id].min = 1, t[id].sec = 0x3f3f3f3f);
        int mid = (l + r) >> 1;
        build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r);
    }
    void pushtag(int id, int val)
    {
        if(t[id].min >= val) return;
        t[id].min = t[id].tag = val;
    }
    void pushdown(int id)
    {
        if(t[id].tag == -1) return;
        pushtag(id << 1, t[id].tag), pushtag(id << 1 | 1, t[id].tag);
        t[id].tag = -1;
    }
    void setval(int id, int l, int r, int val)
    {
        if(t[id].min >= val) return;
        if(t[id].l > r || l > t[id].r) return;
        if(l <= t[id].l && t[id].r <= r && t[id].sec > val)
            return pushtag(id, val);
        pushdown(id), setval(id << 1, l, r, val);
        setval(id << 1 | 1, l, r, val), pushup(id);
    }
    int query(int id, int pos)
    {
        if(t[id].l > pos || t[id].r < pos) 
            return 0x3f3f3f3f;
        if(t[id].l == t[id].r) return t[id].min;
        pushdown(id);
        return std::min(query(id << 1, pos), query(id << 1 | 1, pos));
    }
}T;

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1, ::fa[u] = fa;
    dfn[u] = ++dfscnt, pre[dfscnt] = u, size[u] = 1;
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(v == fa) continue;
        dfs(v, u), size[u] += size[v];
    }
}

char get()
{
    char ch = getchar();
    while(!isalpha(ch)) 
        ch = getchar();
    return ch;
}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{   
    n = read(), m = read();
    for(int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    dfs(1, 0), T.build(1, 1, n);
    while(m--)
    {
        char op = get();
        int u = read();
        if(op == 'Q')
            printf("%d\n", pre[T.query(1, dfn[u])]);
        else T.setval(1, dfn[u], dfn[u] + size[u] - 1, dfn[u]);
    }
    return 0;
}
