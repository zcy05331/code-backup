#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

int n, odd, even;
char s[3010];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        odd = even = 0;
        scanf("%d%s", &n, s + 1);
        for (int i = 1; i <= n; i++)
        {
            if ((s[i] - '0') % 2 == 1)
                ++odd;
            else
                ++even;
        }
        if (even == n || (odd == 1 && n == 1))
        {
            puts("-1");
            continue;
        }
        else
        {
            int cnt = 0;
            if (odd == 1)
            {
                for (int i = 1; i <= n; i++)
                {
                    if (((s[i] - '0') % 2 == 1))
                        continue;
                    putchar(s[i]);
                }
            }
            else
            {
                for (int i = 1; i <= n; i++)
                {
                    if ((s[i] - '0') % 2 == 0)
                        continue;
                    else
                    {
                        if (((odd % 2) == 1) && cnt == odd - 1)
                            continue;
                        putchar(s[i]), ++cnt;
                    }
                }
            }
            puts("");
        }
    }
    return 0;
}
