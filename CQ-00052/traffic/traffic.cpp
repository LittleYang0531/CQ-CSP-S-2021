#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int Max=1e3+5;
int T,n,m,mi,rest,sum;
int Map[Max][Max][4],co[Max][Max],bo[Max][Max];
int nx[4]={1,-1,0,0};
int ny[4]={0,0,1,-1};//0->ÏÂ£¬1->ÉÏ£¬2->ÓÒ£¬3->×ó 

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f= ch=='-' ? -1:1;
	for(;ch<='9'&&ch>='0';ch=getchar()) x=(x<<1)+(x<<3)+(ch-'0');
	return x*f;
}

inline void update(int val,int pos,int clr)
{
	if(pos>m+n)
	{
		if(pos>2*m+n)
		{
			Map[2*n+2*m-pos+1][0][2]=Map[2*n+2*m-pos+1][1][3]=val;
			co[2*n+2*m-pos+1][0]=clr;
		}
		else 
		{
			Map[n+1][2*m+n-pos+1][1]=Map[n+1][2*m+n-pos+1][0]=val;
			co[n+1][2*m+n-pos+1]=clr; 
		}
	}
	else 
	{
		if(pos>m) 
		{
		    Map[pos-m][m+1][3]=Map[pos-m][m][2]=val;
		    co[pos-m][m+1]=clr;
		} 
		else
		{
		 	Map[0][pos][0]=Map[1][pos][1]=val;
		 	co[0][pos]=clr;
		}
	}
}

inline void dfs(int x,int y)
{
	if(mi<sum) return;
	if(!rest) {
		mi=min(sum,mi);
		return;
	}
	for(int tims=0;tims<=1;tims++)
	for(int i=0;i<3;i++)
	{
			int xx=nx[i]+x;
			int yy=ny[i]+y;
			if(!bo[xx][yy]&&xx>=0&&xx<=n+1&&yy>=0&&yy<=m+1&&Map[x][y][i]!=-1)
			{
				if(co[xx][yy]!=co[x][y]) bo[xx][yy]=1,rest--,sum+=Map[x][y][i],dfs(xx,yy);
				else bo[xx][yy]=1,rest--,dfs(xx,yy);
			}
	}
 } 

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	while(T--){
		int k;
		for(int i=0;i<=n+1;i++) for(int j=0;j<=m+1;j++) for(int cor=0;cor<=3;cor++) Map[i][j][cor]=-1;
		for(int i=1;i<n;i++) for(int j=1;j<=m;j++) Map[i][j][0]=Map[i+1][j][1]=read();
		for(int i=1;i<=n;i++) for(int j=1;j<m;j++) Map[i][j][2]=Map[i][j+1][3]=read();
		scanf("%d",&k);
		int val,p,clr;
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d%d",&val,&p,&clr);
			update(val,p,clr);
		}
		for(int ss=1;ss<=3000;ss++)
		{
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) co[i][j]&=1;
		mi=0x3f3f3f3f;sum=0;rest=k+n*m-1;
		for(int i=0;i<=1;i++) dfs(1,1);
		}
		
		printf("%d\n",mi);
	}
	return 0;
}
