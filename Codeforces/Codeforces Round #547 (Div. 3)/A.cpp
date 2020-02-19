#include <bits/stdc++.h>
#define R register
#define ll long long
#define cmin(a, b) ((a < b) ? a : b)
#define cmax(a, b) ((a < b) ? b : a)

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (n == m)
        return 0 * printf("0");
    if (n > m || (m % n != 0))
        return 0 * printf("-1");
    m /= n;
    int ans = 0;
    while (m % 2 == 0)
        ++ans, m /= 2;
    if (m % 3 != 0 && m != 1)
        return 0 * printf("-1");
    while (m % 3 == 0)
        ++ans, m /= 3;
    if (m != 1)
        return 0 * printf("-1");
    printf("%d\n", ans);
    return 0;
}
