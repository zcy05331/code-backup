#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

std::map<int, int> m;

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
    int T = read();
    while (T--)
    {
        m.clear();
        int n = read(), s = read(), k = read(), l = s, r = s, ans = 0x3f3f3f3f;
        for (int i = 1; i <= k; i++)
        {
            int x = read();
            m[x] = 1;
        }
        while (l >= 1)
        {
            if (!m[l])
            {
                ans = std::min(ans, s - l);
                break;
            }
            l--;
        }
        while (r <= n)
        {
            if (!m[r])
            {
                ans = std::min(ans, r - s);
                break;
            }
            r++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
