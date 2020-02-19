#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e7 + 10;
int n, A, B, C, a[MaxN];

inline void init()
{
    scanf("%d%d%d%d%d", &n, &A, &B, &C, &a[1]);
    for (int i = 2; i <= n; i++)
        a[i] = ((long long)a[i - 1] * A + B) % 100000001;
    for (int i = 1; i <= n; i++)
        a[i] = a[i] % C + 1;
}

int main()
{   
    init();
    long double ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int j = ((i == n) ? 1 : (i + 1));
        ans += 1.0 / (1.0 * std::max(a[i], a[j]));
    }
    printf("%0.3Lf", ans);
    return 0;
}
