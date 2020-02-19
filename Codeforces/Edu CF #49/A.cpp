#include <bits/stdc++.h>

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        std::string s;
        std::cin >> s;
        int flag = 1; 
        for(int i = 1 - 1; i <= n / 2 - 1; i++)
        {
            if (abs(s[i] - s[n - i - 1]) == 2 || abs(s[i] - s[n - i - 1]) == 0)
                continue;
            else flag = 0;
        }
        if(flag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}