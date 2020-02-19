#include <bits/stdc++.h>

#define ll long long

const int MaxN = 100010;

inline void read(int &x)
{
    register char ch = getchar();
    while(ch < '0' || ch > '9')
        ch = getchar();
    while(ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
}

int t[MaxN], l[MaxN], e[MaxN];

int main()
{
    int ans = 0;
    int n, L, a;
    scanf("%d%d%d", &n, &L, &a);
    for(int i = 1; i <= n; ++i)
        scanf("%d%d", &t[i], &l[i]), e[i] = t[i] + l[i];
    e[0] = 0, t[n + 1] = L;
    for(int i = 0; i <= n; i++)
    {
        ans += (t[i + 1] - e[i]) / a;
    }
    printf("%d", ans);
    return 0;
}