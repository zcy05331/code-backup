#include <bits/stdc++.h>

int main()
{   
    long long w1, w2, h1, h2;
    scanf("%I64d%I64d%I64d%I64d", &w1, &h1, &w2, &h2);
    long long ans = (w1 + 2) * (h1 + h2 + 2) - (w1 - w2) * h2;
    printf("%I64d\n", ans - w1 * h1 - w2 * h2);
    return 0;
}
