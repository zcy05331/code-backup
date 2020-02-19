#include <bits/stdc++.h>

using std::string;

const int MaxN = 100010;

int a[MaxN];
int l[MaxN], r[MaxN];

int main()
{
    int n;
    string s;
    scanf("%d", &n);
    std::cin >> s;
    int len = s.length();
    int sum = 0, ans = 0;
    for (int i = 0; i < len; i++)
        a[i + 1] = s[i] == 'S' ? 0 : 1, sum += a[i + 1];
    if (sum == 0)
        return printf("0") * 0;
    if (sum == n)
        return printf("%d\n", n) * 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1 && a[i - 1] == 1)
            l[i] = l[i - 1];
        else
            l[i] = i;
    }
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 1 && a[i + 1] == 1)
            r[i] = r[i + 1];
        else
            r[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            int tmp = 0;
            if (a[i - 1])
                tmp += r[i - 1] - l[i - 1] + 1;
            if (a[i + 1])
                tmp += r[i + 1] - l[i + 1] + 1;
            if(tmp == sum)
                ans = std::max(ans, tmp);
            if (tmp < sum)
                ans = std::max(ans, tmp + 1);
            if (a[i - 1] && r[i - 1] - l[i - 1] + 1 < sum)
                ans = std::max(r[i - 1] - l[i - 1] + 2, ans);
            if (a[i + 1] && r[i + 1] - l[i + 1] + 1 < sum)
                ans = std::max(r[i + 1] - l[i + 1] + 2, ans);
            
        }
    }
    printf("%d\n", ans);
    return 0;
}