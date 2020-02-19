#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e3 + 10;

std::string op[MaxN];
int n, m, k, tot, cnt[MaxN];

void print()
{
    printf("YES\n%d\n", tot);
    for (int i = 1; i <= tot; i++)
        std::cout << cnt[i] << " " << op[i] << "\n";
    exit(0);
}

void push(int x, std::string str)
{
    if (!x)
        return;
    k -= x * str.size(), ++tot;
    cnt[tot] = x, op[tot] = str;
    if (!k)
        print();
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    if (k > (4 * n * m - 2 * n - 2 * m))
        return 0 * printf("NO");
    if (n == 1)
    {
        push(std::min(k, m - 1), "R");
        push(std::min(k, m - 1), "L");
        return 0;
    }
    else if (m == 1)
    {
        push(std::min(k, n - 1), "D");
        push(std::min(k, n - 1), "U");
        return 0;
    }
    push(std::min(m - 1, k), "R"), push(std::min(n - 1, k), "D");
    push(std::min(n - 1, k), "U"), push(1, "L");
    for (int i = m - 1; i; i--)
    {
        int tmp = std::min(n - 1, k / 3);
        push(tmp, "DRL");
        if (k < 3 && tmp < n - 1)
            push(1, "D"), push(1, "R");
        push(std::min(n - 1, k), "U"), push(1, "L");
    }
    return 0;
}
