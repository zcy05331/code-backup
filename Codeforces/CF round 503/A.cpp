#include<bits/stdc++.h>

int main()
{
    long long n, h, a, b;
    int k;
    scanf("%I64d%I64d%I64d%I64d%d", &n, &h, &a, &b, &k);
    for (int i = 1; i <= k; i++)
    {
        long long ans;
        long long t1, f1, t2, f2;
        scanf("%I64d%I64d%I64d%I64d", &t1, &f1, &t2, &f2);
        ans = abs(t1 - t2);
        if(t1 == t2)
        {
            printf("%d\n", abs(f1 - f2));
            continue;
        }
        if((f1 >= a  && f1 <= b)|| (f2 >= a && f2 <= b) )ans += abs(f1 - f2);
        else
            ans += std::min(abs(f1 - a) + abs(f2 - a), abs(f1 - b) + abs(f2 - b));
        printf("%I64d\n", ans);
    }
    return 0;
}