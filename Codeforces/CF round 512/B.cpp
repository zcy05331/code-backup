#include <bits/stdc++.h>

const int MaxN = 100010;

int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    int s;
    scanf("%d", &s);
    for(int i = 1; i <= s; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if ((x < d && y < d && (x + y) < (d)) || (x > (n - d) && y > (n - d) && (2 * n - x - y) < d) || (x < (n - d) && y > d && (y - x) > d) || (x > d && (y < (n - d)) && (x - y) > d))
            puts("NO");
        else printf("YES\n");
    }
    return 0;
}