#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

inline int work()
{
    std::string s;
    std::cin >> s;
    int n = s.length();
    for (int i = 1; i < n; i++)
    {
        if (s[i] != '?' && s[i - 1] != '?' && s[i] == s[i - 1])
            return printf("-1\n");
    }
    if (s[0] == '?')
    {
        if (s[1] == '?')
            s[0] = 'a';
        else
            s[0] = ((s[1] - 'a') + 1) % 3 + 'a';
    }
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '?')
        {
            int a[3] = {};
            a[s[i - 1] - 'a'] = a[s[i + 1] - 'a'] = 1;
            for (int j = 0; j < 3; j++)
                if (!a[j])
                    s[i] = j + 'a';
        }
    }
    std::cout << s << "\n";
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        work();
    return 0;
}
