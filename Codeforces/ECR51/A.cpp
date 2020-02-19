#include <bits/stdc++.h>
#define islower(x) bool(x <= 'z' && x >= 'a')
#define isupper(x) bool(x <= 'Z' && x >= 'A')
#define isnum(x) bool(x <= '9' && x >= '0')
std::vector<int> vec;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        std::string s;
        std::cin >> s;
        int ok[3] = {};
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                ok[0]++;
            else if (s[i] >= 'a' && s[i] <= 'z')
                ok[1]++;
            else if (s[i] >= 'A' && s[i] <= 'Z')
                ok[2]++;
        }
        if (ok[0] && ok[1] && ok[2])
        {
            std::cout << s << "\n";
            continue;
        }
        else if (bool(ok[0] >= 1) + bool(ok[1] >= 1) + bool(ok[2] >= 1) == 2)
        {
            if (!ok[0])
                for (int i = 0; i < len; i++)
                {
                    if (ok[1] > ok[2] ? islower(s[i]) : isupper(s[i]))
                    {
                        s[i] = '0';
                        break;
                    }
                }

            else if (!ok[1])
                for (int i = 0; i < len; i++)
                {
                    if(ok[0] > ok[2] ? isnum(s[i]) : isupper(s[i]))
                    {
                        s[i] = 'a';
                        break;
                    }
                }
                    
            else if (!ok[2])
                for (int i = 0; i < len; i++)
                {
                    if (ok[0] > ok[1] ? isnum(s[i]) : islower(s[i]))
                    {
                        s[i] = 'A';
                        break;
                    }
                }
            std::cout << s << "\n";
            continue;
        }
        if(!ok[0] && !ok[1])
            s[0] = '0', s[1] = 'a';
        else if(!ok[0] && !ok[2])
            s[0] = '0', s[1] = 'A';
        else if(!ok[1] && !ok[2])
            s[0] = 'a', s[1] = 'A';
        std::cout << s << "\n";
    }
    return 0;
}