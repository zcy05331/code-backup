#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

int main()
{
    ll t, x, y;
    scanf("%I64d", &t);
    while (t--)
    {
        scanf("%I64d%I64d", &x, &y);
        if (x - y == 1ll)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
