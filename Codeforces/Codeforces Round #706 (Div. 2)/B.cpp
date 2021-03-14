#include <bits/stdc++.h>

#define R register
#define ll long long
#define It std::map<int, int>::iterator
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 1e5 + 10;

std::map<int, int> mp;
int n, k, mex, max, zero, a[MaxN];

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

signed main()
{
    int T = read();
    while (T--)
    {
        zero = mex = max = 0, mp.clear();
        n = read(), k = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read(), mp[a[i]] = 1;
            if (!a[i]) zero = 1;
            max = std::max(max, a[i]);
        }
        if (k == 0)
        {
            printf("%d\n", n);
            continue;
        }
        if (!zero)
        {
            mp[(n + 1) / 2] = 1;
            int ans = 0;
            for (It it = mp.begin(); it != mp.end(); it++)
                ans += it->second;
            printf("%d\n", ans);
            continue;
        }
        while (mp[mex])
            ++mex;
        int lstmex = -1, lstmax = -1, cnt = 0, now = 0, flag = 0;
        while (lstmex != mex && lstmax != max && cnt < k)
        {
            lstmex = mex, lstmax = max, ++cnt;
            now = (mex + max + 1) / 2;
            max = std::max(max, now), mp[now] = 1;
            while (mp[mex])
                ++mex;
            if (mex == max + 1)
            {
                flag = 1;
                break;
            }
        }
        int ans = 0;
        if (flag) ans += k - cnt;
        for (It it = mp.begin(); it != mp.end(); it++)
            ans += it->second;
        printf("%d\n", ans);
    }
    return 0;
}