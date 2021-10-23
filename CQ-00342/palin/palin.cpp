#include<bits/stdc++.h>
using namespace std;

const int N=55;
int a[N],ans[N],b[N],n;
bool flag;

inline int read()
{
	int x=0,f=1; char ch=getchar();
	while( ch < '0' or ch > '9' ) f *= ch=='-' ? -1 : 1, ch=getchar();
	while( ch >= '0' and ch <' 9' ) x=x*10+ch-'0', ch=getchar();
	return x*f;
}

inline void dfs(int stp,int l,int r)
{
	if(flag) return;
	if( stp==2*n )
	{
		bool vis=0;
		b[2*n]=a[l];
//		for(int i=1;i<=2*n;i++) cout<<b[i]<<" "; cout<<endl;
//		for(int i=1;i<=2*n;i++) printf("%c",ans[i] ? 'R' : 'L'); cout<<endl;
		for(int i=1;i<=n;i++) if( b[i]!=b[2*n-i+1] ) vis=1;
		if( !vis ) flag=1,ans[2*n]=0;
		return;
	}
	if( flag ) return;
	b[stp]=a[l]; ans[stp]=0; dfs(stp+1,l+1,r);
	if( flag ) return;
	b[stp]=a[r]; ans[stp]=1; dfs(stp+1,l,r-1);
}

inline void work()
{
	n=read();
	for(int i=1;i<=2*n;i++) a[i]=read();
	flag=0;
	dfs(1,1,2*n);
	if( flag==0 ) printf("-1");
	else for(int i=1;i<=2*n;i++) printf("%c",ans[i] ? 'R' : 'L');
	printf("\n");
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=read();
	while( T-- ) work();
	return 0;
}
