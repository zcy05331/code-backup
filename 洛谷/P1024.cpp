#include<bits/stdc++.h>
using namespace std;
float a, b, c, d;
float f( float x )
{
    return a*pow(x,3)+b*pow(x,2)+c*x+d;
}
int main()
{
    //freopen("P1024.out","w",stdout);
    scanf( "%f%f%f%f", &a, &b, &c, &d );
    for(int i=0;i<=20000;i++)
	{
        float x=-100.0+(i/100.0);
        if(f(x)<=0.00001&&f(x)>=-0.00001)printf("%0.2f ",x);
	}
    return 0;
}
