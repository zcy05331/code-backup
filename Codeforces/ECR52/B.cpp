#include <bits/stdc++.h>

#define ll long long

const int MaxN = 100010;

int main()
{
    ll n, m;
    scanf("%I64d%I64d", &n, &m);
    if(m == 0)
    {
        printf("%I64d %I64d", n, n);
        return 0;
    }
    ll pmin = 0x7f7f7f7f, pmax = 0;
    pmin = n - m * 2;
    if(pmin < 0)
        pmin = 0;
    pmax = sqrt(2 * m);
    while(pmax * (pmax - 1) < m * 2 )
        ++pmax;
    printf("%I64d %I64d", pmin, n - pmax);
    return 0;
}