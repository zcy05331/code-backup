#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)
const int MaxN = 1e5 + 10;
int n;
std::map<std::string, int> m;
std::string s[MaxN], t[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n), m.clear();
        for (int i = 1; i <= n; i++)
            std::cin >> s[i], t[i] = "";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 3; j++)
                t[i] += s[i][j];
            m[t[i]] = 1;
        }
        if (m.size() == n)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
