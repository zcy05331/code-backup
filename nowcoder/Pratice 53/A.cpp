#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e5 + 10;
const int mod = 1e9 + 7;

ll n, f[MaxN][2];

int main()
{
    scanf("%lld", &n);
    f[1][0] = f[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i][1] = (f[i - 1][0]) % mod;
        f[i][0] = (f[i - 1][0] + f[i - 1][1]) % mod;
    }
    printf("%lld\n", (f[n][0] + f[n][1]) % mod);
    return 0;
}
