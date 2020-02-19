#include <bits/stdc++.h>
const int mod = 998244353;
long long fac[1000010];
int main()
{
    int n;
    scanf("%d", &n);
    fac[1] = 1;
    for(int i = 2; i <= n; i++)
        fac[i] = (long long)(fac[i - 1] * 1ll * i % mod);
    long long ans = 0, tmp = 1;
    for(int i = n; i > 2; i--)
        tmp = tmp * i % mod, ans = (ans + tmp * (fac[i - 1] - 1 + mod) % mod) % mod;
    printf("%I64d", (ans + fac[n]) % mod);
    return 0;
}