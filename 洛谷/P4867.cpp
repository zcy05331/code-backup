// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define getindex(x) ((x - 1) * block + 1)
#define getpos(x) ((x - 1) / block + 1)
#define lowbit(x) (x & (-x))
const int MaxN = 1e5 + 10, MaxM = 1e6 + 10;
struct query
{
    int id, pos;
    int l, r, a, b;
};
query q[MaxM];
int n, m, size, block;
int a[MaxN], ans[MaxM], cnt[MaxN], sum[MaxN];
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
inline void ins(int x)
{
    ++cnt[a[x]];
    if (cnt[a[x]] == 1)
        ++sum[getpos(a[x])];
}
inline void del(int x)
{
    --cnt[a[x]];
    if (cnt[a[x]] == 0)
        --sum[getpos(a[x])];
}
inline int ask(int a, int b, int l, int r)
{
    int ans = 0, Posl = getpos(l), Posr = getpos(r);
    for (int i = Posl + 1; i < Posr; i++)
        ans += sum[i];
    if (Posl == Posr)
    {
        for (int i = l; i <= r; i++)
            if (cnt[i])
                ++ans;
    }
    else
    {
        int L = getindex(Posr), R = getindex(Posl + 1) - 1;
        for (int i = l; i <= R; i++)
            if (cnt[i])
                ++ans;
        for (int i = L; i <= r; i++)
            if (cnt[i])
                ++ans;
    }
    return ans;
}
inline void solve()
{
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++)
    {
        while (l > q[i].l)
            l--, ins(l);
        while (r < q[i].r)
            r++, ins(r);
        while (l < q[i].l)
            del(l), l++;
        while (r > q[i].r)
            del(r), r--;
        ans[q[i].id] = ask(q[i].l, q[i].r, q[i].a, q[i].b);
    }
}
int main()
{
    n = read(), m = read();
    size = pow(n, 0.55), block = sqrt(n);
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i <= m; ++i)
    {
        q[i].l = read(), q[i].r = read();
        q[i].a = read(), q[i].b = read();
        q[i].id = i, q[i].pos = (q[i].l - 1) / size + 1;
    }
    std::sort(q + 1, q + m + 1, cmp);
    solve();
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}