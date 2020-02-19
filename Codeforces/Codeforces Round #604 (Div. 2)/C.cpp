#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 4e5 + 10;

int n, a[MaxN], p[MaxN << 2];

inline int work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), p[a[i]] = 0;
    for (int i = 1; i <= n; i++)
        p[a[i]]++;
    int g = p[a[1]], s = 0, b = 0, now = 1;
    while (a[now] == a[1])
        ++now;
    if ((n / 2) - now + 1 < 2 * g + 2)
        return printf("0 0 0\n");
    while (s <= g && now <= n)
    {
        int last = now;
        s += p[a[now]];
        while (a[last] == a[now])
            ++now;
    }
    if (g + s > (n / 2))
        return printf("0 0 0\n");
    while (b <= g && now <= n)
    {
        int last = now;
        b += p[a[now]];
        while (a[last] == a[now])
            ++now;
    }
    if ((b <= g) || (s <= g))
        return printf("0 0 0\n");
    if ((n / 2) < (g + s + b))
        return printf("0 0 0\n");
    while (now <= n && (b + s + g) < (n / 2))
    {
        int last = now;
        if ((p[a[now]] + (b + s + g)) <= (n / 2))
        {
            b += p[a[now]];
            while (a[last] == a[now])
                ++now;
        }
        else
            break;
    }
    printf("%d %d %d\n", g, s, b);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)

        work();

    return 0;
}
