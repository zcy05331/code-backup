#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
long double g=10.0;
int main()
{
    long double t,v=1,vxt,vyt,xxt,xyt,theta=1;
    cin>>v>>theta;
    //printf("%Lf %Lf ",v,theta);
    t=v*cos(theta)/g;
    vxt=v*sin(theta);
    vyt=g*t;
    xxt=t*vxt;
    xyt=0.5*vyt*t;
    printf("%.15Lf %.15Lf",xxt,xyt);
	return 0;
}
