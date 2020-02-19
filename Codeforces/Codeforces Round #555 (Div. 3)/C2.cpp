#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
const int MaxN = 200010;
int n;
int a[MaxN];
std::vector<char> vec;
int main()
{
    scanf("%d", &n);
    int l = 1, r = n, now = -1;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    while (l <= r)
    {
        if (a[l] <= now && a[r] <= now)
            break;
        else if (a[l] <= now)
            vec.push_back('R'), now = a[r], --r;
        else
        {
            if (a[r] <= now)
                vec.push_back('L'), now = a[l], ++l;
            else
            {
                if (a[l] < a[r])
                    vec.push_back('L'), now = a[l], ++l;
                else if (a[l] > a[r])
                    vec.push_back('R'), now = a[r], --r;
                else if (a[l] == a[r])
                {
                    int tmp = 1, tmp2 = 1;
                    for (int i = l + 1; i <= r - 1; i++)
                    {
                        if (a[i] <= a[i - 1])
                            break;
                        ++tmp;
                    }
                    for (int i = r - 1; i >= l + 1; i--)
                    {
                        if (a[i] <= a[i + 1])
                            break;
                        ++tmp2;
                    }
                    if (tmp < tmp2)
                    {
                        for (int i = 1; i <= tmp2; i++)
                            vec.push_back('R');
                            break;
                    }
                    else
                    {
                        for (int i = 1; i <= tmp; i++)
                            vec.push_back('L');
                            break;
                    }
                }
            }
        }
    }
    printf("%d\n", vec.size());
    for (int i = 0; i < vec.size(); i++)
        printf("%c", vec[i]);
    return 0;
}
