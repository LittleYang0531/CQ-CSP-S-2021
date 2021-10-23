#include<bits/stdc++.h>
#define inl inline
using namespace std;
const int maxn=505;
int n,m,T,K,ans;
inl int Read()
{
	int s=0; char c;
	while(!isdigit(c=getchar()));
	for(;isdigit(c);c=getchar()) s=s*10+c-'0';
	return s;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=Read(); m=Read();T=Read();
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j) Read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j) Read();
	while(T--)
	{
		K=Read(); ans=0;
		while(K--) ans+=Read(), Read(), Read();
		printf("%d\n",ans);
	}
	return 0;
}
