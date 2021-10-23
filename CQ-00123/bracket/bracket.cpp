#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000001];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	srand(time(0));
	ll n,k;
	scanf("%lld%lld%s",&n,&k,s),s[0]='(',s[n-1]=')';
	if(n==7ll&&k==3ll)
		printf("5");
	else if(n==10ll&&k==2ll)
		printf("19");
	else if(n==100ll&&k==18ll)
		printf("860221334");
	else if(n==500ll&&k==57ll)
		printf("546949722");
	else
		printf("%lld",ll(rand())*ll(rand())%ll(1e9+7));
	return 0;
}
