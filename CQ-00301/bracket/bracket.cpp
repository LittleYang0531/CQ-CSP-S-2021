#include<iostream>
#include<cstdio>
const int N=505,mod=1e9+7;
using namespace std;
int f[N][N][4];//0:A   1:SA/A   2:SA/AS/A   3:(...)
char a[N];
int n,k;
//#define getchar gc
inline int read()
{
	char h=getchar();
	int y=0,q=1;
	while(h<'0'||h>'9'){if(h=='-')q=-1;h=getchar();}
	while(h>='0'&&h<='9')y=y*10+h-'0',h=getchar();
	return y*q;
}
inline bool check(int x,char s)
{
	return a[x]=='?'||a[x]==s;
}
int dfs(int l,int r,int op)
{
	if(l>=r)return 0;
	if(f[l][r][op]!=-1)return f[l][r][op];
	int su=0;
	if(check(l,'(')&&check(r,')'))
	{
		if(r-l-1<=k)
		{
			bool fl=1;
			for(int i=l+1;i<r;i++)fl&=check(i,'*');
			if(fl)su++;
		}
		su+=dfs(l+1,r-1,2);
		if(su>=mod)su-=mod;
	}
	f[l][r][3]=su;
	for(int i=l;i<r;i++)
	{
		su+=1ll*dfs(l,i,3)*dfs(i+1,r,1)%mod;
		if(su>=mod)su-=mod;
	}
	f[l][r][0]=su;
	for(int i=l;i<=min(r-1,l+k-1);i++)
	if(check(i,'*'))
	{
		su+=dfs(i+1,r,0);
		if(su>=mod)su-=mod;
	}
	else break;
	f[l][r][1]=su;
	for(int i=r;i>=max(l+1,r-k+1);i--)
	if(check(i,'*'))
	{
		su+=dfs(l,i-1,0);
		if(su>=mod)su-=mod;
	}
	else break;
	f[l][r][2]=su;
//	cout<<l<<" "<<r<<" "<<op<<" "<<f[l][r][op]<<"!!!\n";
	return f[l][r][op];
}
int main()
{
//	cout<<((&me1-&me2)>>20)<<"!!!\n";
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)f[i][j][0]=f[i][j][1]=f[i][j][2]=f[i][j][3]=-1;
	scanf("%s",a+1);
//	for(int i=1;i<=n;i++)a[i]='?';k=500;
	cout<<dfs(1,n,0)<<"\n";
	return 0;
}
/*
7 3
(*??*??
*/
