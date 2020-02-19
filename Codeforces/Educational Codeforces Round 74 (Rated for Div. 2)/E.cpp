#include <bits/stdc++.h>
#define gc getchar
#define re register
#define rep(i, s, t) for (re int i = s; i <= t; ++i)
#define reb(i, s, t) for (re int i = s; i >= t; --i)

template <class T>
inline void Readin(T &X)
{
    X = 0;
    register bool F = false;
    register char C = gc();
    while (C < '0' or C > '9')
    {
        if (C == '-')
            F = true;
        C = gc();
    }
    while (C <= '9' and C >= '0')
        X = (X << 1) + (X << 3) + (C & 15), C = gc();
    if (F)
        X = -X;
}
template <class T>
inline void Prt(T X)
{
    if (X < 0)
        putchar('-'), X = -X;
    if (X > 9)
        Prt(X / 10);
    putchar(X % 10 + '0');
}

using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int T, n, h, p[N], Ans;

int main()
{
    Readin(T);
    for (; T--;)
    {
        Readin(h), Readin(n);
        Ans = 0;
        rep(i, 1, n) Readin(p[i]);
        if (n == 1)
        {
            putchar('0'), putchar('\n');
            continue;
        }
        p[n + 1] = 0, p[1] = p[2] + 1;
        rep(i, 1, n - 1)
        {
            if (p[i] - 1 == p[i + 1])
            {
                if (p[i] - p[i + 2] <= 2)
                {
                    ++i, p[i + 1] = p[i + 2] + 1;
                    continue;
                }
                else
                {
                    ++Ans, p[i + 1] = p[i + 2] + 1;
                    continue;
                }
            }
        }
        Prt(Ans), putchar('\n');
    }
    return 0;
}