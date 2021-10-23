#include<iostream>
#include<cstring>
#include<cstdio>

#define maxn 10005
#define rc() getchar()

using namespace std;

int a[maxn],b[maxn],ans[maxn],n,m,bj;

inline int read()
{
	int x=0,b=1;char c=rc();
	while(c<'0'||c>'9') (c=='-')&&(b=-1),c=rc();
	while(c>='0'&&c<='9') x=x*10+(c^48),c=rc();
	return x*b;
}

void f(int x)
{
	if(x==n+1)
	{
		int top1=1,top2=m;
		for(register int i=1;i<=n;++i)
		{
			if(ans[i]==1) b[i]=a[top1++];
			else b[i]=a[top2--];
		}
		int bjj=0;
		for(register int i=n;i>=1;--i)
		{
			if(a[top1]==b[i])++top1,ans[m-i+1]=1;
			else if(a[top2]==b[i])--top2,ans[m-i+1]=2;
			else
			{
				bjj=1;
				break;
			}
		}
		if(bjj==0)bj=1;
		return;
	}
	ans[x]=1;f(x+1);if(bj==1)return;
	ans[x]=2;f(x+1);
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	int t=read();
	while(t--)
	{
		n=read();m=n<<1;
		for(register int i=1;i<=m;++i) a[i]=read();
		f(1);
		if(bj==0) printf("-1\n");
		else
		{
			for(register int i=1;i<=m;++i)
				if(ans[i]==1) putchar('L');
				else putchar('R');
			printf("\n");
		}
		bj=0;
	}
	return 0;
}

