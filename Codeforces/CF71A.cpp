#include <bits/stdc++.h>

int main()
{
    std::string s;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> s;
        int len = s.length();
        if (len > 10)
            printf("%c%d%c\n", s[0], len - 2, s[len - 1]);
        else
            std::cout << s << std::endl;
    }
    return 0;
}