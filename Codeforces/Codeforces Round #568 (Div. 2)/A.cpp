#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int main()
{
    int a[4], d;
    for (int i = 1; i <= 3; i++)
        scanf("%d", &a[i]);
    scanf("%d", &d);
    std::sort(a + 1, a + 4);
    int ans = 0;
    ans = cmax(0, a[1] + d - a[2])+ cmax(0, a[2] + d - a[3]);
    printf("%d\n", ans);
    return 0;
}
