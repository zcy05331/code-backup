#include <bits/stdc++.h>

#define R register
#define ll long long
#define lowbit(x) (x & (-(x)))
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e3 + 10;

int n, k;
int a[MaxN][MaxN], c[MaxN][MaxN];
std::string s;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> s;
        for (int j = 0; j < n; j++)
            a[i][j + 1] = ((s[j] == 'W') ? 1 : 0);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = c[i][j - 1] + a[i][j];
    for (int i = 1; i <= n - k + 1; i++)
    {
        for (int j = 1; j <= n - k + 1; j++)
        {
            
        }
    }
    return 0;
}
