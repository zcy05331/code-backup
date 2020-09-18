#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 2e5 + 10;

std::vector<ll> vec;
ll n, k, ans1, ans2;
ll a[MaxN], b[MaxN], c[MaxN];

char get()
{
    char ch = getchar();
    while (!isalpha(ch))
        ch = getchar();
    return ch;
}

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

signed main()
{
    ll cnt = 0;
    k = read(), n = read();
    for (ll i = 1; i <= n; i++)
    {
        ll a, b;
        char A, B;
        A = get(), a = read(), B = get(), b = read();
        if (A == B)
            ans1 += abs(b - a);
        else
        {
            ++cnt, ++ans1;
            if (A == 'B') std::swap(a, b);
            ::a[cnt] = a, ::b[cnt] = b, c[cnt] = a + b;
        }
    }
    n = cnt;
    if (k == 1)
    {
        cnt = 0;
        ll mid = 0;
        for(int i = 1; i <= n; i++)
            c[++cnt] = a[i], c[++cnt] = b[i];
        std::sort(c + 1, c + cnt + 1), mid = c[cnt >> 1];
        for(int i = 1; i <= cnt; i++)
            ans2 += abs(mid - c[i]);
        printf("%lld\n", ans1 + ans2 + n);
        return 0;
    }
    std::sort(c + 1, c + n + 1);
    return 0;
}
