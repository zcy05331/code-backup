#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int main()
{
    int n, pos = 0, min = 5;
    std::cin >> n;
    int a[5];
    for (int i = 0; i <= 2; i++)
    {
        if ((n + i) % 4 == 1)
            a[i] = 1;
        if ((n + i) % 4 == 2)
            a[i] = 3;
        if ((n + i) % 4 == 3)
            a[i] = 2;
        if ((n + i) % 4 == 0)
            a[i] = 4;
    }
    for (int i = 0; i <= 2; i++)
        if (a[i] < min)
            min = a[i], pos = i;
    printf("%d %c", pos, min + 'A' - 1);
    return 0;
}
