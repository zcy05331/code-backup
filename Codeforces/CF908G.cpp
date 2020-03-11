#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 7e2 + 10;
const ll mod = 1e9 + 7;

char s[MaxN];
ll n, a[MaxN], f[MaxN][MaxN][10][2];

int main()
{
    ll ans = 0;
    scanf("%s", s + 1), n = strlen(s + 1);
    for (ll i = 1; i <= n; i++)
        a[i] = s[i] - '0';
    for (ll i = 0; i <= 9; i++)
        f[0][0][i][0] = 1;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j <= i; j++)
            for (ll k = 1; k <= 9; k++)
                for (ll op = 0; op < 2; op++)
                    for (ll p = 0; p <= (op ? 9 : a[i + 1]); p++)
                        f[i + 1][j + (p >= k)][k][op | (p < a[i + 1])] = sum(f[i + 1][j + (p >= k)][k][op | (p < a[i + 1])], f[i][j][k][op], mod);
    for (ll k = 1; k <= 9; k++)
    {
        ll tmp = 1;
        for (ll i = 1; i <= n; i++)
            ans = sum(ans, tmp * 1ll * (f[n][i][k][0] + f[n][i][k][1]) % mod, mod), tmp = (tmp * 10 + 1) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
