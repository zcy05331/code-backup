#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
const int MaxN = 2e5 + 10;
int n;
std::string s;
int a[MaxN], f[20], b[MaxN];
int main()
{
    scanf("%d", &n);
    std::cin >> s;
    for (int i = 0; i < n; i++)
        a[i + 1] = s[i] - '0', b[i + 1] = a[i + 1];
    for (int i = 1; i <= 9; i++)
        scanf("%d", &f[i]);
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == f[a[i]])
            continue;
        if (a[i] > f[a[i]])
        {
            if (tmp == 0)
                continue;
            else
                break;
        }
        tmp = 1;
        b[i] = f[a[i]];
    }
    for (int i = 1; i <= n; i++)
        printf("%d", b[i]);
    return 0;
}
