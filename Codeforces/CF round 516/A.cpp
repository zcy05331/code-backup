# include <bits/stdc++.h>

int main()
{
    int a[3];
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    std::sort(a, a + 3);
    int ans = std::max(a[2] + 1 - a[0] - a[1], 0);
    printf("%d\n", ans);
    return 0;
}