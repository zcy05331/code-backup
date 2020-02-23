#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 1e6 + 10;

ll top, st[MaxN], val[MaxN];
ll n, a[MaxN], pre[MaxN], suf[MaxN], ans[MaxN];

int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (ll i = n; i; i--)
    {
        ll tmp = 1;
        suf[i] = suf[i + 1] + a[i];
        while (top && st[top] > a[i])
            suf[i] -= val[top] * (st[top] - a[i]), tmp += val[top--];
        val[++top] = tmp, st[top] = a[i];
    }
    top = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll tmp = 1;
        pre[i] = pre[i - 1] + a[i];
        while (top && st[top] > a[i])
            pre[i] -= val[top] * (st[top] - a[i]), tmp += val[top--];
        val[++top] = tmp, st[top] = a[i];
    }
    ll maxx = 0, id = 0;
    for (ll i = 1; i <= n; i++)
        if (maxx < pre[i] + suf[i + 1])
            maxx = pre[i] + suf[i + 1], id = i;
    ll now = 1e9 + 7;
    for (ll i = id; i; i--)
        now = std::min(now, a[i]), ans[i] = now;
    now = 100000000;
    for (ll i = id + 1; i <= n; i++)
        now = std::min(now, a[i]), ans[i] = now;
    for (ll i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
    return 0;
}
