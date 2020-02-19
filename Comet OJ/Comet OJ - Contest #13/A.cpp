#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

int main()
{
    std::string s;
    int len, ans = 0;
    std::cin >> len >> s;
    for (int i = 0; i < len; i++)
        if (s[i] == 'G')
            ++ans;
    printf("%d\n", ans);
    return 0;
}
