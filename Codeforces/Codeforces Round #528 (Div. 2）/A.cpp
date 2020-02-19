#include <bits/stdc++.h>

int main()
{
    std::string s, t;
    std::cin >> s;
    int len = s.length();
    int cnt = 0;
    for(int i = 0; i < len; i++)
    {
        t = t + s[((len + 1) / 2 + cnt) - 1];
        if(i % 2 == 0)
            cnt = -cnt, ++cnt;
        else cnt = -cnt;
    }
    std::cout << t;
    return 0;
}