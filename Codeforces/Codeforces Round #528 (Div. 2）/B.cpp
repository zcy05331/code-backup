#include <bits/stdc++.h>
# define ll long long
int main()
{
    ll n, k;
    ll ans = 0;
    scanf("%I64d%I64d", &n, &k);
    for(int i = 1; i < k; i++)
        if(n % i == 0)
            ans = i;
    printf("%I64d", (((n / ans) * k) + ans));
    return 0;
}