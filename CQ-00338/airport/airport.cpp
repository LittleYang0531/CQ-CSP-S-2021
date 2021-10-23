#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,ans1,ans2,ans;
int r[1000005];
struct ti{
	long long s,t;
}T1[1000005],T2[1000005];
bool cmp(ti a,ti b)
{
	if(a.s<b.s) return 1;
	else return 0;
}
void check1(int x)
{
	ans1=0;
	memset(r,0,sizeof(r));
	int y=min(m1,x);
	ans1+=y;
	for(int i=1;i<=y;i++)
		r[i]=i;
	for(int i=y+1;i<=m1;i++)
		for(int j=1;j<=y;j++)
		{
			if(T1[i].s>T1[r[j]].t)
			{
				r[j]=i;
				ans1++;
				break;
			}
		}
}
void check2(int x)
{
	ans2=0;
	memset(r,0,sizeof(r));
	int y=min(m2,x);
	ans2+=y;
	for(int i=1;i<=y;i++)
		r[i]=i;
	for(int i=y+1;i<=m2;i++)
		for(int j=1;j<=y;j++)
		{
			if(T2[i].s>T2[r[j]].t)
			{
				r[j]=i;
				ans2++;
				break;
			}
		}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
		cin>>T1[i].s>>T1[i].t;
	for(int i=1;i<=m2;i++)
		cin>>T2[i].s>>T2[i].t;
	sort(T1+1,T1+m1+1,cmp);
	sort(T2+1,T2+m2+1,cmp);
	for(int i=0;i<=n;i++)
	{
		check1(i);
		check2(n-i);
		int sum=ans1+ans2;
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
