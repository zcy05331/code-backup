#include <bits/stdc++.h>
#define N 500005
#define inf 1000000000
using namespace std;
int x[N], y[N];
int n, f, rt, m, ans;
struct Point
{
    int d[2], maxv[2], minv[2], l, r;
    int &operator[](int x) { return d[x]; }
    friend bool operator<(Point a, Point b) { return a[f] < b[f]; }
    friend int querydis(Point a, Point b) { return abs(a[1] - b[1]) + abs(a[0] - b[0]); }
} p[N];
struct K_D_Tree
{
    Point t[N], T;
    int ans;
    void pushup(int x)
    {
        int l = t[x].l, r = t[x].r;
        for (int i = 0; i <= 1; i++)
        {
            t[x].minv[i] = t[x].maxv[i] = t[x][i];
            if (l)
            {
                t[x].minv[i] = min(t[x].minv[i], t[l].minv[i]);
                t[x].maxv[i] = max(t[x].maxv[i], t[l].maxv[i]);
            }
            if (r)
            {
                t[x].minv[i] = min(t[x].minv[i], t[r].minv[i]);
                t[x].maxv[i] = max(t[x].maxv[i], t[r].maxv[i]);
            }
        }
    }
    int build(int l, int r, int f)
    {
        int mid = (l + r) >> 1;
        nth_element(p + l, p + mid, p + r + 1);
        t[mid] = p[mid];
        for (int i = 0; i <= 1; i++)
            t[mid].minv[i] = t[mid].maxv[i] = t[mid][i];
        if (l < mid) t[mid].l = build(l, mid - 1, f ^ 1);
        if (r > mid) t[mid].r = build(mid + 1, r, f ^ 1);
        pushup(mid);
        return mid;
    }
    int getmin(Point a)
    {
        int ans = 0;
        for (int i = 0; i <= 1; i++)
        {
            ans += max(T[i] - a.maxv[i], 0);
            ans += max(a.minv[i] - T[i], 0);
        }
        return ans;
    }
    int getmax(Point a)
    {
        int ans = 0;
        for (int i = 0; i <= 1; i++)
        {
            ans += max(abs(T[i] - a.maxv[i]), abs(T[i] - a.minv[i]));
        }
        return ans;
    }
    void querymax(int x)
    {
        ans = max(ans, querydis(t[x], T));
        int l = t[x].l, r = t[x].r, dl = -inf, dr = -inf;
        if (l) dl = getmax(t[l]);
        if (r) dr = getmax(t[r]);
        if (dl > dr)
        {
            if (dl > ans) querymax(l);
            if (dr > ans) querymax(r);
        }
        else
        {
            if (dr > ans) querymax(r);
            if (dl > ans) querymax(l);
        }
    }
    void querymin(int x)
    {
        int tmp = querydis(T, t[x]);
        if (tmp) ans = min(ans, tmp);
        int l = t[x].l, r = t[x].r, dl = inf, dr = inf;
        if (l) dl = getmin(t[l]);
        if (r) dr = getmin(t[r]);
        if (dl < dr)
        {
            if (dl < ans) querymin(l);
            if (dr < ans) querymin(r);
        }
        else
        {
            if (dr < ans) querymin(r);
            if (dl < ans) querymin(l);
        }
    }
    int query(int f, int x, int y)
    {
        T[0] = x;
        T[1] = y;
        if (!f)
            ans = inf, querymin(rt);
        else
            ans = -inf, querymax(rt);
        return ans;
    }
} kd;
inline int read()
{
    int f = 1, x = 0;
    char ch;
    do
    {
        ch = getchar();
        if (ch == '-') f = -1;
    } while (ch < '0' || ch > '9');
    do
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return f * x;
}
int main()
{
    n = read();
    ans = inf;
    for (int i = 1; i <= n; i++)
    {
        x[i] = read();
        y[i] = read();
        p[i][0] = x[i];
        p[i][1] = y[i];
    }
    rt = kd.build(1, n, 0);
    for (int i = 1; i <= n; i++)
    {
        int minv = kd.query(0, x[i], y[i]), maxv = kd.query(1, x[i], y[i]);
        ans = min(ans, maxv - minv);
    }
    printf("%d\n", ans);
    return 0;
}