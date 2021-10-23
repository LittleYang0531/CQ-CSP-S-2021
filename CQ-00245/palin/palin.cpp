#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##END=b;i<=i##END;++i)
#define go(x) for(int i=a,i##END=b;i<=i##END;++i)
template<class T>
inline void in(T&x)
{
	T f=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x*=f;
}
template void in<int>(int&);
template<class T>
void out(T x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)out(x/10);
	putchar(x%10^48);
}
template void out<int>(int);

using namespace std;

const int N=1e6+5;

int n;
int a[N];
int ans[N];

bool check(int w)
{
	ans[1]=w,ans[n]=1;
	int al=1,ar=n;
	int l1=1,r1=0,l2=n+1,r2=n;
	if(w==1)++l1;
	else --r2;
	For(i,l1,r2)
	{
		if(a[i]!=a[w])r1=i;
		else break;
	}
	for(int i=r2;i>=l1;--i)
	{
		if(a[i]!=a[w])l2=i;
		else break;
	}
//	printf("lr:%d %d %d %d\n",l1,r1,l2,r2);
	while(1)
	{
		if(l1<=r1)
		{
			if(l1!=r1&&a[l1]==a[r1])
			{
				++l1,--r1;
				ans[++al]=1,ans[--ar]=1;
				continue;
			}
			if(l2<=r2&&a[l1]==a[l2])
			{
				++l1,++l2;
				ans[++al]=1,ans[--ar]=n;
				continue;
			}	
		}
		if(l2<=r2)
		{
			if(l1<=r1&&a[r1]==a[r2])
			{
				--r1,--r2;
				ans[++al]=n,ans[--ar]=1;
				continue;
			}
			if(l2!=r2&&a[l2]==a[r2])
			{
				++l2,--r2;
				ans[++al]=n,ans[--ar]=n;
				continue;
			}
		}
		break;
	}
	if(al+1==ar)return 1;
	return 0;
}

signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	in(T);
	while(T--)
	{
		in(n);
		n<<=1;
		For(i,1,n)
		{
			in(a[i]);
		}
		if(check(1))For(i,1,n)putchar(ans[i]==1?'L':'R');
		else if(check(n))For(i,1,n)putchar(ans[i]==1?'L':'R');
		else out(-1);
		putchar('\n');
	}
	return 0;
}
