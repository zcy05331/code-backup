#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

int main()
{
    int n = 100;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1;; j++)
        {
            if ((j * (j + 1) / 2) % i == 0)
            {
                printf("%d %d\n", i, j);
                break;
            }
        }
    }
    return 0;
}
