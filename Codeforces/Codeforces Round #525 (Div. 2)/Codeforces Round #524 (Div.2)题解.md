# Codeforces Round #524 (Div.2)题解

## 题解CF 1088A Ehab and another construction problem

本题即是给定整数$x$求任意满足以下条件的数对$(a,b)$

* $1 \leq a$,$b \leq x$

* $a \mod b = 0$
* $x < a*b$
* $a/b > x$

做完了

```cpp
# include <bits/stdc++.h>

int main()
{
    int x;
    scanf("%d", &x);
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= x; j++)
            if((i % j == 0) && (j * i > x) && ((i / j) < x))
                return 0 * printf("%d %d\n", i, j);
    printf("-1");
    return 0;
}
```



## 题解CF 1088B Ehab and subtraction

一看到$1e5$的规模马上想到$O(n \log_2 n)$以下的算法

一看首先排序啊

再一看排完序满足单调性肯定二分啊

每次二分下一个非$0$的数的下标

记得把$r$设成inf,方便边界判断

```cpp
# include <bits/stdc++.h>

# define ll long long

ll a[100010];

int main()
{
    ll n, k;
    ll now = 0, pos = 1;
    scanf("%I64d%I64d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    std::sort(a + 1, a + n + 1);
    a[n + 1] = 0x7f7f7f7f7f7f7f;
    for(int i = 1; i <= k; i++)
    {
        if(pos == n + 1)
        {
            printf("0\n");
            continue;
        }
        printf("%I64d\n", a[pos] - now);
        now += a[pos] - now;
        ll l = pos + 1, r = n + 1;
        while(l < r)
        {
            ll mid = (l + r) >> 1;
            if(a[mid] > now)
                r = mid;
            else l = mid + 1;
        }
        pos = l;
    }
    return 0;
}
```



## 题解CF 1088C Ehab and a 2-operation task

这个$C​$代码非常好写！！！！！

贪心地，我们可以把每个数$a_i$模成$i$

但有些数不到$i$怎么办?

我们把它加上一个非常大的数（~~像233333这样~~）

然后每次模上一个数使$a_i$等于$i$即可

```cpp
# include <bits/stdc++.h>

int a[2010];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]); 
    printf("%d\n", n + 1);
    printf("1 %d %d\n", n, 899999);
    for(int i = 1; i <= n; i++)
    {
        a[i] += 899999;
        printf("2 %d %d\n", i, (a[i] - i + 1));
        a[i] %= (a[i] - i + 1);
    }
    return 0;
}
```









