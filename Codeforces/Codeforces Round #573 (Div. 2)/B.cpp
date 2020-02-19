#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

inline int cmp(std::string a, std::string b)
{
    if (a[1] != b[1])
        return a[1] < b[1];
    return a[0] < b[0];
}

int main()
{
    std::string a[4];
    std::cin >> a[1] >> a[2] >> a[3];
    std::sort(a + 1, a + 4, cmp);
    if (a[1] == a[2] && a[2] == a[3])
        return 0 * printf("0");
    else if ((a[1][0] == (a[2][0] - 1) && a[1][1] == a[2][1]) && (a[2][0] == (a[3][0] - 1) && a[2][1] == a[3][1]))
        return 0 * printf("0");
    if ((a[1] == a[2]) || (a[2] == a[3]))
        return 0 * printf("1");
    for (int i = 1; i <= 2; i++)
    {
        if ((a[i][0] == (a[i + 1][0] - 1)) && a[i][1] == a[i + 1][1])
            return 0 * printf("1");
    }
    for (int i = 1; i <= 2; i++)
    {
        if ((a[i][0] == (a[i + 1][0] - 2)) && a[i][1] == a[i + 1][1])
            return 0 * printf("1");
    }
    printf("2");
    return 0;
}
