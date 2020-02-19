#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int main()
{   
    int a[5];
    for(int i = 1; i <= 4; i++)
        scanf("%d", &a[i]);
    std::sort(a + 1, a + 4 + 1);
    printf("%d %d %d\n", a[4] - a[1], a[4] - a[2], a[4] - a[3]);
    return 0;
}
