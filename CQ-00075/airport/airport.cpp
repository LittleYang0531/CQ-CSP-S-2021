#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+10;
struct node{
	int x,y,id,v;
}a[MAX];
int n,ans;
int su[2],l[2][MAX],m[5];
bool vis[MAX];
inline int read()
{
	int x=0,f=1;
	char ch = getchar();
	while(ch<'0' or ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
bool cmp(node xx,node yy)
{
	return xx.x<yy.x;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n = read(),m[0] = read(),m[1] = read(),m[2] = m[0]+m[1],m[3] = m[2]+m[2];
	for(int i = 1;i<=m[0];i++) 
	{
		a[i].x = read(),a[i].y = 1,a[i].id = 0,a[i].v = i;
		a[i+m[2]].x = read(),a[i+m[2]].y = -1,a[i+m[2]].id = 0,a[i+m[2]].v = i;
	}
	for(int i = m[0]+1;i<=m[2];i++) 
	{
		a[i].x = read(),a[i].y = 1,a[i].id = 1,a[i].v = i;
		a[i+m[2]].x = read(),a[i+m[2]].y = -1,a[i+m[2]].id = 1,a[i+m[2]].v = i;
	}
	sort(a+1,a+m[3]+1,cmp);
	for(int i = 1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		su[0] = 0,su[1] = 0;
		for(int j = 1;j<=m[3];j++)
		{
			if(a[j].y == 1 and su[a[j].id]<i) vis[a[j].v] = 1,l[a[j].id][i]++,su[a[j].id]++;
			if(a[j].y == -1 and vis[a[j].v]) su[a[j].id]--;
		}
	}
	for(int i = 0;i<=n;i++) ans = max(ans,l[0][i]+l[1][n-i]);
	printf("%lld",ans);
	return 0;
}
