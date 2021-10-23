#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
int n,k;
char s[505];
char p[505];
__int128 q;
int ans;
bool check(int l,int r)
{
	if(p[l]=='*'||p[r]=='*')
	return 0;
	if(r==l)
	return 1;
	for(int i=l+1;i+1<r;++i)
	{
		if(check(l,i)&&check(i+1,r))
		return 1;
	}
	int x=1,y=r;
	for(int i=l;i<=r;++i)
	{
		if(p[i]=='*')
		return 0;
	}
	return 0;
}
void dfs(int x,int l,int r,int bj)
{
	if(r>l)
	return;
	if(x>n)
	{
		if(l!=r||!check(1,n))
		return;
		for(int i=1;i<=n;++i)
		cout<<p[i];
		cout<<endl;
		ans++;
		return;
	}
	char q=p[x];
	if(p[x]!='?')
	{
		if(p[x]=='(')
		dfs(x+1,l+1,r,0);
		else if(p[x]==')')
		dfs(x+1,l,r+1,0);
		else if(p[x]=='*')
		dfs(x+1,l,r,bj+1);
	}
	else
	{
		p[x]='(';
		dfs(x+1,l+1,r,0);
		p[x]=')';
		dfs(x+1,l,r+1,0);
		p[x]='*';
		dfs(x+1,l,r,bj+1);
	}
	p[x]=q;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s+1;
	for(int i=1;i<=n;++i)
	p[i]=s[i];
	cout<<1<<endl;
	return 0;
}
/*
       m             m             j    l            n      n     bbb
      m m           m m                 l            nn     n     b  b
     m   m         m   m           j    l            n n    n     b  b
    m     m       m     m          j    l            n  n   n     b b
   m       m     m       m         j    l            n   n  n     b b
  m         m   m         m     j  j    l            n    n n     b  b
 m           m m           m     j j    l            n     nn     b  b
m             m             m     j     llllllllll   n      n     bbb
*/
