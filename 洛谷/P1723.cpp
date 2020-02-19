#include <bits/stdc++.h>
using namespace std;
const int N = 1100000;
char s[N], str[3 * N + 5];
int n, p[3 * N + 5], ans;
void init()
{
    str[0] = '#';
    str[1] = '#';
    for (int i = 0; i < n; i++)
        str[(i << 1) + 2] = s[i], str[(i << 1) + 3] = '#';
    n = (n << 1) + 2;
    str[n] = 0;
}
void manacher()
{
    int mx = 0, id = 0;
    for (int i = 0; i < n; i++)
    {
        if (mx > i)
            p[i] = min(p[2 * id - i], mx - i);
        else
            p[i] = 1;
        while (i - p[i] >= 0 && str[i + p[i]] == str[i - p[i]])
            p[i]++;
        if (p[i] + i > mx)
            mx = p[i] + i, id = i;
    }
}
int main()
{
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(p, 0, sizeof(p)), memset(str, 0, sizeof(str));
        std::cin >> s;
        n = strlen(s);
        init();
        manacher();
        ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, p[i]);
        printf("%d\n", ans - 1);
    }
    return 0;
}
