#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

std::map<int, int> m1, m2;
int n, cnt, l[MaxN], r[MaxN], a[MaxN], s[MaxN];

inline void prework()
{
    m1.clear(), m2.clear();
    for (int i = 1; i <= n; i++)
        m1[l[i]] = m1[r[i]] = 1;
    cnt = 0;
    for (std::map<int, int>::iterator it = m1.begin(); it != m1.end(); it++)
        m2[it->first] = ++cnt;
    for (int i = 1; i <= n; i++)
        l[i] = m2[l[i]] * 2 - 1, r[i] = m2[r[i]] * 2 - 1;
}

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

int main()
{
    int T = read();
    while (T--)
    {
        n = read(), cnt = 0;
        for (int i = 1; i <= n; i++)
            l[i] = read(), r[i] = read();
        prework(), cnt = cnt * 2 - 1;
        for (int i = 1; i <= n; i++)
            a[l[i]]++, a[r[i] + 1]--;
        for (int i = 1; i <= cnt; i++)
            a[i] += a[i - 1];
        int num = 0, ans = -1000000;
        for (int i = 1; i <= cnt; i++)
        {
            s[i] = s[i - 1];
            num += (a[i] && !a[i - 1]);
            if (a[i] > 1 && a[i - 1] <= 1)
                ++s[i];
        }
        for (int i = 1; i <= n; i++)
        {
            int cur = s[r[i]] - s[l[i] - 1] + ((a[l[i]] > 1) && (a[l[i] - 1] > 1)) - 1;
            ans = std::max(ans, cur);
        }
        printf("%d\n", num + ans);
        for (int i = 0; i <= cnt * 2; i++)
            a[i] = s[i] = 0;
    }
    return 0;
}
