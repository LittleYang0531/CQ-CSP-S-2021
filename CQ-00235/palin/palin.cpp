#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
int a[100010],in[100010],n;
char k[100010];
void bl(int i,int l,int r)
{
	if(l==r)return;
	if(i==n)
	{
		for(int z=0;z<n;++z)
			putchar(k[z]),putchar(' ');
		exit(0);
	}
	if(i>(n+1)/2)
	{
		int y=(n+1)/2*2;
		if(in[l+1]==a[y-i])
		{
			k[i]='L';
			++l;
			bl(i+1,l,r);
		}
		if(in[r-1]==a[y-i])
		{
			k[i]='R';
			++r;
			bl(i+1,l,r);
		}
		return;
	}
	k[i]='L',a[i]=in[++l];
	bl(i+1,l,r);
	--l;
	k[i]='R',a[i]=in[--r];
	bl(i+1,l,r);
}
#define rid(g) g=read()
main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int rid(t);
	while(t--)
	{
		int rid(n);
		for(int z=0;z<n;z++)rid(a[z]);
		bl(0,-1,n);
	}
	return 0;
}
