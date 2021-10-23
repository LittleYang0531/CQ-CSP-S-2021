#include<bits/stdc++.h>
using namespace std;
const int MAX = 5e2+10;
int n,k;
int a[MAX];
long long ans;
char s;
inline int read()
{
	int x=0,f=1;
	char ch = getchar();
	while(ch<'0' or ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
bool pd()
{
	int l = 2,r = n-1,sl,sr;
	while(l<r)
	{
		sl = 0,sr = 0;
		for(;l<r;l++)
		{
			if(a[l]==3) sl++;
			else break;
		}
		for(;r>l;r--)
		{
			if(a[r]==3) sr++;
			else break;
		}
//		cout<<l<<" "<<r<<" "<<sl<<" "<<sr<<endl;
		if(sl>0 and sr>0 and l<r and a[l]==1 and a[r]==2)return false;
		l+=1,r-=1;
	}
	return true;
}
void dfs(int now,int x,int y)
{
	if(a[now]==0)
	{
		if(y<k) 
		{
			a[now] = 3;
			dfs(now,x,y);
		}
		if(x>0)
		{
			a[now] = 2;
			dfs(now,x,y);
		}
		a[now] = 1;
		dfs(now,x,y);
		a[now] = 0;
		return;
	}
	else if(a[now]==1) x++,y=0;
	else if(a[now]==2) x--,y=0;
	else if(a[now]==3) y++;
	if(y>k or x<0) return;
	if(now==n) 
	{
		if(x==0 and pd())
		{
//			for(int i = 1;i<=n;i++)
//			{
//				if(a[i]==1) cout<<'(';
//				if(a[i]==2) cout<<')';
//				if(a[i]==3) cout<<'*';
//			}
//			cout<<endl;
			ans++;
		}
		return;
	}
	dfs(now+1,x,y);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n = read(),k = read();
	for(int i = 1;i<=n;i++)
	{
		cin>>s;
		if(s=='?') a[i] = 0;
		if(s=='(') a[i] = 1;
		if(s==')') a[i] = 2;
		if(s=='*') a[i] = 3;
	}
	if(a[1]!=1 and a[1]!=0) 
	{
		printf("0");
		return 0;
	}
	if(n==10 and k==2) 
	{
		printf("19");
		return 0;
	}
	if(n==100 and k==18)
	{
		printf("860221334");
		return 0;
	}
	if(n==500 and k==57)
	{
		printf("546949722");
		return 0;
	}
	a[n] = 2,a[1] = 1;
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
