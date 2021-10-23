#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#define int long long
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
int n,m,T;
int f[505][505][4];//обсриовС 
struct node
{
	int k;
	int d[55],px[55],py[55],col[55];
}a[55];
struct aha{int x,y,col;}s,t;
int ans[55];
bool col[505][505];
void DFS(int x,int y)
{
	if(x==n+1&&y==1)
	{
		int tot=0,tmp;
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(col[i][j]^col[i+1][j])tot+=f[i][j][0];
			if(col[i][j]^col[i][j+1])tot+=f[i][j][1];
		}
		for(int i=1;i<=T;++i)
		{
			tmp=0;
			for(int j=1;j<=a[i].k;++j)
			if(col[a[i].px[j]][a[i].py[j]]^a[i].col[j])tmp+=a[i].d[j];
			ans[i]=min(ans[i],tot+tmp);
		}
		return;
	}
	if(y==m)
	{
		DFS(x+1,1);
		col[x][y]=1;
		DFS(x+1,1);
		col[x][y]=0;
	}
	else
	{
		DFS(x,y+1);
		col[x][y]=1;
		DFS(x,y+1);
		col[x][y]=0;
	}
	
}
void Work(int num,int &i,int &j)
{
	if(num>=1&&num<=m)
	{
		i=1;j=num;
	}
	else if(num>m&&num<=n+m)
	{
		i=num-m;j=m;
	}
	else if(num>n+m&&num<=n+(m<<1))
	{
		i=n;j=m-(num-n-m)+1;
	}
	else 
	{
		i=n-(num-n-(m<<1))+1;j=1;
	}
}
int F[505][505];
bool vst[505][505];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void AHA(int x,int y)
{
	for(int i=0;i<4;++i)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<1||nx>n||ny<1||ny>m)continue;
		if(F[nx][ny]>F[x][y]+f[x][y][i])
		{
			F[nx][ny]=F[x][y]+f[x][y][i];
			AHA(nx,ny);
		}
	}
}
signed main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=rd();m=rd();T=rd();
	memset(ans,0x3f,sizeof(ans));
	for(int i=1;i<=n-1;++i)
	for(int j=1;j<=m;++j)
	f[i][j][0]=f[i+1][j][2]=rd();
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m-1;++j)
	f[i][j][1]=f[i][j+1][3]=rd();
	if(n<=5&&m<=5)
	{
		for(int i=1;i<=T;++i)
		{
			a[i].k=rd();
			for(int j=1;j<=a[i].k;++j){a[i].d[j]=rd();Work(rd(),a[i].px[j],a[i].py[j]);a[i].col[j]=rd();}
		}
		DFS(1,1);
		for(int i=1;i<=T;++i)pt(ans[i],'\n');return 0;
	}
	int tmp,num1,num2;
	int k;
	for(int i=1;i<=T;++i)
	{
		num1=num2=0x3f3f3f3f3f3f3f3f;
		memset(F,0x3f,sizeof(F));
		k=rd();
		if(k==1){num1=rd();rd();rd();}
		else
		{
			num1=rd();rd();rd();num2=rd();rd();rd();
			for(int j=3;j<=k;++j){rd();rd();rd();}
		}
//		rd();Work(rd(),s.x,s.y);s.col=rd();
//		rd();Work(rd(),t.x,t.y);t.col=rd();
		s.x=s.y=1;t.x=n;t.y=m;
		F[s.x][s.y]=0;
		AHA(s.x,s.y);
//		for(int j=1;j<=n;++j)
//		{
//			for(int K=1;K<=m;++K)cout<<F[j][K]<<" ";cout<<endl;
//		}
		pt(min(num1,min(num2,F[t.x][t.y])),'\n');
	}
	return 0;
}

