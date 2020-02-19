#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

struct node
{
    int l, r;
    double sum, len;
};

int n;
double a[MaxN];
std::vector<node> vec;

int main()
{
    int tmp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &tmp), a[i] = tmp;
    for (int i = 1; i <= n; i++)
    {
        vec.push_back((node){i, i, a[i], 1});
        while (vec.size() >= 2 && (vec[vec.size() - 2].sum / vec[vec.size() - 2].len) >= (vec[vec.size() - 1].sum / vec[vec.size() - 1].len))
        {
            // printf("%.10lf, %.10lf\n", (vec[vec.size() - 2].sum / vec[vec.size() - 2].len), (vec[vec.size() - 1].sum / vec[vec.size() - 1].len));
            node x = (node){vec[vec.size() - 2].l, vec[vec.size() - 1].r, vec[vec.size() - 2].sum + vec[vec.size() - 1].sum, vec[vec.size() - 1].r - vec[vec.size() - 2].l + 1.0};
            vec.pop_back(), vec.pop_back(), vec.push_back(x);
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = vec[i].l; j <= vec[i].r; j++)
            a[j] = (vec[i].sum / vec[i].len);
    }
    for (int i = 1; i <= n; i++)
        printf("%.10lf\n", a[i]);
    return 0;
}
