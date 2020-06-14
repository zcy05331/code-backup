#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int inf = 1e9 + 7;
const int MaxN = 5e5 +10;

int n, m, cnt, ans;
int nowd, root, x[MaxN], y[MaxN];

struct node
{
    int lc, rc;
    int d[2], max[2], min[2];
    int &operator[](int x) {return d[x];}
    friend bool operator<(node a, node b) { return a[nowd] < b[nowd]; }
    friend int dis(node a, node b) { return abs(a[1] - b[1]) + abs(a[0] - b[0]); }
};

node a[MaxN];

struct kdtree
{
    int ans;
    node t[MaxN], q;
    void pushup(int x)
    {
        int lc = t[x].lc, rc = t[x].rc;
        for(int i = 0; i < 2; i++)
        {
            t[x].min[i] = t[x].max[i] = t[x][i];
            if(lc) 
            {
                t[x].min[i] = std::min(t[x].min[i], t[lc].min[i]);
                t[x].max[i] = std::max(t[x].max[i], t[lc].max[i]);
            }
            if(rc)
            {
                t[x].min[i] = std::min(t[x].min[i], t[rc].min[i]);
                t[x].max[i] = std::max(t[x].max[i], t[rc].max[i]);
            }
        }
    }
    int build(int l, int r, int d)
    {
        int mid = (l + r) >> 1;
        std::nth_element(a + l, a + mid, a + r + 1), t[mid] = a[mid];
        for(int i = 0; i < 2; i++)
            t[mid].min[i] = t[mid].max[i] = t[mid][i];
        if(l < mid) t[mid].lc = build(l, mid - 1, d ^ 1);
        if(r > mid) t[mid].rc = build(mid + 1, r, d ^ 1);
        pushup(mid);
        return mid;
    }
    int getmin(node a) 
    {
        int ans = 0;
        for(int i = 0; i < 2; i++)
        {
            ans += std::max(q[i] - a.max[i], 0);
            ans += std::max(a.min[i] - q[i], 0);
        }
        return ans;
    }
    int getmax(node a)
    {
        int ans = 0;
        for(int i = 0; i < 2; i++)
            ans += std::max(abs(q[i] - a.max[i]), abs(q[i] - a.min[i]));
        return ans;
    }
    void query_max(int x)
    {
        ans = std::max(ans, dis(t[x], q));
        int lc = t[x].lc, rc = t[x].rc, dl = -inf, dr = -inf;
        if(lc) dl = getmax(t[lc]);
        if(rc) dr = getmax(t[rc]);
        if(dl > dr)
        {
            if(dl > ans) query_max(lc);
            if(dr > ans) query_max(rc);
        }
        else
        {
            if(dr > ans) query_max(rc);
            if(dl > ans) query_max(lc);
        }
    }
    void query_min(int x)
    {
        int tmp = dis(t[x], q);
        if(tmp) ans = std::min(ans, tmp);
        int lc = t[x].lc, rc = t[x].rc, dl = inf, dr = inf;
        if (lc) dl = getmin(t[lc]);
        if (rc) dr = getmin(t[rc]);
        if (dl < dr)
        {
            if (dl < ans) query_min(lc);
            if (dr < ans) query_min(rc);
        }
        else
        {
            if (dr < ans) query_min(rc);
            if (dl < ans) query_min(lc);
        }
    }
    int query(int d, int x, int y)
    {
        q[0] = x, q[1] = y;
        if(!d) ans = inf, query_min(root);
        else ans = -inf, query_max(root);
        return ans;
    }
} T;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0')
    {
        if(ch == '-')
            f = 0;
        ch = getchar();
    }
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

int main()
{   
    n = read(), ans = inf;
    for(int i = 1; i <= n; i++)
    {
        x[i] = read(), y[i] = read();
        a[i][0] = x[i], a[i][1] = y[i];
    }
    root = T.build(1, n, 0);
    for(int i = 1; i <= n; i++)
    {
        int min = T.query(0, x[i], y[i]);
        int max = T.query(1, x[i], y[i]);
        ans = std::min(ans, max - min);
    }
    printf("%d\n", ans);
    return 0;
}
