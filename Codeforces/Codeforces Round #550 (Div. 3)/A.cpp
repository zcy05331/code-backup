#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define openfile(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)

int used[30];

inline int check(std::string s)
{
    memset(used, 0, sizeof(used));
    int len = s.size();
    if (len == 1)
        return true;
    std::sort(s.begin(), s.end());
    for (int i = 1; i < len; i++)
        if (s[i] != s[i - 1] + 1)
            return 0;
    return 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        std::string s;
        std::cin >> s;
        if (check(s))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
