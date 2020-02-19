#include <bits/stdc++.h>
#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define openfile(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
int a, b;
int f[20][20], num[20];
inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}
inline void init()
{
    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 2; i <= 10; i++)
    {
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];
    }
}
inline int solve(int x)
{
    int len = 0, ans = 0;
    while (x)
        num[++len] = x % 10, x /= 10;
    for (int i = 1; i <= len - 1; i++)
        for (int j = 1; j <= 9; j++)
            ans += f[i][j];
    for (int i = 1; i < num[len]; i++)
        ans += f[len][i];
    for (int i = len - 1; i; i--)
    {
        for (int j = 0; j <= num[i] - 1; j++)
        {
            if (abs(num[i + 1] - j) >= 2)
                ans += f[i][j];
        }
        if (abs(num[i] - num[i + 1]) < 2)
            break;
    }
    return ans;
}
int main()
{
    a = read(), b = read();
    init();
    printf("%d", solve(b +1) - solve(a));
    return 0;
}
