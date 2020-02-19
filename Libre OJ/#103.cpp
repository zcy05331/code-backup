#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e6 + 10;

std::string s, t;
int n, m, ans, next[MaxN], f[MaxN];

int main()
{
    std::cin >> s >> t;
    std::swap(s, t);
    s = ' ' + s, t = ' ' + t;
    n = s.length() - 1, m = t.length() - 1;
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && s[i] != s[j + 1])
            j = next[j];
        if (s[i] == s[j + 1])
            ++j;
        next[i] = j;
    }
    for(int i = 1, j = 0; i <= m; i++)
    {
        while(j && (j == n || t[i] != s[j + 1]))
            j = next[j];
        if(t[i] == s[j + 1])
            j++;
        f[i] = j;
        if(f[i] == n)
            ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
