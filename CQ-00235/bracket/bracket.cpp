#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define u  unsigned
#define pi pair<int,int>
#define X first
#define Y second
#define rg register
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch)
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
char s[550];
int n,k;
const int mod=1000000007;
u ll dg(rg int i,int sx,int kh,int fsx)
{
	u ll ans=1;
	for(rg int sx=0;s[i]!=')'&&i<n; ++i)
	{cout<<ans;
		ans%=mod;
		if(s[i]=='?')
		{
			int got=0;
			if(kh)
				got+=dg(i+1,fsx,kh-1,0);
			else
			{
				++i;
				got+=dg(i,0,kh+1,sx)%mod;
				ans*=got;
				continue;
			}
			got+=dg(i+1,0,kh+1,sx);
			got+=dg(i+1,sx+1,kh,fsx);
			ans*=got;
		}
		else if(s[i]=='*') ++sx;
			else
			{
				++i;
				ans*=dg(i,0,kh+1,sx);
			}
		if(sx>k||!ans)return 0;
	}
	if(kh!=0)return 0;
	return 1;
}
#define rid(g) g=read()
main()
{
	freopen("bracket.in","r",stdin);
//	freopen("bracket.out","w",stdout);
	rid(n),rid(k);
	scanf("%s",s);
	if(s[0]=='*'||s[0]==')'||s[n-1]=='*'||s[n-1]=='(')
	{
		putchar('0');
		return 0;
	}
	s[0]='(',s[n-1]=')';
	printf("%lld",dg(0,0,0,0));
	return 0;
}
