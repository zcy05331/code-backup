#include <bits/stdc++.h>
int main()
{
    long long n, k;
    scanf("%I64d%I64d", &n, &k);
    if(k <= n)printf("%I64d", (k - 1) / 2);
    else printf("%I64d", std::max(0ll, n - k / 2));
    return 0;
}