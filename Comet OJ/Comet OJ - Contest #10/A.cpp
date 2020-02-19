#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const std::string str = "ytpca";

int main()
{
    int n, len, ans = 0;
    std::string s;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int flag = 1;
        std::cin >> s;
        len = s.length();
        for (int j = len - 1; j > len - 6; j--)
        {
            if (s[j] != str[(len - 1) - j])
                flag = 0;
        }
        ans += flag;
    }
    printf("%d\n", ans);
    return 0;
}
