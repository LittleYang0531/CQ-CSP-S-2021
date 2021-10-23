#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;
	char ch=getchar();
	while(ch<'0'||ch>'9');
	x=ch-'0';
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x;
}
int T;
int n;
int a[1000001];
bool bj=0;
char f[500001],l[500001];
inline bool dfs(int num,int fx,int fy,int lx,int ly)
{
	//cout<<num<<" "<<fx<<" "<<fy<<" "<<lx<<" "<<ly<<endl;
	if(num==n)
	{
		return 1;
	}
	if(fx<lx&&a[fx]==a[lx])
	{
		if(dfs(num+1,fx+1,fy,lx-1,ly))
		{
			f[num]='L';
			l[num]='L';
			return 1;
		}
	}
	if(fx<=lx&&fy>=ly&&a[fx]==a[ly])
	{
		if(dfs(num+1,fx+1,fy,lx,ly+1))
		{
			f[num]='L';
			l[num]='R';
			return 1;
		}
	}
	if(fx<=lx&&fy>=ly&&a[fy]==a[lx])
	{
		if(dfs(num+1,fx,fy-1,lx-1,ly))
		{
			f[num]='R';
			l[num]='L';
			return 1;
		}
	}
	//cout<<a[fy]<<" "<<a[ly]<<endl;
	if(fy>ly&&a[fy]==a[ly])
	{
		if(dfs(num+1,fx,fy-1,lx,ly+1))
		{
			f[num]='R';
			l[num]='R';
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=2*n;i++)
		{
			a[i]=read();
		}
		int s1=n,s2=1;
		for(int i=2;i<2*n;i++)
		{
			if(a[i]==a[1])
			{
				s1=i;
			}
			else if(a[i]==a[2*n])
			{
				s2=i;
			}
		}
		if(dfs(1,2,2*n,s1-1,s1+1))
		{
			cout<<"L";
			for(int i=1;i<n;i++)
			{
				cout<<f[i];
			}
			for(int i=n-1;i>=1;i--)
			{
				cout<<l[i];
			}
			cout<<"L"<<endl;
			continue;
		}
		if(dfs(1,1,2*n-1,s2-1,s2+1))
		{
			cout<<"R";
			for(int i=1;i<n;i++)
			{
				cout<<f[i];
			}
			for(int i=n-1;i>=1;i--)
			{
				cout<<l[i];
			}
			cout<<"L"<<endl;
			continue;
		}
		cout<<-1<<endl;
	}
	return 0;
}
