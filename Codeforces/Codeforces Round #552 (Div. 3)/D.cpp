#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define pa std::pair<int, int>

const int MaxN = 200010;

int s[MaxN];
int n, a, b, c, d;

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    c = a, d = b;
    for (int i = 1; i <= n; i++)
        scanf("%d", &s[i]);
    for (int i = 1; i <= n; i++)
    {
        if (a == 0 && b == 0)
            return 0 * printf("%d\n", i - 1);
        else if (a == 0 && b > 0)
            --b;
        else if (a > 0 && b == 0)
        {
            if (s[i] == 1)
                --a, b = cmin(b + 1, d);
            else
                --a;
        }
        else if (a > 0 && b > 0)
        {
            if (s[i] == 1)
            {
                if (b < d)
                    --a, b = cmin(b + 1, d);
                else
                    --b;
            }
            else
                --b;
        }
    }
    printf("%d\n", n);
    return 0;
}
