# include <bits/stdc++.h>

# define ll long long

const int MaxN = 100010;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        ll s, a, b, c;
        scanf("%I64d%I64d%I64d%I64d", &s, &a, &b, &c);
        ll ans = 0;
        ans = s / c;
        ans = ans + (ans / a) * b;
        printf("%I64d\n", ans);
    }
    
    return 0;
}