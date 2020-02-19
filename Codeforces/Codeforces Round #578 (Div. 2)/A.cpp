#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int n;
int ch[100];
std::string s;

int main()
{
    scanf("%d", &n);
    std::cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            int now = 0;
            for (int j = 1; j <= 10; j++)
            {
                if (ch[j] == 0)
                {
                    now = j;
                    break;
                }
            }
            ch[now] = 1;
        }
        else if (s[i] == 'R')
        {
            int now = 0;
            for (int j = 10; j >= 1; j--)
            {
                if (ch[j] == 0)
                {
                    now = j;
                    break;
                }
            }
            ch[now] = 1;
        }
        else
            ch[s[i] - '0' + 1] = 0;
    }
    for (int i = 1; i <= 10; i++)
        printf("%d", ch[i]);
    return 0;
}
