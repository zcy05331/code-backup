#include <bits/stdc++.h>
# define ll long long
const int MaxN = 50005;
struct query
{
    int l, r, id, pos;
    bool operator < (const query &x)const
    {
        if(pos == x.pos)
            return r < x.r;
        else return pos < x.pos;
    }
};
query q[MaxN];
int a[MaxN], n, m, k;
ll cnt[MaxN], ans[MaxN];
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    int size = sqrt(n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i, q[i].pos = (q[i].l - 1) / size + 1;
    }
    std::sort(q + 1, q + m + 1);
    int l = 1, r = 0;
    ll sum = 0;
    for(int i = 1; i <= m; i++)
    {   
        while (l > q[i].l)
            l--, cnt[a[l]]++, sum += 2 * cnt[a[l]] - 1;
        while(r < q[i].r)
            r++, cnt[a[r]]++, sum += 2 * cnt[a[r]] - 1;
        while(l < q[i].l)
            cnt[a[l]]--, sum -= 2 * cnt[a[l]] + 1, l++;
        while(r > q[i].r)
            cnt[a[r]]--, sum -= 2 * cnt[a[r]] + 1, r--;
        ans[q[i].id] = sum;
    }
    for(int i = 1; i <= m; i++)
        printf("%lld\n", ans[i]);
    return 0;
}