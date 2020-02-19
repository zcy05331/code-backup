#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 3e5 + 10;

int n;
char s[MaxN];

int main()
{
    scanf("%d", &n), scanf("%s", s + 1);
    int d = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (s[i] == '?')
            d += 9;
        else
            d += (s[i] - '0') * 2;
    }
    for (int i = (n / 2) + 1; i <= n; i++)
    {
        if (s[i] == '?')
            d -= 9;
        else
            d -= (s[i] - '0') * 2;
    }
    printf(d ? "Monocarp" : "Bicarp");
    return 0;
}
