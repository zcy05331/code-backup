#include <bits/stdc++.h>

#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 4e6 + 10;
const double delta = 0.7;

struct node
{
    int x, y, val;
};

int n, xl, xr, yl, yr, cur, root;

struct KDTree
{
    node t[MaxN];
    int cnt, lc[MaxN], rc[MaxN], sum[MaxN], size[MaxN];
    int g[MaxN], d[MaxN], L[MaxN], R[MaxN], U[MaxN], D[MaxN];
    void dfs(int x)
    {
        if (!x) return;
        dfs(lc[x]), g[++cnt] = x, dfs(rc[x]);
    }
    inline void pushup(int x)
    {
        size[x] = size[lc[x]] + size[rc[x]] + 1;
        sum[x] = sum[lc[x]] + sum[rc[x]] + t[x].val;
        L[x] = R[x] = t[x].x, U[x] = D[x] = t[x].y;
        if (lc[x])
        {
            L[x] = std::min(L[x], L[lc[x]]), R[x] = std::max(R[x], R[lc[x]]);
            U[x] = std::min(U[x], U[lc[x]]), D[x] = std::max(D[x], D[lc[x]]);
        }
        if (rc[x])
        {
            L[x] = std::min(L[x], L[rc[x]]), R[x] = std::max(R[x], R[rc[x]]);
            U[x] = std::min(U[x], U[rc[x]]), D[x] = std::max(D[x], D[rc[x]]);
        }
    }
    int build(int l, int r)
    {
        if (l > r) return 0;
        int mid = (l + r) >> 1;
        double avrx = 0, avry = 0, valx = 0, valy = 0;
        for (register unsigned i = l; i <= r; ++i)
            avrx += t[g[i]].x, avry += t[g[i]].y;
        avrx /= (r - l + 1), avry /= (r - l + 1);
        for (register unsigned i = l; i <= r; ++i)
            valx += (avrx - t[g[i]].x) * (avrx - t[g[i]].x),
                valy += (avry - t[g[i]].y) * (avry - t[g[i]].y);
        if (valx < valy)
            std::nth_element(g + l, g + mid, g + r + 1, [&](int a, int b) { return t[a].x < t[b].x; }), d[g[mid]] = 1;
        else
            std::nth_element(g + l, g + mid, g + r + 1, [&](int a, int b) { return t[a].y < t[b].y; }), d[g[mid]] = 2;
        lc[g[mid]] = build(l, mid - 1), rc[g[mid]] = build(mid + 1, r), pushup(g[mid]);
        return g[mid];
    }
    inline void restore(int &x)
    {
        cnt = 0, dfs(x);
        x = build(1, cnt);
    }
    inline bool check(int x) { return (delta * size[x]) <= (double)(std::max(size[lc[x]], size[rc[x]])); }
    void insert(int &x, int u)
    {
        if (!x) return (void)(x = u, pushup(x));
        if (d[x] == 1)
            ((t[u].x <= t[x].x) ? insert(lc[x], u) : insert(rc[x], u));
        else
            ((t[u].y <= t[x].y) ? insert(lc[x], u) : insert(rc[x], u));
        pushup(x);
        if (check(x)) restore(x);
    }
    int query(int x)
    {
        if (!x || xl > R[x] || L[x] > xr || yl > D[x] || U[x] > yr) return 0;
        if (xl <= L[x] && R[x] <= xr && yl <= U[x] && D[x] <= yr) return sum[x];
        int ret = 0, X = t[x].x, Y = t[x].y;
        if (xl <= X && X <= xr && yl <= Y && Y <= yr) ret += t[x].val;
        return query(lc[x]) + query(rc[x]) + ret;
    }
} T;

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

int main()
{
    int op, ans;
    read(), n = read();
    while ((op = read()) != 3)
    {
        if (op == 1)
        {
            cur++, T.t[cur].x = read();
            T.t[cur].y = read(), T.t[cur].val = read(), T.insert(root, cur);
        }
        else if (op == 2)
        {
            xl = read(), yl = read(), xr = read(), yr = read();
            ans = T.query(root), printf("%d\n", ans);
        }
    }
    return 0;
}
