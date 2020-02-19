#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

int n, ans, now, flag;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = flag = now = n = 0;
        std::string s;
        std::vector<int> vec[27];
        std::cin >> s, n = s.size();
        for (int i = 0; i < n; i++)
            vec[s[i] - 'a'].push_back(i + 1);
        std::cin >> s, n = s.size();
        for (int i = 0; i < n; i++)
            if (vec[s[i] - 'a'].size() == 0)
                flag = 1;
        if (flag)
        {
            puts("-1");
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            auto it = std::lower_bound(vec[s[i] - 'a'].begin(), vec[s[i] - 'a'].end(), now + 1);
            if (it == vec[s[i] - 'a'].end())
                ans++, it = std::lower_bound(vec[s[i] - 'a'].begin(), vec[s[i] - 'a'].end(), 1);
            now = *it;
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}
