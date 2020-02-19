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
        for (int i = 1; i <= 2 * n; i++)
            scanf("%d", &a[i]);
        std::sort(a + 1, a + 2 * n + 1);
        printf("%d\n", abs(a[n + 1] - a[n]));
    }
    return 0;
}
