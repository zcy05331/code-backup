#include <bits/stdc++.h>

bool p[10000010];
long long phi[10000010], ans;
long long n, m, cnt, prime[2500010];

void getphi()
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!p[i])
        {
            prime[++cnt] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= cnt; j++)
        {
            if (i * prime[j] > n)
                break;
            p[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}

int main()
{
    scanf("%lld%lld", &n, &m);
    getphi();
    for (int i = 1; i <= std::min(n, m); i++)
        ans += phi[i] * (n / i) * (m / i);
    ans = ans * 2 - m * n;
    printf("%lld\n", ans);
    return 0;
}
