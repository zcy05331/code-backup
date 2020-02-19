#include <bits/stdc++.h>
#define ll long long
const int MaxN = 100010;
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
ll cnt[MaxN], ans[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    int size = sqrt(n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i, q[i].pos = (q[i].l - 1) / size + 1;
    }
    std::sort(q + 1, q + m + 1);
    int l = 1, r = 0;
    ll sum = 0;
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
        ans[q[i].id] = ((sum == (q[i].r - q[i].l + 1)) ? 1 : 0);
    }
    for (int i = 1; i <= m; i++)
        puts((ans[i] == 1) ? "Yes" : "No");
    return 0;
}