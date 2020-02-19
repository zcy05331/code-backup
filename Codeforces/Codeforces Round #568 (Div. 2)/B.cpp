#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        std::string s, t;
        std::cin >> s >> t;
        s += '#';
        int lens = s.length(), lent = t.length();
        int pos = 0, flag = 1;
        int cnt = 0;
        for (int i = 0; i < lens; i++)
        {
            if (s[i] != s[i - 1])
            {
                int tot = 0;
                while (t[pos] == s[i - 1] && pos < lent)
                    ++tot, ++pos;
                if (tot < cnt)
                {
                    flag = 0;
                    break;
                }
                cnt = 1;
            }
            else
                cnt++;
        }
        if (pos != lent)
            flag = 0;
        if (flag == 0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
