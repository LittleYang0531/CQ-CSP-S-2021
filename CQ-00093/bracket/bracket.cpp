#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int r(){int s=0,k=1;char c=getchar();while(!isdigit(c)){if(c=='-')k=-1;c=getchar();}while(isdigit(c)){s=s*10+c-'0';c=getchar();}return s*k;}
int n,k,f[50][50],s[1005],cl[1005],cr[1005],ca[1005],ans;
const int mod=1000000007;
char c[1005];
inline bool check(int l,int r)
{
	if(l>r)return 0;
	return (s[r]-s[l-1]==r-l+1&&r-l+1<=k);
}
int dfs(int l,int r)
{
	if(l>=r)return f[l][r]=0;
	if(!cl[l]||!cr[r])return f[l][r]=0;
	if(f[l][r]!=-1)return f[l][r];
//	if(f[l][r])return 1;
	
	f[l][r]=0;
	if(check(l+1,r-1)||r-l==1)f[l][r]++;//()
//	if(f[l][r])return 1;
	
	if(l+1<r-1)f[l][r]+=dfs(l+1,r-1);//(A)
	f[l][r]%=mod;
//	if(f[l][r])return 1;
	
	for(int i=l+2;i<=r-2;i++)//(AS)
	if(check(i+1,r-1))
	if(l+1<i)f[l][r]+=dfs(l+1,i),f[l][r]%=mod;
//	if(f[l][r])return 1;
	
	for(int i=l+1;i<=r-3;i++)//(SA)
	if(check(l+1,i))
	if(i+1<r-1)f[l][r]+=dfs(i+1,r-1),f[l][r]%=mod;	
//	if(f[l][r])return 1;
	
	int ok=0;
	for(int i=l+1;i<=r-2;i++)//AB
	{
		if(l<i&&i+1<r)
		{
			ok=(long long)dfs(l,i)*dfs(i+1,r)%mod;
			f[l][r]+=ok,f[l][r]%=mod;
		}
	}
//	if(f[l][r])return 1;
	
	for(int i=l+2;i<=r-2;i++)//ASB
	for(int j=i;j<=r-2;j++)
	if(check(i,j))
	{
		if(l<i-1&&j+1<r)
		{
			ok=(long long)dfs(l,i-1)*dfs(j+1,r)%mod;
			f[l][r]+=ok,f[l][r]%=mod;
		}
	}
//	if(f[l][r])return 1;
	return f[l][r];
}
void init()
{
	memset(f,-1,sizeof(f));	
	for(int i=1;i<=n;i++)
	{
		cl[i]=(c[i]=='('||c[i]=='?');
		cr[i]=(c[i]==')'||c[i]=='?');
		ca[i]=(c[i]=='*'||c[i]=='?');
//		cout<<cl[i]<<' '<<cr[i]<<' '<<ca[i]<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		if(ca[i])s[i]=1;
		else s[i]=0;
		s[i]+=s[i-1];
	}
}

void bs(int now)
{
	if(now==n+1)
	{
		init();
		if(dfs(1,n))
		{
			ans++;
//			cout<<(c+1)<<endl;
		}
		return;
	}
	if(c[now]=='?')
	{
		c[now]='(';
		bs(now+1);
		
		c[now]=')';
		bs(now+1);
		
		c[now]='*';
		bs(now+1);
		
		c[now]='?';
	}
	else bs(now+1);
}
signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);

	n=r();k=r();
	cin>>(c+1);
	if(n<=40)
	{
		bs(1);
		cout<<ans;
	}
	else 
	{
		init();
		cout<<dfs(1,n);
	}
}
