#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e4 + 10;

std::string s;
int n;
std::pair<std::string, int> a[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        std::cin >> n >> s;
        for (int i = 1; i <= n; i++)
        {
            std::string tmp = "";
            int id = i, find = (((n - i) % 2) ? 0 : (i - 1));
            for (int j = 0; j < n; j++)
            {
                if (j + i - 1 >= n)
                {
                    if((n - i) % 2)
                        tmp += s[find], find++;
                    else --find, tmp += s[find];
                }
                else
                    tmp += s[j + i - 1];
            }
            a[i] = std::make_pair(tmp, id);
        }
        std::sort(a + 1, a + n + 1);
        std::cout << a[1].first << "\n" << a[1].second << "\n";
    }
    return 0;
}
