#include <bits/stdc++.h>
#define int long long
const int MaxN = 1000010;
struct query
{
    int l, r, id, pos;
};
query q[MaxN];
int n, t, size;
int ans[MaxN], sum;
int a[MaxN], cnt[MaxN];
inline int cmp(query a, query b)
{
    if (a.pos != b.pos)
        return a.pos < b.pos;
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
    sum += a[x] * (2 * cnt[a[x]] + 1);
    cnt[a[x]]++;
}
inline void del(int x)
{
    sum -= a[x] * (2 * cnt[a[x]] - 1);
    cnt[a[x]]--;
}
inline void solve()
{
    int l = 1, r = 0;
    for (int i = 1; i <= t; i++)
    {
        while (l > q[i].l)
            --l, add(l);
        while (r < q[i].r)
            ++r, add(r);
        while (l < q[i].l)
            del(l), ++l;
        while (r > q[i].r)
            del(r), --r;
        ans[q[i].id] = sum;
    }
}
signed main()
{
    n = read(), t = read();
    size = pow(n, 0.55);
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= t; i++)
    {
        q[i].l = read(), q[i].r = read();
        q[i].id = i, q[i].pos = (q[i].l - 1) / size + 1;
    }
    std::sort(q + 1, q + t + 1, cmp);
    solve();
    for (int i = 1; i <= t; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
