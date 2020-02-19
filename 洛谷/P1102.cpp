#include <bits/stdc++.h>

const int MaxN = 200010;
long long a[MaxN];
std::map<long long, int> m;
long long n, c;
long long ans;

int main()
{

    scanf("%lld%lld", &n, &c);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        m[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        ans += m[a[i] - c];
    }
    printf("%lld", ans);
    return 0;
}