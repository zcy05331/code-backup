#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

int n, a[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int min = 2e9 + 10, max = 0, x = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == -1)
            {
                if (~a[i + 1])
                {
                    max = std::max(max, a[i + 1]);
                    min = std::min(min, a[i + 1]);
                }
            }
            else if (a[i + 1] == -1)
            {
                max = std::max(max, a[i]);
                min = std::min(min, a[i]);
            }
            else
                x = std::max(x, abs(a[i] - a[i + 1]));
        }
        if (min == 2e9 + 10)
            min = max = 0;
        int ans = (min + max) >> 1;
        printf("%d %d\n", std::max(std::max(abs(ans - min), abs(max - ans)), x), ans);
    }
    return 0;
}