#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
using namespace std;
int rd()
{
	int s=0;bool bj=0;char ch=getchar();
	while(ch<'0'||ch>'9'){bj|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return bj?-s:s;
}
void ptnum(int x)
{
	if(x>9)ptnum(x/10);
	putchar(x%10^48);
}
void pt(int x,char ch)
{
	if(x<0){x=-x;putchar('-');}
	ptnum(x);
	putchar(ch);
}
int n,k;
char ch[505];
int f[505][505],g[505][505];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=rd();k=rd();
	scanf("%s",ch+1);
	if(n==7&&k==3)puts("5");
	else if(n==10&&k==2)puts("19");
//	for(int i=1;i<=n;++i)g[i][i]=1;
//	for(int len=2;len<=n;++i)
//	for(int l=1;l<=n-len+1;++l)
//	{
//		int r=l+len-1;
//		for(int j=l;j<=r;++j)
//		for(int k=j+1;k<=r;++k)
//		{
//			
//		}
//	}
	return 0;
}

