#include<bits/stdc++.h>
using namespace std;
struct plane
{
	int x;
	int y;
};
int n,m1,m2,t[120000]={0},tt[120000]={0};
plane a[150000],b[150000]; 
bool cmp(plane x1,plane x2)
{
	return x1.x<x2.x;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);	
	int t1,t2,cnt=0,tcnt=0,ttcnt=0,tot=0,maxx=0;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=m2;i++)scanf("%d%d",&b[i].x,&b[i].y);
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	for(int i=0;i<=n;i++)
	{
		t1=i;
		t2=n-i;
		cnt=tot=0;
		for(int j=1;j<=m1;j++)
		{
			if(cnt<t1)
			{
				for(int k=1;k<=m1;k++)
				{
					if(t[k]<=a[j].x&&t[k]!=0)
					{
						t[k]=0;
						cnt--;
					}
				}
				t[++tcnt]=a[j].y;
				cnt=min(++cnt,n);
				tot++;
			}
		}
	//	cout<<tot<<" ";
		cnt=0;
		for(int j=1;j<=m2;j++)
		{
			if(cnt<t2)
			{
				for(int k=1;k<=m2;k++)
				{
					if(tt[k]<=a[j].x&&tt[k]!=0)
					{
						tt[k]=0;
						cnt--;
					}
				}
				tt[++ttcnt]=a[j].y;
				cnt=min(++cnt,n);
				tot++;
			}
		}
		//cout<<tot<<endl;
		maxx=max(maxx,tot);
	}
	cout<<maxx;
	return 0;
}
