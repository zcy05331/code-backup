#include <bits/stdc++.h>

int main()
{
    long long n, k;
    scanf("%I64d%I64d", &n, &k);
    if(k % n == 0)
        printf("%I64d", k / n);
    else 
        printf("%I64d", k / n + 1);
    return 0;
}