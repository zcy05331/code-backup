#include <bits/stdc++.h>

int main()
{
    int n, k, len = 0;
    std::string s;
    scanf("%d%d", &n, &k);
    std::cin >> s;
    for(int i = 1; i < n ; i++)
    {
        int flag = 1;
        for(int j = 0; j < n - i; j++)
        {
            if(s[j] != s[i + j])
                flag = 0;
        }
        if(flag)
        {
            len = i;
            break;
        }
            
    }
    //printf("%d\n",len);
    if(len)
    {
        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j < len; j++)
            {
                putchar(s[j]);
            }
        }
        for (int i = len; i < n; i++)
            putchar(s[i]);
    }
    else
    {
        for(int i = 1; i <= k; i++)std::cout << s;
    }
    return 0;
}
