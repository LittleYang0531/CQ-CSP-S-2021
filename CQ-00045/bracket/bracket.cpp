#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#define maxn 502
#define inf (1<<30)
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
int read()
{
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=='-'?f=-f,c=getchar():c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	return x*f;
}
string s;
int n,k;
int f[maxn][maxn];
ll dfs(int l,int r)
{
	if(l>r)return 1;
	if(l==r)return 0;
	if(f[l][r]>=0)return f[l][r];
//	cout<<1;
	ll sum=0;
	if((s[l]=='('||s[l]=='?')&&(s[r]==')'||s[r]=='?'))
	{
//		cout<<2;
		bool qwe=1;
		for(int i=l+1;i<r;i++)
		{
			if(s[i]!='?'&&s[i]!='*')
			{
				qwe=0;
				break;
			}
		}
		if(qwe&&r-l-1<=k&&r-l-1!=0)sum++;
		sum+=dfs(l+1,r-1);
		sum%=mod;
		int i=l+1,ss=0;
		while(i<r-1&&ss<k&&(s[i]=='?'||s[i]=='*'))
		{
			ss++;
			sum=(sum+dfs(i+1,r-1))%mod;
			i++;
		}
		i=r-1;
		ss=0;
		while(i>l+1&&ss<k&&(s[i]=='?'||s[i]=='*'))
		{
			ss++;
			sum=(sum+dfs(l+1,i-1))%mod;
			i--;
		}
		for(int i=l;i<r;i++)
		{
			sum=(sum+dfs(l,i)*dfs(i+1,r)%mod)%mod;
			int j=i+1;
			ss=0;
			while(j<r&&ss<k&&(s[j]=='?'||s[j]=='*'))
			{
				ss++;
				sum=(sum+(dfs(l,i)*dfs(j+1,r)%mod))%mod;
				j++;
			}
		}
	}
	f[l][r]=sum;
	return sum;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();
	k=read();
	cin>>s;
	s=' '+s;
	memset(f,-1,sizeof(f));
	printf("%lld\n",dfs(1,n));
	return 0;
}
//10 2
//???(*??(?)
