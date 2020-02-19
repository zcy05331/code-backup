#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int main()
{
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    if (x > y + z)
        return 0 * printf("+");
    if (y > x + z)
        return 0 * printf("-");
    if (x == y && z == 0)
        return 0 * printf("0");
    if ((x <= y + z) || (y <= x + z))
        return 0 * printf("?");
    return 0;
}
