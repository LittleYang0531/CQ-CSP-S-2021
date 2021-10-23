#include<bits/stdc++.h>

using namespace std;
const int MAXN=505,MAXM=6e5+50;
//f[i][j]表示i开始,j结束的划分，需要的最小代价
//i,j可以用网格边缘射线法表示
//所以是tm的弗洛伊德
/*
枚举任意两个附加点，50*49/2
枚举最小值：O(1) 
*/ 

int n,m,T;
long long dis[MAXN][MAXN];
bool Can(int x,int y)
{
	if(x<1||x>n||y<1||y>m)
	return false;
	return true;
}
int Id(int x,int y)
{
	return (x-1)*m+y;
}
int Pid(int x)
{
	if(x<=m)
	return Id(1,x);
	if(x<=m+n)
	return Id(x-m,m);
	if(x<=2*m+n)
	return Id(n,m-(x-m-n)+1);
	return Id(2*(n+m)-x+1,1);
}
void Main1()
{
	int P[80],Color[80],val[80];
	
	int t;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&t);
			if(Can(i+1,j+1))
			{
				dis[Id(i+1,j)][Id(i+1,j+1)]=dis[Id(i+1,j+1)][Id(i+1,j)]=t;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			scanf("%d",&t);
			if(Can(i+1,j+1))
			{
				dis[Id(i,j+1)][Id(i+1,j+1)]=dis[Id(i+1,j+1)][Id(i,j+1)]=t;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			if(Can(i,j+1)&&dis[Id(i,j)][Id(i,j+1)]>1e15)
			{
				dis[Id(i,j)][Id(i,j+1)]=dis[Id(i,j+1)][Id(i,j)]=0;
			}
			if(Can(i+1,j)&&dis[Id(i,j)][Id(i+1,j)]>1e15)
			{
				dis[Id(i,j)][Id(i+1,j)]=dis[Id(i+1,j)][Id(i,j)]=0;
			}
		}
	}
	for(int k=1;k<=n*m;k++)
	{
		for(int i=1;i<=n*m;i++)
		{
			if(i==k)
			continue;
			for(int j=1;j<=n*m;j++)
			{
				if(j==k||j==i)
				continue;
				if(dis[i][k]+dis[k][j]<=dis[i][j])
				{
					dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
//	for(int i=1;i<=n*m;i++)
//	{
//		for(int j=1;j<=n*m;j++)
//		{
//			cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
//		}
//	}
	while(T--)
	{
		memset(P,0,sizeof(P));
		memset(Color,0,sizeof(Color));
		memset(val,0,sizeof(val));
		int k;
		scanf("%d",&k);
		long long ans=1e18;
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d%d",&val[i],&P[i],&Color[i]);
			for(int j=1;j<i;j++)
			{
				if(Color[j]!=Color[i])
				{
				//	cout<<Pid(P[i])<<" "<<Pid(P[j])<<" "<<dis[4][3]<<endl; 
					ans=min((long long)val[i],min((long long)val[j],dis[Pid(P[i])][Pid(P[j])]));
				}
			}
		}
		printf("%lld\n",ans);
	}
	
	
	return;
}
void Main2()
{
	
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&T);
	if(n*m<=1000)
	{
		Main1();
	}
	else
	{
		Main2();
	}
	
	

	return 0;
}
