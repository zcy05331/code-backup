#include <bits/stdc++.h>
const int MaxN = 100010;
struct query
{
    int id, pos;
    int op, l, r, x;
};
query q[MaxN];
int n, m, size;
int a[MaxN], cnt[MaxN], ans[MaxN];
std::bitset<100010> cnt1, cnt2;
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
    if(cnt[a[x]] == 1)
        cnt1[a[x]] = 1, cnt2[100000 - a[x]] = 1;
}
inline void del(int x)
{
    --cnt[a[x]];
    if(cnt[a[x]] == 0)
        cnt1[a[x]] = 0, cnt2[100000 - a[x]] = 0;
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
        if (q[i].op == 1)
            ans[q[i].id] = (cnt1 & (cnt1 << q[i].x)).any();
        else if (q[i].op == 2)
            ans[q[i].id] = (cnt1 & (cnt2 >> (100000 - q[i].x))).any();
        else if (q[i].op == 3)
        {
            for (int j = 1; j * j <= q[i].x; j++)
            {
                if (q[i].x % j == 0)
                    if (cnt1[j] && cnt1[q[i].x / j])
                        ans[q[i].id] = 1;
            }
        }
    }
}
int main()
{
    n = read(), m = read();
    size = pow(n, 0.55);
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
    {
        q[i].op = read(), q[i].l = read(), q[i].r = read(), q[i].x = read();
        q[i].id = i, q[i].pos = (q[i].l - 1) / size + 1;
    }
    std::sort(q + 1, q + m + 1, cmp);
    solve();
    for (int i = 1; i <= m; i++)
        puts(ans[i] == 1 ? "hana" : "bi");
    return 0;
}
