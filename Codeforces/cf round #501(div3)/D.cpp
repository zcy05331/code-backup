#include <bits/stdc++.h>

long long n,k,s;

int main()
{

    scanf("%I64d%I64d%I64d", &n, &k, &s);
    if(s > k * (n - 1ll) ||s < k)
    {
        puts("NO");
        return 0;
    }
    printf("YES\n");
    int pos = 1;
    for(int i = 1; i <= k; i++)
    {
        if(s > k)
        {
            if (pos + s / k <= n)
                pos += std::min(n - 1, s / k);
            else if (pos - s / k >= 1)
                pos -= std::min(n - 1, s / k);
            s -= std::min(n - 1, s / k);
            printf("%d ", pos);
            k--;
        }
        
    }
    return 0;
}