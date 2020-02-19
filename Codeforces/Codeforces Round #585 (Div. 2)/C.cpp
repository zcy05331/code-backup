#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 3e5 + 10;

int n;
char a[MaxN], b[MaxN];
std::vector<int> x, y;

int main()
{
    scanf("%d", &n);
    scanf("%s%s", a + 1, b + 1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 'a' && b[i] == 'b')
            x.push_back(i);
        else if (a[i] == 'b' && b[i] == 'a')
            y.push_back(i);
    }
    if ((x.size() + y.size()) & 1)
        return 0 * puts("-1");
    printf("%d\n", (x.size() + y.size()) / 2 + (x.size() & 1));
    if (x.size() & 1)
    {
        printf("%d %d\n", x.back(), x.back());
        y.push_back(x.back()), x.pop_back();
    }
    for (int i = 0; i < x.size(); i += 2)
        printf("%d %d\n", x[i], x[i + 1]);
    for (int i = 0; i < y.size(); i += 2)
        printf("%d %d\n", y[i], y[i + 1]);
    return 0;
}
