#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<stack>
#include<cstring>
#include<algorithm>
#define N 100005
#define INF 0x7fffffff
using namespace std;
int a[N<<1],b[N<<1];
int n;
bool HW()
{
	for(int i=1;i<=2*n;i++)
	{
		if(b[i]!=b[2*n-i+1]) return false;
	}
	return true;
}
char op[10005];
int l,r;
int dfs(int dep)
{
	if(dep>2*n) 
	{
		if(HW()) return 1;
		return 0;
	}
	op[dep]='L';
	b[dep]=a[l++];
	if(dfs(dep+1)) return 1;
	l--;
	op[dep]='R';
	b[dep]=a[r--];
	if(dfs(dep+1)) return 1;
	r++;
	return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		l=1,r=2*n;
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		if(dfs(1)) 
		{
			for(int i=1;i<=2*n;i++)
			{
				cout<<op[i];
			}
			cout<<endl;
		}
		else cout<<-1<<endl;
	}
	return 0;	
}

