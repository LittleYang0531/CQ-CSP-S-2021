#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[1000005];
int b[1000005];
char path[1000005];
bool flg=0;
void print()
{
	for(int i=1;i<=2*n;++i)
	printf("%c",path[i]);
	printf("\n");
}
bool check()
{
	for(int i=1;i<=n;++i)
	{
		if(b[i]!=b[2*n+1-i])
		return 0;
	}
	return 1;
}
void dfs(int x,int head,int tail)
{
	if(flg==1)
	return;
	if(x>2*n)
	{
		if(check())
		{
			flg=1;
			print();
		}
		return;
	}
	else if(x>n+1)
	{
		int p=x-1;
		if(b[p]!=b[2*n-p+1])
		return;
	}
	int p=a[head],q=a[tail];
	path[x]='L';
	b[x]=p;
	dfs(x+1,head+1,tail);
	path[x]='R';
	b[x]=q;
	dfs(x+1,head,tail-1);
	b[x]=0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		flg=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i)
		scanf("%d",&a[i]);
		dfs(1,1,2*n);
		if(flg==0)
		printf("-1\n");
	}
	return 0;
}
/*
   c        c    ffffffff     n      n           m             m            ss    l
  c        c     f            nn     n          m m           m m          s      l
 c        c      f            n n    n         m   m         m   m        s       l
c        c       ffffffff     n  n   n        m     m       m     m       s       l
c        c       f            n   n  n       m       m     m       m       s      l
 c        c      f            n    n n      m         m   m         m       s     l
  c        c     f            n     nn     m           m m           m    s  s    l
   c        c    f            n      n    m             m             m     s     lllllllllll
   */
