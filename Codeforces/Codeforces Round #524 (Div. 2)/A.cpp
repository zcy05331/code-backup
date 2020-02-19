# include <bits/stdc++.h>

# define ll long long

int main()
{
    ll n, k;
    scanf("%lld%lld", &n, &k);
    ll ans = ((2 * n) / k) + ((5 * n) / k) + ((8 * n) / k) + bool((2 * n) % k != 0) + bool((5 * n) % k != 0) + bool((8 * n) % k != 0);
    printf("%lld\n", ans);
    return 0;
}