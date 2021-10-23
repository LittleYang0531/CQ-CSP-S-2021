#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn=1e5+5;
struct ss{
	int x,y;
}a[maxn];
struct gl{
	int e,r;
}b[maxn];
long long ans;
int cmp(ss a,ss b)
{
	return a.x<b.x;
}
int hanshu(gl a,gl b)	
{
	return a.e<b.e;
}
int p[maxn];
int w[maxn];
int u,o;
int s;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=k;i++)
	scanf("%d%d",&b[i].e,&b[i].r);
	sort(a+1,a+m+1,cmp);
	sort(b+1,b+k+1,hanshu);
	p[1]=a[1].y;
	u=o=0;
	for(int i=0;i<=n;i++)
	{
		s=n-i;
		o=u=1;
		if(s==0)
		u=0;
		if(i==0)
		o=0;
		memset(p,0,sizeof(p));
		memset(w,0,sizeof(w));
		p[1]=b[1].r;
		for(int j=2;j<=k;j++)
		{
			for(int d=1;d<=s;d++)
			{
				if(p[d]!=0)
				{
				    if(b[j].e>p[d])
				    {
					    u++;
					    p[d]=b[j].r;
					    break;
				    }
				}
				else if(p[d]==0)
				{
					u++;
					p[d]=b[j].r;
					break;
				}
			}
		}
		w[1]=a[1].y;
		for(int j=2;j<=m;j++)
		{
			for(int d=1;d<=i;d++)
			{
				if(w[d]==0)
				{
					o++;
					w[d]=a[j].y;
					break;
				}
				else if(w[d]!=0)
				{
					if(a[j].x>w[d])
					{
						o++;
						w[d]=a[j].y;
						break;
					}
				}
			}
		}
		if(o+u>ans)
		ans=o+u;
	}
	printf("%lld",ans);
	return 0;
}
