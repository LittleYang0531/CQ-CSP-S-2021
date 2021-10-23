#include <bits/stdc++.h>
using namespace std;
int T,a[1000001],b[1000001];
std::string str;
bool z;
void dfs(int b[1000001],std::string ans,int l,int al,int ar,int n)
{
	if(z) return;
	if(l==n+n+1||al>ar)
	{
		bool f=true;
		for(int i=1;i<=n;i++)
		{
			if(b[i]!=b[n+n-i+1])
			{
				f=false;
				break;
			}
		}
		if(f)
		{
			str=ans;
			z=true;
		}
		return;
	}
	if(l>2*n||al>2*n||ar<1) return;
	b[l]=a[al];
	dfs(b,ans+"L",l+1,al+1,ar,n);
	b[l]=a[ar];
	dfs(b,ans+"R",l+1,al,ar-1,n);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	std::cin>>T;
	for(int t=1,n;t<=T;t++)
	{
		memset(a,0,sizeof(a));
		str="-1";
		z=false;
		scanf("%d",&n);
		for(int i=1;i<=n+n;i++) scanf("%d",&a[i]);
		dfs(b,"",1,1,n+n,n);
		std::cout<<str<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
