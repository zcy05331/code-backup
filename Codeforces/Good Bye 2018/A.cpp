# include <bits/stdc++.h>

int main()
{
    int y, b, r;
    scanf("%d%d%d", &y, &b, &r);
    int ans = std::min(std::min(y, b - 1), r - 2);
    printf("%d\n", ans * 3 + 3);
    return 0;
}