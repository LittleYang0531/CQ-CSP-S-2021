#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N]; 
int temp[N],ans[N];
bool vis[N];
char op[N],temp1[N];
int read()
{
	int x=0,f=1;char s=getchar();
	while(s<'0'||s>'9')
	{
		if(s=='-') f=-f;
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=x*10+s-48;
		s=getchar();
	}
	return x*f;
}
void dfs(int x,int l,int r)
{
	if(r<l)
	{
		for(int i=1;i<=(n<<1);i++)
		if(temp[i]<ans[i])
		{
			for(int j=1;j<=(n<<1);j++)
			ans[j]=temp[j];
			for(int j=1;j<=(n<<1);j++)
			op[j]=temp1[j];
			break;
		}
		else if(temp[i]>ans[i]) break;
		return ;
	}
	if(x<=n)
	{
		if(!vis[a[l]])
		{
			vis[a[l]]=1;
			temp[x]=a[l];
			temp1[x]='L'; 
			dfs(x+1,l+1,r);
			vis[a[l]]=0;
		}
		if(!vis[a[r]])
		{
			vis[a[r]]=1;
			temp[x]=a[r];
			temp1[x]='R'; 
			dfs(x+1,l,r-1);
			vis[a[r]]=0;
		}
	}
	else
	{
		if(vis[a[l]]&&temp[2*n+1-x]==a[l])
		{
			temp[x]=a[l];
			temp1[x]='L'; 
			dfs(x+1,l+1,r);
		}
		if(vis[a[r]]&&temp[2*n+1-x]==a[r])
		{
			temp[x]=a[r];
			temp1[x]='R'; 
			dfs(x+1,l,r-1);
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=(n<<1);i++) ans[i]=0x7fffffff;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=(n<<1);i++)
		a[i]=read();
		dfs(1,1,(n<<1));
		if(ans[1]>100000000)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=(n<<1);i++)
		printf("%c",op[i]);
		printf("\n");
	}
	return 0;
}
