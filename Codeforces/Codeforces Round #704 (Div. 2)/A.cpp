#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

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
    ll T = read();
    while (T--)
    {
        ll p = read(), a = read(), b = read(), c = read();
        ll ansa = (a - p % a) % a, ansb = (b - p % b) % b, ansc = (c - p % c) % c;
        printf("%I64d\n", std::min(ansa, std::min(ansb, ansc)));
    }
    return 0;
}
