#include <bits/stdc++.h>

long long gcd(long long a, long long b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

int main()
{
    long long a, b, x, y;
    scanf("%I64d%I64d%I64d%I64d", &a, &b, &x, &y);
    long long g = gcd(x, y);
    x /= g;
    y /= g;
    printf("%I64d", std::min((long long)(a / x), (long long)(b / y)));
    return 0;
}