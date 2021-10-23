#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct q{
	int s;int e;
	bool operator <(q &a)const
	{
		return s<a.s;
	}
};
q a1[100000+5];
q a2[100000+5];
int s1[100000+5];int s2[100000+5];
int r1;int r2;
int n,m1,m2;
queue<q> qq;
queue<q> qq2;
void print(int c,int s[])
{
	printf("\n");
	for(int i=0;i<=c;i++)
	{
		printf("%d ",s[i]);
	}
	printf("\n");
}
ll up(q a[],int m,ll ct)
{
	if(ct==0) return 0;
	while(qq.size()) qq.pop();
	int num=1;
	int nt=0;qq.push(a[1]);
	for(int i=2;i<=m;i++)
	{
		q t=qq.front();
		while(qq.size())
		{
			q t=qq.front();qq.pop();
			if(t.e>=a[i].s)
			{
				qq2.push(t);
			}
		}
		while(qq2.size())
		{
			qq.push(qq2.front());qq2.pop();
		}
		if(qq.size()+1<=ct)
		{			
			qq.push(a[i]);
			num++;
		}
    }
    return num;
}
void up1(q a[],int m,int f)
{
	int s[100000+5];
	while(qq.size()) qq.pop();
	int num=1;int ct=1;
	int nt=0;qq.push(a[1]);
	for(int i=2;i<=m;i++)
	{
		q t=qq.front();
		while(t.e<=a[i].s&&qq.size())
		{
			qq.pop();
			t=qq.front();
		}
		if(qq.size()+1<=ct)
		{			
			qq.push(a[i]);
			if(i==m) s[ct]=i;
		}
		else
		{
			s[ct]=i-1;
			ct++;
			qq.push(a[i]);
		}
    }
    if(f==1)
    {
    	for(int i=1;i<=ct;i++)
    	{
    		s1[i]=s[i];
		}
		r1=ct;
	}
	else
	{
		for(int i=1;i<=ct;i++)
		{
			s2[i]=s[i];
		}
		r2=ct;
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&a1[i].s,&a1[i].e);
	}	
	sort(a1+1,a1+1+m1);
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&a2[i].s,&a2[i].e);
	}
	sort(a2+1,a2+1+m2);
	if(n*(m1+m2)<=5000000)
	{
	    ll ans=-1;int idx=1;
		for(int i=0;i<=n;i++)
		{
			ans=max(up(a1,m1,i)+up(a2,m2,n-i),ans);
			idx=i;
		}
		cout<<ans;
	}
	else
	{
		ll ans=0;
		up1(a1,m1,1);up1(a2,m2,2);
		if(m1>m2)
		{
			if(r1<=n)
			{
				printf("%d",s1[r1]+s2[n-r1]);
			}
			else
			{
				ans=max(s1[r1]+s2[n-r1],s1[r2]+s1[n-r1]);
				printf("%d",ans);
			}
		}
		else if(m1<m2)
		{
			if(r2<=n) printf("%d",s2[r2]+s1[n-r2]);
			else 
			{
				ans=max(s1[r1]+s2[n-r1],s1[r2]+s1[n-r1]);
				printf("%lld",ans);
			}
		}
		else
		{
			ans=max(s1[r1]+s2[n-r1],s1[r2]+s1[n-r1]);
			printf("%d",ans);
		}
	}
	return 0;
}
