#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;
int n, m, q, op[MaxN], ans[MaxN];

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

int main()
{
    n = read(), m = read(), q = read();
    for (int i = 1; i <= m; i++)
        op[i] = read();
    if (m <= 2000 && q <= 2000)
    {
        while (q--)
        {
            int tp = read();
            if (tp == 1)
            {
                int s = read(), l = read(), r = read();
                for (int i = l; i <= r; i++)
                {
                    if (op[i] == 1)
                        s = 2 * s;
                    else if (op[i] == 2)
                        s = s * 2 + 1;
                    else if (op[i] == 3 && s != 1)
                        s = s / 2;
                }
                printf("%d\n", s);
            }
            else
            {
                int x = read(), y = read();
                op[x] = y;
            }
        }
    }
    else
    {
        int s = 1;
        for (int i = 1; i <= m; i++)
        {
            if (op[i] == 1)
                s = 2 * s;
            else if (op[i] == 2)
                s = s * 2 + 1;
            else if (op[i] == 3 && s != 1)
                s = s / 2;
            ans[i] = s;
        }
        while (q--)
        {
            int tp = read(), s = read(), l = read(), r = read();
            printf("%d\n", ans[r]);
        }
    }
    return 0;
}
