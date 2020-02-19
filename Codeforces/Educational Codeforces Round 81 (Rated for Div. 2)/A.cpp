#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        if (n % 2 == 0)
        {
            for (int i = 1; i <= n / 2; i++)
                printf("1");
            puts("");
        }
        else
        {
            putchar('7');
            for (int i = 2; i <= n / 2; i++)
                printf("1");
            puts("");
        }
    }
    return 0;
}
