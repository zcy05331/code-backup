#include <bits/stdc++.h>
std::string s;
int main()
{
    freopen("cpp.out", "w", stdout);
    while (std::getline(std::cin, s))
    {
        s = "\"" + s + "\"";
        std::cout << s + ","
                  << "\n";
    }
    return 0;
}
