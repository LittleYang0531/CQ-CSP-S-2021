#include<bits/stdc++.h>
#define R register int
#define I inline
#define ll long long
using namespace std;
const int N=503,P=1e9+7;
I void pls(int &a,const int &b){a+=b;if(a>=P)a-=P;}
I int add(const int &a,const int &b){return a+b>=P?a+b-P:a+b;}
char s[N];
int f[N][N],g[N][N],h[N][N],to[N];
bool is(int x,char c)
{
	if(s[x]=='?')return 1;
	return c==s[x];
}
bool rg(int l,int r){return to[l]>=r;}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(R i=n,j=0;i;i--)
	{
		if(!is(i,'*'))j=0;
		else if(j==0)j=i;
		to[i]=j==0?i-1:j;
	}
//	for(R i=1;i<=n;i++)printf("-> %d %d\n",i,to[i]);
	for(R i=1;i<n;i++)if(is(i,'(')&&is(i+1,')'))f[i][i+1]=g[i][i+1]=h[i][i+1]=1;
	for(R l=3;l<=n;l++)
	{
		for(R i=1,j=i+l-1;j<=n;i++,j++)
		{
			int w=0,t=0;
			if(is(i,'(')&&is(j,')'))
			{
				w=f[i+1][j-1];
//				printf("! %d %d %d\n",i,j,f[i+1][j-1]);
				for(R k=1;k<=m&&i+k+1<j-1;k++)
				{
					if(!rg(i+1,i+k))break;
					pls(w,f[i+k+1][j-1]);
				}
				for(R k=1;k<=m&&j-k-1>i+1;k++)
				{
					if(!rg(j-k,j-1))break;
					pls(w,f[i+1][j-k-1]);
				}
				if(rg(i+1,j-1)&&j-i-1<=m)pls(w,1);
			}
			for(R k=i+1;k<j;k++)
			{
				ll v=g[k][j]-g[min(k+m-1,to[k])+2][j];
				if(v<0)v+=P;
				t=(t+h[i][k-1]*v)%P;
//				printf("$$ %d %d %d %d %lld\n",i,j,k,f[i][k-1],v);
			}
			h[i][j]=w;f[i][j]=add(w,t);
			g[i][j]=add(g[i+1][j],f[i][j]);
		}
	}
//	for(R i=1;i<=n;i++)
//		for(R j=1;j<=i;j++)
//			printf("F %d %d %d %d\n",j,i,f[j][i],g[j][i],h[j][i]);
	printf("%d\n",f[1][n]);
}
