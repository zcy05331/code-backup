#include <bits/stdc++.h>
#define getpos(x) ((x - 1) / block + 1)
#define getblock(x) ((x - 1) * block + 1)
const int MaxN = 100010;
struct query
{
    int id, pos;
    int l, r, a, b;
};
query q[MaxN];
int n, m, size, block;
int a[MaxN], cnt[MaxN], sum[MaxN][3], ans[MaxN][3];
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
    ++cnt[a[x]];
    ++sum[getpos(a[x])][1];
    if (cnt[a[x]] == 1)
        ++sum[getpos(a[x])][2];
}
inline void del(int x)
{
    --cnt[a[x]];
    --sum[getpos(a[x])][1];
    if (cnt[a[x]] == 0)
        --sum[getpos(a[x])][2];
}
inline void ask(int x)
{
    int id = q[x].id, l = q[x].a, r = q[x].b, Posl = getpos(q[x].a), Posr = getpos(q[x].b);
    for (int i = Posl + 1; i < Posr; i++)
        ans[id][1] += sum[i][1], ans[id][2] += sum[i][2];
    if (Posl == Posr)
    {
        for (int i = l; i <= r; i++)
        {
            ans[id][1] += cnt[i];
            if (cnt[i])
                ans[id][2]++;
        }
    }
    else
    {
        int L = getblock(Posr), R = getblock(Posl + 1) - 1;
        for (int i = l; i <= R; i++)
        {
            ans[id][1] += cnt[i];
            if (cnt[i])
                ans[id][2]++;
        }
        for (int i = L; i <= r; i++)
        {
            ans[id][1] += cnt[i];
            if (cnt[i])
                ans[id][2]++;
        }
    }
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
            del(l), l++;
        while (r > q[i].r)
            del(r), r--;
        ask(i);
    }
}
int main()
{
    n = read(), m = read();
    size = pow(n, 0.55), block = sqrt(n);
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i <= m; i++)
    {
        q[i].l = read(), q[i].r = read();
        q[i].a = read(), q[i].b = read();
        q[i].id = i, q[i].pos = (q[i].l - 1) / size + 1;
    }
    std::sort(q + 1, q + m + 1, cmp);
    solve();
    for (int i = 1; i <= m; i++)
        printf("%d %d\n", ans[i][1], ans[i][2]);
    return 0;
}
