#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int ref[] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

int h, m, a, b, flag;

int check(int a, int b)
{
    int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
    a1 = ref[b % 10], a2 = ref[b / 10], b1 = ref[a % 10], b2 = ref[a / 10];
    if (a1 == -1 || a2 == -1 || b1 == -1 || b2 == -1) return 0;
    a1 = a1 * 10 + a2, b1 = b1 * 10 + b2;
    // meow("%d %d %d %d\n", a, b, a1, b1);
    if (a1 >= h || b1 >= m) return 0;
    return 1;
}

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

void add()
{
    ++b;
    if (b >= m)
    {
        ++a, b = 0;
        if (a >= h) a = 0;
    }
}

signed main()
{
    int T = read();
    while (T--)
    {
        flag = 0;
        h = read(), m = read(), a = read(), b = read();
        if (check(a, b))
        {
            if (a < 9)
                printf("0%d", a);
            else
                printf("%d", a);
            printf(":");
            if (b < 9)
                printf("0%d", b);
            else
                printf("%d", b);
            puts("");
            continue;
        }
        while (1)
        {
            if (check(a, b))
            {
                if (a < 9)
                    printf("0%d", a);
                else
                    printf("%d", a);
                printf(":");
                if (b < 9)
                    printf("0%d", b);
                else
                    printf("%d", b);
                puts("");
                break;
            }
            add();
        }
    }
    return 0;
}