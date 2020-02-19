#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

int n, m, pos = 0, vis[1000];
std::string ans, s[1000], inv[1000];
std::vector<std::string> vec[2];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        std::cin >> s[i];
    for (int i = 1; i <= n; i++)
        inv[i] = s[i], std::reverse(inv[i].begin(), inv[i].end());
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        if (!pos && s[i] == inv[i])
            pos = i;
        else
        {
            int flag = 0;
            for (int j = i + 1; j <= n; j++)
                if (inv[i] == s[j])
                    flag = j;
            if (flag)
            {
                vis[i] = vis[flag] = 1;
                vec[0].push_back(s[i]);
                vec[1].push_back(s[flag]);
            }
        }
    }
    for (int i = 0; i < vec[0].size(); i++)
        ans += vec[0][i];
    if (pos)
        ans += s[pos];
    for (int i = vec[1].size() - 1; ~i; --i)
        ans += vec[1][i];
    printf("%d\n", ans.size());
    std::cout << ans;
    return 0;
}
