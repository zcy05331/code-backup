// luogu-judger-enable-o2
#include <bits/stdc++.h>
# define ll long long
const int MaxN = 50010;
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
ll a[MaxN], n, m, k;
ll cnt[MaxN], x[MaxN], y[MaxN];
ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}
int main()
{
    scanf("%lld%lld", &n, &m);
    int size = n / sqrt(m * 2 / 3);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(int i = 1; i <= m; i++)
    {
        scanf("%lld%lld", &q[i].l, &q[i].r);
        q[i].id = i, q[i].pos = (q[i].l - 1) / size + 1;
    }
    std::sort(q + 1, q + m + 1);
    int l = 1, r = 0;
    ll sum = 0;
    for(int i = 1; i <= m; i++)
    {   
        if(q[i].l == q[i].r)
        {
            x[q[i].id] = 0, y[q[i].id] = 1;
            continue;
        }
        while (l > q[i].l)
            l--, cnt[a[l]]++, sum += 2ll * cnt[a[l]] - 1;
        while(r < q[i].r)
            r++, cnt[a[r]]++, sum += 2ll * cnt[a[r]] - 1;
        while(l < q[i].l)
            cnt[a[l]]--, sum -= 2ll * cnt[a[l]] + 1, l++;
        while(r > q[i].r)
            cnt[a[r]]--, sum -= 2ll * cnt[a[r]] + 1, r--;
        x[q[i].id] = sum - 1ll * (q[i].r - q[i].l + 1), y[q[i].id] = (q[i].r - q[i].l + 1) * 1ll * (q[i].r - q[i].l);
        ll g = gcd(x[q[i].id], y[q[i].id]);
        x[q[i].id] /= g, y[q[i].id] /= g;
    }
    for(int i = 1; i <= m; i++)
        printf("%lld/%lld\n", x[i], y[i]);
    return 0;
}