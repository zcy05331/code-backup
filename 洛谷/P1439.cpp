#include <bits/stdc++.h>
const int MaxN = 100010;
int read()
{
    int x = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9')
        ch = getchar();
    while(ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}
int a[MaxN];
int id[MaxN];
int main()
{
    int n;
    scanf("%d", &n);
    memset(a, 0x3f, sizeof(a));
    for(int i = 1; i <= n; i++)
        id[read()] = i;
    for(int i = 1; i <= n; i++)
    {
        int x = id[read()];
        *std::lower_bound(a + 1, a + n + 1, x) = x;
    }
    printf("%d", std::lower_bound(a + 1, a + n + 1, a[0]) - a - 1);
    return 0;
}