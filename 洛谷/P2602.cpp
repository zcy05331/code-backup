#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define openfile(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
ll a, b;
ll f[20], sum[20];
ll cnta[20], cntb[20];
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
inline void solve(ll x, ll *cnt)
{
    ll num[20] = {};
    int len = 0;
    while (x)
    {
        num[++len] = x % 10;
        x = x / 10;
    }
    for (int i = len; i >= 1; i--)
    {
        for (int j = 0; j <= 9; j++)
            cnt[j] += f[i - 1] * num[i];
        for (int j = 0; j < num[i]; j++)
            cnt[j] += sum[i - 1];
        ll tmp = 0;
        for (int j = i - 1; j >= 1; j--)
            tmp = tmp * 10 + num[j];
        cnt[num[i]] += tmp + 1;
        cnt[0] -= sum[i - 1];
    }
}
int main()
{
    a = read(), b = read();
    sum[0] = 1;
    for (int i = 1; i <= 15; i++)
    {
        f[i] = f[i - 1] * 10 + sum[i - 1];
        sum[i] = 10 * sum[i - 1];
    }
    solve(a - 1, cnta);
    solve(b, cntb);
    for (int i = 0; i <= 9; i++)
        printf("%lld ", cntb[i] - cnta[i]);
    return 0;
}
