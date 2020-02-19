#include <bits/stdc++.h>

int main()
{
    long long m, k;
    scanf("%lld%lld", &k, &m);;
    long long n = 1;
    unsigned long long tmp = 1;
    while(1)
    {
        if(tmp % m == k)
            break;
        n++;
        tmp = ((tmp * 10) + 1) % m;
    }
    printf("%lld\n", n);
    return 0;
}