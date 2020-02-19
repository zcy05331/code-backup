#include <bits/stdc++.h>
using namespace std;
int a[13] = {};
int main()
{
	int ans = 0, now = 0, s = 0;
	for (int i = 0; i < 12; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 12; i++)
	{
		s = 0;
		now += 300;
		now -= a[i];
		if (now < 0)
		{
			cout << "-" << i + 1;
			return 0;
		}
		s = now / 100;
		now %= 100;
		ans += s * 100;
		//	cout<<"now="<<now<<" ans="<<ans<<"\n";
	}
	ans *= 1.2;
	printf("%d", ans + now);
	return 0;
}
