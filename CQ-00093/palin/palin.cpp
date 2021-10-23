#include<bits/stdc++.h>
using namespace std;
inline int r(){int s=0,k=1;char c=getchar();while(!isdigit(c)){if(c=='-')k=-1;c=getchar();}while(isdigit(c)){s=s*10+c-'0';c=getchar();}return s*k;}
int n,ans[5005],a[5005],cnt,T,t[5005],b[5005],ok,f[5005];
void check(int now,int l,int r)
{
	if(now==0)
	{
		ok=1;
		for(int i=1;i<=2*n;i++)
		{
			if(ans[i]==1)putchar('L');
			else putchar('R');
		}
		puts("");
		return;
	}
	if(a[l]==t[now])
	{
		ans[++cnt]=1;
		check(now-1,l+1,r);
		cnt--;
	}
	else if(a[r]==t[now])
	{
		ans[++cnt]=2;
		check(now-1,l,r-1);
		cnt--;
	}
}
void dfs(int now,int l,int r)
{	
//	cout<<"dfs"<<l<<' '<<r<<endl;
	if(ok)return;
	if(now==n)
	{
//		for(int i=1;i<=n;i++)
//		cout<<t[i]<<' ';
//		cout<<endl;
		check(n,l,r);
		return;
	}
	if(!b[l])
	{
		b[l]=1;b[f[l]]=1;
		ans[++cnt]=1;
		t[now+1]=a[l];
		dfs(now+1,l+1,r);
		cnt--;
		b[l]=0;b[f[l]]=0;
	}
	if(ok)return;
	if(!b[r])
	{
		b[r]=1;b[f[r]]=1;
		ans[++cnt]=2;
		t[now+1]=a[r];
		dfs(now+1,l,r-1);
		cnt--;
		b[r]=0;b[f[r]]=0;
	}
}
void init()
{
	ok=0;
	memset(b,0,sizeof(b));
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=r();
	while(T--)
	{
		n=r();
		for(int i=1;i<=2*n;i++)a[i]=r();
		for(int i=1;i<=2*n;i++)
		{
			if(!b[a[i]])b[a[i]]=i;
			else f[i]=b[a[i]],f[b[a[i]]]=i;
		}
		init();
		dfs(0,1,2*n);
		if(!ok)puts("-1");
	}
}
