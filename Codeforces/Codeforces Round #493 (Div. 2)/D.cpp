#pragma G++ optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
const int a[]= {0,4,10,20,35,56,83,116,155,198,244,292};

int main()
{
    long long n,ans;
    scanf( "%I64d", &n );
    if(ans<=11)ans=a[n];
    else ans=a[11]+(49)*(n-11);
    printf( "%I64d", ans );
    return 0;
}
