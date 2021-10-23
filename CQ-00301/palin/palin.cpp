#include<iostream>
#include<cstdio>
#include<vector>
const int N=1e6+5;
using namespace std;
//char me1;
vector<int>v[N];
int a[N],s[N],dy[N];
int n,n2;
char ans[N],tans[N];
bool fl=0;
//#define getchar gc
inline int read()
{
	char h=getchar();
	int y=0,q=1;
	while(h<'0'||h>'9'){if(h=='-')q=-1;h=getchar();}
	while(h>='0'&&h<='9')y=y*10+h-'0',h=getchar();
	return y*q;
}
inline void calc1(int l,int r)
{
//	cout<<l<<" "<<r<<"!!!\n";
	int nl=dy[1],nr=dy[1],xl=2,xr=n2;
	tans[1]='L';tans[n2]='L';
	for(int i=2;i<=n;i++)
	{
		if(xl<l&&(nl==0||dy[xl]==nl-1||dy[xl]==nr+1))
		{
			if(nl==0)nl=dy[xl],nr=dy[xl],tans[n2-i+1]='L';
			else if(dy[xl]==nl-1)nl--,tans[n2-i+1]='L';
			else nr++,tans[n2-i+1]='R';
			tans[i]='L';
			xl++;
		}
		else if(xr>r&&(nl==0||dy[xr]==nl-1||dy[xr]==nr+1))
		{
			if(nl==0)nl=dy[xr],nr=dy[xr],tans[n2-i+1]='L';
			else if(dy[xr]==nl-1)nl--,tans[n2-i+1]='L';
			else nr++,tans[n2-i+1]='R';
			tans[i]='R';
			xr--;
		}
		else return;
	}
	if(!fl)
	{
		for(int i=1;i<=n2;i++)
		ans[i]=tans[i];
		fl=1;
	}
	else
	{
		for(int i=1;i<=n2;i++)
		if(ans[i]!=tans[i])
		{
			if(ans[i]<tans[i])return;
			else break;
		}
		for(int i=1;i<=n2;i++)
		ans[i]=tans[i];
	}
}
inline void calc2(int l,int r)
{
	int nl=dy[n2],nr=dy[n2],xl=1,xr=n2-1;
	
	tans[1]='R';tans[n2]='L';
	for(int i=2;i<=n;i++)
	{
		if(xl<l&&(nl==0||dy[xl]==nl-1||dy[xl]==nr+1))
		{
			if(nl==0)nl=dy[xl],nr=dy[xl],tans[n2-i+1]='L';
			else if(dy[xl]==nl-1)nl--,tans[n2-i+1]='L';
			else nr++,tans[n2-i+1]='R';
			tans[i]='L';
			xl++;
		}
		else if(xr>r&&(nl==0||dy[xr]==nl-1||dy[xr]==nr+1))
		{
			if(nl==0)nl=dy[xr],nr=dy[xr],tans[n2-i+1]='L';
			else if(dy[xr]==nl-1)nl--,tans[n2-i+1]='L';
			else nr++,tans[n2-i+1]='R';
			tans[i]='R';
			xr--;
		}
		else return;
	}
	if(!fl)
	{
		for(int i=1;i<=n2;i++)
		ans[i]=tans[i];
		fl=1;
	}
	else
	{
		for(int i=1;i<=n2;i++)
		if(ans[i]!=tans[i])
		{
			if(ans[i]<tans[i])return;
			else break;
		}
		for(int i=1;i<=n2;i++)
		ans[i]=tans[i];
	}
}
//char me2;
int main()
{
//	cout<<((&me1-&me2)>>20)<<"!!!\n";
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t=read();
	while(t--)
	{
		n=read(),n2=n<<1;int cnt=0;fl=0;
		for(int i=1;i<=n;i++)s[i]=0,v[i].clear();
		for(int i=1;i<=n2;i++)a[i]=read(),v[a[i]].push_back(i);
		for(int i=1;i<=n;i++)dy[v[i][0]]=v[i][1],dy[v[i][1]]=v[i][0];
		for(int i=n+1;i<=n2;i++)
		{
			s[a[i]]++;
			if(s[a[i]]==1)cnt++;
		}
		for(int i=n2;i>=n;i--)
		{
			if(cnt==n)
			{
				if(i-n+1>1)calc1(i-n+1,i);
				if(i<n2)calc2(i-n+1,i);
				if(n>1000)
				{
					if(i==n2)
					{
						calc2(1,n);
					}
					break;
				}
			}
			s[a[i]]--;
			if(s[a[i]]==0)cnt--;
			s[a[i-1-n+1]]++;
			if(s[a[i-1-n+1]]==1)cnt++;
		}
		if(!fl)puts("-1");
		else 
		{
			for(int i=1;i<=n2;i++)putchar(ans[i]);
			putchar('\n');
		}
	}
	return 0;
}
/*
1
20
17 3 16 1 9 12 19 6 8 2 20 14 18 10 5 11 15 7 13 4
4 13 7 15 11 5 10 18 17 14 20 2 8 6 19 12 9 1 16 3
*/
