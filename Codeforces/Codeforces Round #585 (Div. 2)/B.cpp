#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 5e5 + 10;

ll n, a[MaxN], s[MaxN], odd[MaxN], even[MaxN];

int main()
{
    scanf("%I64d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &a[i]), s[i] = (s[i - 1] + ((a[i] > 0) ? 0 : 1));
    for (int i = 1; i <= n; i++)
    {
        odd[i] = odd[i - 1], even[i] = even[i - 1];
        if (s[i] % 2)
            odd[i]++;
        else
            even[i]++;
    }
    ll ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] % 2)
            ans1 += odd[i - 1];
        else
            ans1 += even[i];
    }
    ans2 = (n * (n + 1ll)) / 2ll, ans2 -= ans1;
    std::cout << ans2 << ' ' << ans1;
    return 0;
}
