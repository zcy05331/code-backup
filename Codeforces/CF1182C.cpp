#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define mp(i, j) std::make_pair(i, j)
#define check(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')

const int MaxN = 1e5 + 10;

struct node
{
    char ch;
    int last, 
};

int n;
std::string s[MaxN];
std::pair<int, int> p[MaxN];
int len[MaxN], cnt[MaxN], last[MaxN], used[MaxN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> s[i];
        len[i] = s[i].length();
        for (int j = 0; j < len[i]; j++)
        {
            if (check(s[i][j]))
                last[i] = j, ++cnt[i];
        }
        p[i] = mp(cnt[i], last[i]);
    }
    std::sort(p + 1, p + n + 1);
    for (int i = 2; i <= n; i++)
    {
        if (used[i - 1])
            continue;
    }
    return 0;
}
