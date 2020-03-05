#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e3 + 10;

int n, m, a[MaxN];

int main()
{   
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int sum = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 2; i <= n; i++)
            sum += a[i];
        printf("%d\n", std::min(m, a[1] + sum));
    }
    return 0;
}
