#include <bits/stdc++.h>

int main()
{
    int n;
    int ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ans = std::max(ans, x + y);
    }
    printf("%d\n", ans);
    return 0;
}