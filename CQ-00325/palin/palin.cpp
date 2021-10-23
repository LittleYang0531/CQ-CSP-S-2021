#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
//char buf[1<<23],*p1,*p2;
//#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2))?EOF:*p1++)
//inline void rd(int &x)
//{
//	x=0;
//	char ch=getchar();
//	while(ch<'0'||ch>'9')ch=getchar();
//	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
//}
int n;
int s[1000005];
bool a[1000005];
bool flag;
int tmp[1000005];
bool check()
{
	bool flag=true;
	int l=1,r=2*n;
	for(int i=1;i<=2*n;++i)
	{
		if(a[i]==0)tmp[i]=s[l++];
		else tmp[i]=s[r--];
	}
	for(int i=1;i<=2*n;++i)
	{
		if(tmp[i]!=tmp[2*n+1-i])return false;
	}
	return true;
}
void dfs(int step,int l,int r)
{
	if(flag)return ;
	if(step>2*n)
	{
		if(check())
		{
			flag=true;
			for(int i=1;i<=2*n;++i)
			{
				if(a[i]==0)cout<<'L';
				else cout<<'R';
			}
			cout<<'\n';
		}
		return ;
	}
	a[step]=0;
	dfs(step+1,l+1,r);
	a[step]=1;
	dfs(step+1,l,r-1);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		flag=false;
		cin>>n;
		for(int i=1;i<=2*n;++i)cin>>s[i];
		dfs(1,1,2*n);
		if(!flag)cout<<"-1\n";
	}
	return 0;
}
