// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define ll long long
const int MaxN = 500010;
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
int a[MaxN], n, m, k;
int cnt[MaxN << 1], ans[MaxN];
inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    m = read();
    int size = n / sqrt((m * 2) / 3);
    for (int i = 1; i <= m; i++)
    {
        q[i].l = read(), q[i].r = read();
        q[i].id = i, q[i].pos = (q[i].l - 1) / size + 1;
    }
    std::sort(q + 1, q + m + 1);
    int l = 1, r = 0, sum = 0;
    for (int i = 1; i <= m; i++)
    {
        while (l > q[i].l)
            l--, cnt[a[l]]++, sum += ((cnt[a[l]] == 1) ? 1 : 0);
        while (r < q[i].r)
            r++, cnt[a[r]]++, sum += ((cnt[a[r]] == 1) ? 1 : 0);
        while (l < q[i].l)
            cnt[a[l]]--, sum -= ((cnt[a[l]] == 0) ? 1 : 0), l++;
        while (r > q[i].r)
            cnt[a[r]]--, sum -= ((cnt[a[r]] == 0) ? 1 : 0), r--;
        ans[q[i].id] = sum;
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}