#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

int calc(int a, int b, int c)
{
    int ans = 0, tmp = 0;
    tmp = std::min(a, b / 2), ans += tmp * 3, b -= tmp * 2;
    tmp = std::min(b, c / 2), ans += tmp * 3, c -= tmp * 2;
    return ans;
}

int calc1(int a, int b, int c)
{
    int ans = 0, tmp = 0;
    tmp = std::min(b, c / 2), ans += tmp * 3, b -= tmp;
    tmp = std::min(a, b / 2), ans += tmp * 3, b -= tmp * 2;
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int a, b, c;
        int ans = 0, tmp = 0;
        scanf("%d%d%d", &a, &b, &c);
        ans = std::max(calc(a, b, c), calc1(a, b, c));

        printf("%d\n", ans);
    }
    return 0;
}
