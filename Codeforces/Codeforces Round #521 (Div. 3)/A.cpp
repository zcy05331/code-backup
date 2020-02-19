# include <bits/stdc++.h>

# define ll long long

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        ll a, b, k;
        scanf("%I64d%I64d%I64d", &a, &b, &k);
        ll ans = (a - b) * (k / 2);
        if(k % 2)
            ans += a;
        printf("%I64d\n", ans);
    }
    return 0;
}