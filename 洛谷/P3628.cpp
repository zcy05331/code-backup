#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

ll n, A, B, C;
ll a[MaxN], s[MaxN], f[MaxN], q[MaxN];

inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

ll g(int num) { return A * num * num + B * num + C; }
ll x(int num) { return s[num]; }
ll y(int num) { return (f[num] + A * s[num] * s[num] - B * s[num]); }
ll k(int num) { return 2 * A * s[num]; }

int main()
{
    n = read(), A = read(), B = read(), C = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), s[i] = s[i - 1] + a[i];
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++)
    {
        while (l < r && (y(q[l + 1]) - y(q[l])) >= k(i) * (x(q[l + 1]) - x(q[l])))
            ++l;
        f[i] = f[q[l]] + g(s[i] - s[q[l]]);
        while (l < r && (y(q[r]) - y(q[r - 1])) * (x(i) - x(q[r])) <= (y(i) - y(q[r])) * (x(q[r]) - x(q[r - 1])))
            --r;
        q[++r] = i;
    }
    printf("%lld\n", f[n]);
    return 0;
}
