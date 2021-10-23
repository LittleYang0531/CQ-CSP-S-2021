#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+50;

int n,m1,m2;
struct Plane
{
	int l,r,Cnt;
};
bool cmp(Plane x,Plane y)
{
	return x.l<y.l;
}
Plane a[MAXN],b[MAXN];
int ans=0;
int Sum1[MAXN],Sum2[MAXN];
bool flag[MAXN];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&b[i].l,&b[i].r);
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	int n1=0,n2=0;
	for(int i=1;i<=m1;i++)
	{
		if(flag[i]==true)
		continue;
		n1++;
		Sum1[n1]=Sum1[n1-1]+1;
		int r=i;
		while(true)
		{
			int L=r+1,R=m1,Mid,New=0;
			while(L<=R)
			{
			//	cout<<L<<" "<<R<<endl;
				Mid=(L+R)>>1;
				if(a[Mid].l>a[r].r)
				{
					New=Mid;
					R=Mid-1;
				}
				else
				{
					L=Mid+1;
				}
			}
			//cout<<New<<" ";
			while(flag[New])
			New++;
			if(New!=0&&New<=m1)
			{
				r=New;
				flag[r]=true;
				Sum1[n1]++;
			}
			else
			{
				break;
			}
		}
	//	cout<<endl;
	}
//	for(int i=1;i<=n1;i++)
//	cout<<Sum1[i]<<" ";
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=m2;i++)
	{
		if(flag[i]==true)
		continue;
		n2++;
		Sum2[n2]=Sum2[n2-1]+1;
		int r=i;
		while(true)
		{
			int L=r+1,R=m1,Mid,New=0;
			while(L<=R)
			{
			//	cout<<L<<" "<<R<<endl;
				Mid=(L+R)>>1;
				if(b[Mid].l>b[r].r)
				{
					New=Mid;
					R=Mid-1;
				}
				else
				{
					L=Mid+1;
				}
			}
			//cout<<New<<" ";
			while(flag[New])
			New++;
			if(New!=0&&New<=m2)
			{
				r=New;
				flag[r]=true;
				Sum2[n2]++;
			}
			else
			{
				break;
			}
		}
	//	cout<<endl;
	}
	for(int i=0;i<=n1&&i<=n;i++)
	{
	//	cout<<Sum1[i]+Sum2[min(n-i,m2)]<<" ";
		ans=max(ans,Sum1[i]+Sum2[min(n-i,m2)]);
	}
	cout<<ans;
	return 0;
}
