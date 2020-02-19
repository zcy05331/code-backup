#include <bits/stdc++.h>

int si,co;

int main()
{
    char c;
    while(std::cin >> c)
    {
        if(c == 's')si++;
        else if(c == 'c')co++;
    }
    printf("%d", std::min(co, si));
    return 0;
}