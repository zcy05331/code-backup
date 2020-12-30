#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

struct node
{
    char c;
    ll a, id, ans;
} x[MaxN];

char c[MaxN];
ll n, l, t, cnt, a[MaxN], b[MaxN], pos[MaxN];

int cmp(node a, node b) { return (a.a < b.a); }
int cmp1(node a, node b) { return (a.id < b.id); }

signed main()
{
    ll pos = 1;
    scanf("%lld%lld%lld", &n, &l, &t);
    for (int i = 1; i <= n; x[i].id = i, i++)
        scanf("%lld %c", &x[i].a, &x[i].c);
    if(t == 0)  
    {
        for(int i = 1; i <= n; i++)
            printf("%lld ", x[i].a);
        return 0;
    }
    std::sort(x + 1, x + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        a[i] = x[i].a, c[i] = x[i].c;
        if (c[i] == 'R')
            b[i] = (a[i] + t) % l;
        else
            b[i] = ((a[i] - t) % l + l) % l;
        // fprintf(stderr, "%lld ", a[i]);
    }
    std::sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == 'R')
        {
            if (l - a[i] <= t)
                pos += ((t - l + a[i]) / l + 1) % n;
        }
        else
        {
            if (a[i] + 1 <= t)
                pos -= ((t - a[i] - 1) / l + 1) % n;
        }
    }
    pos = (pos % n + n) % n;
    if (pos == 0) pos = n;
    // fprintf(stderr, "pos = %lld\n", pos);
    for (int i = 1; i <= n; i++)
        x[i].ans = b[pos], pos = (pos % n) + 1;
    std::sort(x + 1, x + n + 1, cmp1);
    for(int i = 1; i <= n; i++)
        printf("%d ", ((x[i].ans == 0) ? l : x[i].ans));
    return 0;
}