#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll base = 331;
const ll MaxN = 3e2 + 10;
const ll mod = 998244853;

ll n, m, max = -1;
std::vector<ll> ans;
char s[MaxN], t[MaxN];
std::vector<std::string> str;

int main()
{
    // freopen("uva760.in", "r", stdin);
    // freopen("uva760.out", "w", stdout);
    scanf("%s\n%s", s + 1, t + 1);
    while ("hgs ak ioi")
    {
        ans.clear(), str.clear(), max = -1;
        n = strlen(s + 1), m = strlen(t + 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int cnt = -1;
                for (int k = 0;; k++)
                {
                    if (i + k > n || j + k > m)
                        break;
                    if (s[i + k] != t[j + k])
                        break;
                    cnt = k;
                }
                if (cnt > max)
                    max = cnt, ans.clear(), ans.push_back(i);
                else if (cnt == max)
                    ans.push_back(i);
            }
        }
        if (ans.size() == 0)
            printf("No common sequences.\n");
        else
        {
            std::sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
            {
                if (i == 0 || ans[i] != ans[i - 1])
                {
                    std::string Str = "";
                    for (int j = 0; j <= max; j++)
                        Str += s[ans[i] + j];
                    str.push_back(Str);
                }
            }
            std::sort(str.begin(), str.end());
            for (int i = 0; i < str.size(); i++)
                if (i == 0 || str[i] != str[i - 1])
                    std::cout << str[i] << "\n";
            if (scanf("%s\n%s", s + 1, t + 1) == 2)
                puts("");
            else
                break;
        }
    }
    return 0;
}
