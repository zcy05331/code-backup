#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

ll n, L;
ll c[MaxN], s[MaxN], a[MaxN], f[MaxN], q[MaxN];

inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

ll k(ll num) { return 2 * a[num]; }
ll x(ll num) { return a[num]; }
ll y(ll num) { return f[num] + a[num] * a[num] + 2 * a[num] * L; }

int main()
{
    n = read(), L = read() + 1;
    for (int i = 1; i <= n; i++)
        c[i] = read(), s[i] = s[i - 1] + c[i], a[i] = s[i] + i;
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++)
    {
        while (l < r && (y(q[l + 1]) - y(q[l])) <= k(i) * (x(q[l + 1]) - x(q[l])))
            l++;
        f[i] = f[q[l]] + (a[i] - a[q[l]] - L) * (a[i] - a[q[l]] - L);
        while (l < r && (y(q[r]) - y(q[r - 1])) * (x(i) - x(q[r])) >= (y(i) - y(q[r])) * (x(q[r]) - x(q[r - 1])))
            r--;
        q[++r] = i;
    }
    printf("%lld\n", f[n]);
    return 0;
}
