#include <bits/stdc++.h>
const int MaxN = 200010;
struct query
{
    int l, r;
    int pos, id;
};
query q[MaxN];
int n, m, size, now;
int a[MaxN], cnt[MaxN], ans[MaxN];
inline int cmp(query a, query b)
{
    if (a.pos != b.pos)
        return a.pos < b.pos;
    else
        return a.r < b.r;
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
inline void add(int x)
{
    ++cnt[a[x]];
    if (a[x] == now)
        while (cnt[now])
            ++now;
}
inline void del(int x)
{
    --cnt[a[x]];
    if (cnt[a[x]] == 0)
        now = std::min(now, a[x]);
}
inline void solve()
{
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++)
    {
        while (l > q[i].l)
            --l, add(l);
        while (r < q[i].r)
            ++r, add(r);
        while (l < q[i].l)
            del(l), ++l;
        while (r > q[i].r)
            del(r), --r;
        ans[q[i].id] = now;
    }
}
int main()
{
    n = read(), m = read();
    size = pow(n, 0.55);
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= m; i++)
    {
        q[i].l = read(), q[i].r = read();
        q[i].id = i, q[i].pos = (q[i].l - 1) / size + 1;
    }
    std::sort(q + 1, q + m + 1, cmp);
    solve();
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}
