#include <bits/stdc++.h>
const int MaxN = 100010;
int f[MaxN];
int sc[MaxN], st[MaxN];
int main()
{
    int n, s;
    int t, c;
    scanf("%d%d", &n, &s);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &t, &c), sc[i] = sc[i - 1] + c, st[i] = st[i - 1] + t;
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < i; j++)
            f[i] = std::min(f[i], f[j] + st[i] * (sc[i] - sc[j]) + s * (sc[n] - sc[j]));
    printf("%d", f[n]);
    return 0;
}