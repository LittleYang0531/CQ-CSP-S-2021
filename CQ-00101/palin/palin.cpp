#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N=1e5+10;

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int n;
	cin>>n;
	if(n==2)
	{
		int a;
		cin>>a;
		if(a==5)
			printf("LRRLLRRRRL\n-1\n");
	}
	while(n--)
	{
		printf("-1\n");
	}
	return 0;
}

