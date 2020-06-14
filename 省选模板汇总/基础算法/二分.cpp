#include <bits/stdc++.h>

#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

bool check(int mid)
{
    //do something
}

bool calc(double mid)
{
    //do something in real number field
}

double find(double l, double r) // find answer in real number field
{
    double L = l, R = r;
    for(int i = 1; i <= 100; i++)
    {
        double mid = (L + R) / 2;
        if(calc(mid)) r = mid;
        else l = mid;
    }
    return l;
}

int getmin(int l, int r)
{
    int L = l, R = r;
    while(L < R)
    {
        int mid = (L + R) >> 1;
        if(check(mid))
            R = mid;
        else L = mid + 1;
    }
    return L;
}

int getmax(int l, int r)
{
    int L = l, R = r;
    while(L < R)
    {
        int mid = (L + R + 1) >> 1;
        if(check(mid)) 
            L = mid;
        else R = mid - 1;
    }
    return L;
}

int main()
{   
    //do something
    return 0;
}
