#include<bits/stdc++.h>
using namespace std;
int main()
{
	float x,a=2,n=0;
	int ans=0;
	scanf("%f",&x);
	while(x>n)
	{
		n+=a;
		a*=0.98;
		ans++;
	//	cout<<"n= "<<n<<" a= "<<a<<" ans= "<<ans<<endl;
	}
	cout<<ans;
	return 0;
}

