#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

int ceil(int i, int j) { return (i / j) + (!!(i % j)); }



int main()
{
    int T, n, m;
    scanf("%d", &T);
    while (T--)
    {
        int ans = 0;
        scanf("%d%d", &n, &m);
        int a = n / (m + 1), b = n / m;
        if (a < b && b <= (n - b)) ans += b - a;
        a = ceil(n, m + 1), b = ceil(n, m);
        if (a < b && (n - b + 1) > (b - 1)) ans += b - a;
        printf("%d\n", ans);
    }
    return 0;
}
