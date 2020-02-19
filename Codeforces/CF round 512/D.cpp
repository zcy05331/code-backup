#include <bits/stdc++.h>

#define ll long long

ll gcd(ll a, ll b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

int main()
{
    ll n, m, k;
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    if (n * m * 2ll % k != 0)
        return 0 * puts("NO");
    puts("YES");
    printf("0 0\n");
    ll S = n * m * 2ll / k, x = gcd(n, S), X = S / x;
    if(k & 1)
        if(x * 2 <= n)
            x <<= 1, X >>= 1;
    printf("%I64d 0\n0 %I64d", x, X);
    return 0;
}