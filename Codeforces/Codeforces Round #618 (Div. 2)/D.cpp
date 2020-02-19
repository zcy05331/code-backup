#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

int n, a[MaxN], b[MaxN];

int main()
{
    scanf("%d", &n);
    if (n & 1)
        return 0 * printf("nO");
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i], &b[i]);
    for (int i = 1; i <= (n / 2); i++)
        if ((a[i] + a[i + (n / 2)] != a[1] + a[(n / 2) + 1]) || (b[i] + b[i + (n / 2)] != b[1] + b[(n / 2) + 1]))
            return 0 * printf("No");
    puts("YEs");
    return 0;
}
