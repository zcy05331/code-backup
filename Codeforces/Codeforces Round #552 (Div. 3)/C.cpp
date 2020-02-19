#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
ll a, b, c;
ll solve(int n)
{
    ll ans = 0;
    ll x = a, y = b, z = c;
    for (int i = n; i <= 7; i++)
    {
        if (i == 1 || i == 4 || i == 7)
        {
            if (x == 0)
                return ans;
            --x, ++ans;
        }
        else if (i == 2 || i == 6)
        {
            if (y == 0)
                return ans;
            --y, ++ans;
        }
        else if (i == 3 || i == 5)
        {
            if (z == 0)
                return ans;
            --z, ++ans;
        }
    }
    ll cnt = cmin(cmin((x / 3), (y / 2)), (z / 2));
    ans += cnt * 7;
    x -= 3 * cnt, y -= cnt * 2, z -= 2 * cnt;
    for (int j = 1; j <= 100; j++)
    {
        for (int i = 1; i <= 7; i++)
        {
            if (i == 1 || i == 4 || i == 7)
            {
                if (x == 0)
                    return ans;
                --x, ++ans;
            }
            else if (i == 2 || i == 6)
            {
                if (y == 0)
                    return ans;
                --y, ++ans;
            }
            else if (i == 3 || i == 5)
            {
                if (z == 0)
                    return ans;
                --z, ++ans;
            }
        }
    }
}
int main()
{
    scanf("%I64d%I64d%I64d", &a, &b, &c);
    ll ans = 0;
    for (int i = 1; i <= 7; i++)
    {
        ll cnt = solve(i);
        //printf("%I64d\n", cnt);
        ans = cmax(cnt, ans);
    }
    printf("%I64d\n", ans);
    return 0;
}
