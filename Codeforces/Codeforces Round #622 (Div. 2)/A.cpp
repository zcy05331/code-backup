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
        int a, b, c, ans = 0;
        scanf("%d%d%d", &a, &b, &c);
        if (a)
            --a, ++ans;
        if (b)
            --b, ++ans;
        if (c)
            --c, ++ans;
        if (a && b)
            --a, --b, ++ans;
        if (a && c)
            --a, --c, ++ans;
        if (b && c)
            --b, --c, ++ans;
        if (a && b && c)
            --a, --b, --c, ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
