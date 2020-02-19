#include <bits/stdc++.h>

const int MaxN = 110;

int n;
int a[MaxN];
int s[MaxN];


int main()
{
    scanf("%d", &n);
    std::string str;
    std::cin >> str;
    for(int i = 1; i <= n; i++)
        a[i] = str[i - 1] - '0', s[i] = s[i - 1] + a[i];
    while(str[n - 1] == '0')
        n--;
    if(!s[n])
        return 0 * printf("YES");
    for(int i = 1; i < n; i++)
    {
        int flag = 1;
        for (int j = i + 1; j <= n; j++)
        {
            int pos = j - 1;
            while (j <= n && s[j] - s[pos] < s[i])
                j++;
            if (j > n || s[j] - s[pos] != s[i])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            return 0 * puts("YES");
    }   
    puts("NO");
    return 0;
}