#include <bits/stdc++.h>

int m[10];

int check(std::string s)
{
    if(s == "A")
        return 1;
    if(s == "B")
        return 2;
    if (s == "C")
        return 3;
    if (s == "AB")
        return 4;
    if(s == "BC")
        return 5;
    if(s == "AC")
        return 6;
    return 7;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= 9; i++)
        m[i] = 100000000;
    for(int i = 1; i <= n; i++)
    {
        int p;
        std::string s;
        scanf("%d", &p);
        std::cin >> s;
        if(s.size() == 3)
            s = "ABC";
        else if(s.size() == 2)
        {
            if(s[0] > s[1])
                std::swap(s[0], s[1]);
        }
        m[check(s)] = std::min(m[check(s)], p);
    }
    int ans = m[7];
    ans = std::min(ans, m[1] + m[2] + m[3]);
    ans = std::min(ans, m[1] + m[5]);
    ans = std::min(ans, m[2] + m[6]);
    ans = std::min(ans, m[3] + m[4]);
    ans = std::min(ans, m[4] + m[5]);
    ans = std::min(ans, m[5] + m[6]);
    ans = std::min(ans, m[4] + m[6]);
    if(ans >= 100000000)
        printf("-1");
    else
        printf("%d\n", ans);
    return 0;
}