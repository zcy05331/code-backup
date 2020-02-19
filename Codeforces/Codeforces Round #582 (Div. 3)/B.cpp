#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e5 + 10;

int n, a[MaxN], minx[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        minx[n] = a[n];
        int ans = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            minx[i] = 0;
            if (a[i] > minx[i + 1])
                ++ans;
            minx[i] = std::min(a[i], minx[i + 1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
