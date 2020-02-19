#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e5 + 10;

ll n, k, s, a[MaxN], f[MaxN];
std::deque<int> dq;

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

int main()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), s += a[i];
    for (int i = 1; i <= n; i++)
    {
        if (!dq.empty())
            f[i] = f[dq.front()] + a[i];
        else
            f[i] = a[i];
        while (!dq.empty() && f[i] <= f[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        while (!dq.empty() && i - dq.front() > k)
            dq.pop_front();
    }
    ll ans = 0x3f3f3f3f3f3f;
    for (int i = n - k; i <= n; i++)
        ans = std::min(ans, f[i]);
    printf("%lld\n", s - ans);
    return 0;
}
