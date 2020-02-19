#include <bits/stdc++.h>
const int MaxN = 10010;
long long n[MaxN], m[MaxN], k[MaxN];
int main()
{
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%I64d%I64d%I64d", &n[i], &m[i], &k[i]);
        if(m[i] > n[i])
            std::swap(m[i], n[i]);
        if (n[i] > k[i] || m[i] > k[i])
        {
            printf("-1\n");
            continue;
        }
        if(m[i] == 0 || n[i] == 0)
        {
            printf("%d\n", 0);
            continue;
        }
        long long ans = k[i] - n[i] + m[i];
        if((ans - m[i]) & 1)
            ans -= 2;
        if((n[i] - m[i]) & 1)
        {
            if((ans - m[i]) & 1)
                ans++;
            else ans--;
        }
        printf("%I64d\n", ans + n[i] - m[i]);
    }
    return 0;
}
