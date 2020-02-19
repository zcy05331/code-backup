#include <bits/stdc++.h>
const int MaxN = 2000010;
inline int read()
{
    register int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}
struct query
{
    int l, r, id, pos;
    bool operator<(const query &x) const
    {
        if (pos == x.pos)
            return r < x.r;
        else
            return pos < x.pos;
    }
};
query q[MaxN];
int l = 1, r, sum = 0;
int cnt[MaxN], num[MaxN], ans[MaxN];
int a[MaxN], vec[MaxN], val[MaxN], n, m, k, len;
inline void unique()
{
    memcpy(vec, a, sizeof(a));
    std::sort(vec + 1, vec + n + 1);
    for (int i = 1; i <= n; i++)
        if (i == 1 || vec[i] != vec[i - 1])
            val[++len] = vec[i];
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(val + 1, val + len + 1, a[i]) - val;
}
inline void add(int pos)
{
    num[cnt[a[pos]]]--;
    cnt[a[pos]]++;
    num[cnt[a[pos]]]++;
    sum = std::max(cnt[a[pos]], sum);
}
inline void del(int pos)
{
    num[cnt[a[pos]]]--;
    if(cnt[a[pos]] == sum && num[cnt[a[pos]]] == 0)
        --sum;
    cnt[a[pos]]--;
    num[cnt[a[pos]]]++;
}
int main()
{
    n = read(), m = read();
    int size = sqrt(n);
    for (register unsigned i = 1; i <= n; ++i)
        a[i] = read();
    unique();
    for (register unsigned i = 1; i <= m; ++i)
    {
        q[i].l = read(), q[i].r = read();
        q[i].id = i, q[i].pos = (q[i].l - 1) / size + 1;
    }
    std::sort(q + 1, q + m + 1);
    for (register unsigned i = 1; i <= m; ++i)
    {
        while (l > q[i].l)
            l--, add(l);
        while (r < q[i].r)
            r++, add(r);
        while (l < q[i].l)
            del(l), l++;
        while (r > q[i].r)
            del(r), r--;
        ans[q[i].id] = -sum;
    }
    for (register unsigned i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
    return 0;
}