#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

int len, flag;
char ch[MaxN], a[MaxN], b[MaxN];

int main()
{
    scanf("%s", ch + 1), len = strlen(ch + 1);
    for (int i = len; i >= 1; i--)
    {
        if (ch[i] == 'Z' && ch[i + 1] != 'Z' && i != len)
            return 0 * printf("-1");
        if (ch[i] == 'Z')
            a[i] = 0, b[i] = 0;
        else if (ch[i] == 'X')
            a[i] = 2, b[i] = 1;
        else if (ch[i] == 'Y')
            a[i] = 1, b[i] = 2;
        a[i] += '0', b[i] += '0';
    }
    for (R int i = 1; i <= len; ++i)
        putchar(a[i]);
    puts("");
    for (R int i = 1; i <= len; ++i)
        putchar(b[i]);
    return 0;
}
