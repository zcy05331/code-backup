#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
bool END;
char _B[1 << 16], *_S = _B, *_T = _B, _U[1 << 16 | 1], *_O = _U, *_W = _U + (1 << 16);
#define getc() (_S == _T && (_T = (_S = _B) + fread(_B, 1, 1 << 16, stdin), _S == _T) ? END = 1 : *_S++)

const int MaxN = 1e6 + 10;

ll n, k;
ll a[MaxN], s[MaxN];

ll read()
{
    ll x = 0;
    char ch = getc();
    while (ch > '9' || ch < '0')
        ch = getc();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getc();
    return x;
}

int main()
{
    n = read(), k = read();
    for (R int i = 1; i < n; ++i)
        a[i] = read();
    for (R int i = n - 1; i; i--)
        s[i] = a[i] + s[i + 1];
    ll ans = s[1];
    for (R int i = 1; i <= n; ++i)
        ans = std::min(ans, (s[1] - s[i]) + s[std::min(i + k, n)]);
    printf("%lld\n", ans);
    return 0;
}
