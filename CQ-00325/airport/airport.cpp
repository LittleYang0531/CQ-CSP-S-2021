#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;
char buf[1<<23],*p1,*p2;
#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2))?EOF:*p1++)
inline void rd(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}
struct Flight{
	int l,r;
	bool operator <(const Flight &ano)const
	{
		return l<ano.l;
	}
}flight1[100005],flight2[100005];
struct Element{
	int num,l,r;
	Element(int num=0,int l=0,int r=0):num(num),l(l),r(r){
		
	}
	bool operator <(const Element &ano)const
	{
		return l<ano.l;
	}
};
int n,m1,m2;
int ans1[100005],ans2[100005];
set<Element>s;
Element st[100005];
int top;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	rd(n),rd(m1),rd(m2);
	for(int i=1;i<=m1;++i)
	{
		rd(flight1[i].l),rd(flight1[i].r);
	}
	for(int i=1;i<=m2;++i)
	{
		rd(flight2[i].l),rd(flight2[i].r);
	}
	for(int i=1;i<=m1;++i)
	{
		s.insert(Element(i,flight1[i].l,flight1[i].r));
	}
	for(int i=1;!s.empty();++i)
	{
		set<Element>::iterator iter=s.begin();
		while(iter!=s.end())
		{
			st[++top]=*iter;
			iter=s.lower_bound(Element(0,iter->r,0));
		}
		ans1[i]=top;
		while(top)s.erase(s.find(st[top--]));
	}
	for(int i=1;i<=m2;++i)
	{
		s.insert(Element(i,flight2[i].l,flight2[i].r));
	}
	for(int i=1;!s.empty();++i)
	{
		set<Element>::iterator iter=s.begin();
		while(iter!=s.end())
		{
			st[++top]=*iter;
			iter=s.lower_bound(Element(0,iter->r,0));
		}
		ans2[i]=top;
		while(top)s.erase(s.find(st[top--]));
	}
	int sum1=0,sum2=0,ans=0;
	for(int i=1;i<=n;++i)sum2+=ans2[i];
	for(int i=0;i<=n;++i)
	{
		sum1+=ans1[i];
		if(i!=0)sum2-=ans2[n-i+1];
		ans=max(ans,sum1+sum2);
	}
	cout<<ans;
	return 0;
}
