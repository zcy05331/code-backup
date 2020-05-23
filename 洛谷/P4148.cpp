#include <bits/stdc++.h>

#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;
const double delta = 0.715;

struct node
{
    int x, y, val;
};

int n, xl, xr, yl, yr, cur, root;

struct KDTree
{
    node t[MaxN];
    int cnt, L[MaxN], R[MaxN], U[MaxN], D[MaxN];
    int g[MaxN], d[MaxN], lc[MaxN], rc[MaxN], sum[MaxN], size[MaxN];
    void dfs(int x)
    {
        if(!x) return;
        dfs(lc[x]);
        g[++cnt] = x;
        dfs(rc[x]);
    }
    void maintain(int x)
    {
        size[x] = size[lc[x]] + size[rc[x]] + 1;
        sum[x] = sum[lc[x]] + sum[rc[x]] + t[x].val;
        L[x] = R[x] = t[x].x, U[x] = D[x] = t[x].y;
        if(lc[x])
        {
            L[x] = std::min(L[x], L[lc[x]]), R[x] = std::max(R[x], R[lc[x]]);
            U[x] = std::min(U[x], U[lc[x]]), D[x] = std::max(D[x], D[lc[x]]);
        }
        if(rc[x])
        {
            L[x] = std::min(L[x], L[rc[x]]), R[x] = std::max(R[x], R[rc[x]]);
            U[x] = std::min(U[x], U[rc[x]]), D[x] = std::max(D[x], D[rc[x]]);
        }
    }
    int build(int l, int r, int k)
    {
        if(l > r) return 0;
        int mid = (l + r) >> 1;
        if(k)  std::nth_element(g + l, g + mid, g + r + 1, [&](int a, int b) { return t[a].x < t[b].x; }), d[g[mid]] = 1;
        else std::nth_element(g + l, g + mid, g + r + 1, [&](int a, int b) { return t[a].y < t[b].y; }), d[g[mid]] = 2;
        lc[g[mid]] = build(l, mid - 1, k ^ 1), rc[g[mid]] = build(mid + 1, r, k ^ 1),  maintain(g[mid]);
        return g[mid];
    }
    void restore(int &x)
    {
        cnt = 0, dfs(x);
        x = build(1, cnt, 0);
    }
    bool bad(int x) { return (delta * size[x]) <= (double) std::max(size[lc[x]], size[rc[x]]); }
    void insert(int &x, int u)
    {
        if(!x) 
            return (void) (x = u, maintain(x));
        if(d[x] == 1)
            ((t[u].x <= t[x].x) ? insert(lc[x], u) : insert(rc[x], u));
        else
            ((t[u].y <= t[x].y) ? insert(lc[x], u) : insert(rc[x], u));
        maintain(x);
        if(bad(x)) restore(x);
    }
    int query(int x) 
    {
        if(!x || L[x] > xr || xl > R[x] || U[x] > yr || D[x] < yl) return 0;
        if(xl <= L[x] && R[x] <= xr && yl <= U[x] && D[x] <= yr) return sum[x];
        int ret = 0, X = t[x].x, Y = t[x].y;
        if(xl <= X && X <= xr && yl <= Y && Y <= yr) ret += t[x].val;
        return query(lc[x]) + query(rc[x]) + ret;
    }
}T;

int main()
{   
    int op, ans = 0;
    scanf("%d", &n);
    while(scanf("%d", &op) != EOF)
    {
        if(op == 1)
        {
            cur++, scanf("%d%d%d", &T.t[cur].x, &T.t[cur].y, &T.t[cur].val);
            T.t[cur].x ^= ans, T.t[cur].y ^= ans, T.t[cur].val ^= ans, T.insert(root, cur);
        }
        else if(op == 2)
        {
            scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
            xl ^= ans, yl ^= ans, xr ^= ans, yr ^= ans;
            ans = T.query(root), printf("%d\n", ans);
        }
        else break;
    }
    return 0;
}
