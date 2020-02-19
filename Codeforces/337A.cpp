#include <bits/stdc++.h>

const int Max = 1010;

int n, m;
int a[Max];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    std::sort(a + 1, a + m + 1);
    int ans = 0x7f7f7f7f;
    for(int i = 1; i <= m - n + 1; i++)
        ans = std::min(ans, a[n + i - 1] - a[i]);
    printf("%d\n", ans);
    return 0;
}