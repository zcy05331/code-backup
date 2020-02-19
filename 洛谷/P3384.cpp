#include <bits/stdc++.h>
#define mod(a, b) ((a + b) % p)

typedef long long ll;

const ll MaxN = 100000 + 10;

struct edge
{
    int next, to;
} e[MaxN << 1];

struct st_node
{
    long long sum;
    long long lazy;
    int l, r;
    int lson, rson;
} node[MaxN << 1];

struct tree_node
{
    int f;
    int dep;
    int size; 
    int hson;
    int top;
    int id;
} t[MaxN << 1];

long long root, n, m, r, p = 0x7f7f7f7f7f7f7f7f;
long long cnt;
long long a[MaxN], rank[MaxN], head[MaxN];

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(int u, int f, int dep)
{
    t[u].f = f;
    t[u].dep = dep;
    t[u].size = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == f)
            continue;
        dfs1(v, u, dep + 1);
        t[u].size += t[v].size;
        if (t[v].size > t[t[u].hson].size)
            t[u].hson = v;
    }
}

void dfs2(int u, int top)
{
    ++cnt;
    t[u].top = top;
    t[u].id = cnt;
    rank[cnt] = u;
    if (!t[u].hson)
        return;
    dfs2(t[u].hson, top);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v != t[u].hson && v != t[u].f)
            dfs2(v, v);
    }
}

void update(int x)
{
    node[x].sum = (node[node[x].lson].sum + node[node[x].rson].sum + node[x].lazy * (node[x].r - node[x].l + 1)) % p;
}

void build(int l, int r, int cur)
{
    if (l == r)
    {
        node[cur].l = node[cur].r = l;
        node[cur].sum = a[rank[l]];
        return;
    }
    int mid = (l + r) >> 1;
    node[cur].lson = cnt++;
    node[cur].rson = cnt++;
    build(l, mid, node[cur].lson);
    build(mid + 1, r, node[cur].rson);
    node[cur].l = node[node[cur].lson].l;
    node[cur].r = node[node[cur].rson].r;
    update(cur);
}

void update_tree(int l, int r, int c, int cur)
{
    if (l <= node[cur].l && r >= node[cur].r)
    {
        node[cur].sum = mod(node[cur].sum, c * (node[cur].r - node[cur].l + 1));
        node[cur].lazy = mod(node[cur].lazy, c);
        return;
    }
    int mid = (node[cur].l + node[cur].r) >> 1;
    if (l <= mid)
        update_tree(l, r, c, node[cur].lson);
    if (mid < r)
        update_tree(l, r, c, node[cur].rson);
    update(cur);
}

long long query_tree(int l, int r, int cur)
{
    if (l <= node[cur].l && r >= node[cur].r)
        return node[cur].sum;
    int tot = node[cur].lazy * (std::min(node[cur].r, r) - std::max(node[cur].l, l) + 1) % p;
    int mid = (node[cur].l + node[cur].r) >> 1;
    if (l <= mid)
        tot = mod(tot, query_tree(l, r, node[cur].lson));
    if (mid < r)
        tot = mod(tot, query_tree(l, r, node[cur].rson));
    return tot % p;
}

void update_chain(int x, int y, int c)
{
    int fx = t[x].top, fy = t[y].top;
    while (fx != fy)
    {
        if (t[fx].dep >= t[fy].dep)
        {
            update_tree(t[fx].id, t[x].id, c, root);
            x = t[fx].f;
            fx = t[x].top;
        }
        else
        {
            update_tree(t[fy].id, t[y].id, c, root);
            y = t[fy].f;
            fy = t[y].top;
        }
    }
    if (t[x].id <= t[y].id)
        update_tree(t[x].id, t[y].id, c, root);
    else
        update_tree(t[y].id, t[x].id, c, root);
}

long long query_chain(int x, int y)
{
    ll ans = 0;
    int fx = t[x].top, fy = t[y].top;
    while (fx != fy)
    {
        if (t[fx].dep >= t[fy].dep)
        {
            ans = mod(ans, query_tree(t[fx].id, t[x].id, root));
            x = t[fx].f;
            fx = t[x].top;
        }
        else
        {
            ans = mod(ans, query_tree(t[fy].id, t[y].id, root));
            y = t[fy].f;
            fy = t[y].top;
        }
    }
    if (t[x].id <= t[y].id)
        ans = mod(ans, query_tree(t[x].id, t[y].id, root));
    else
        ans = mod(ans, query_tree(t[y].id, t[x].id, root));
    return ans % p;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    cnt = 0;
    dfs1(1, 0, 1);
    dfs2(1, 1);
    cnt = 0;
    root = cnt++;
    build(1, n, root);
    for (int i = 1; i <= m; i++)
    {
        char op;
        ll x, y;
        std::cin >> op;
        if (op == 'P')
        {
            scanf("%lld%lld", &x, &y);
            update_chain(x, y, 1);
        }
        if (op == 'Q')
        {
            scanf("%lld%lld", &x, &y);
            printf("%lld\n", query_chain(x, y));
        }
    }
    return 0;
}