#include <bits/stdc++.h>

#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const double eps = 1e-7;

int n;
double l, r, a[20];

double f(double x)
{
    double ret = 0;
    for (int i = n; ~i; i--)
        ret = (ret * x) + a[i];
    return ret;
}

int main()
{
    scanf("%d%lf%lf", &n, &l, &r);
    for (int i = n; ~i; i--)
        scanf("%lf", &a[i]);
    while (l <= r - eps)
    {
        double k = (r - l) / 3.0, L = l + k, R = r - k;
        if (f(L) > f(R)) r = R;
        else l = L;
    }
    printf("%0.5lf", l);
    return 0;
}
