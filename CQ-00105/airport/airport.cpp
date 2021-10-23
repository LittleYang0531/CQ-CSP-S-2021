#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#define R_ register
#define ll long long
using namespace std;

int n,ans;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
struct qj{
	int l,r;
};
inline bool cmp(const qj &a,const qj &b){
	return a.l<b.l;
}
set<int>s;
set<int>::iterator it;
	int pos[100005],bl[100005],pp,tot,t[100005];
	qj a[100005];
struct quj{
	int m,as[100005];
	inline void solve()
	{
		memset(t,0,sizeof(t));
		memset(as,0,sizeof(as));
		memset(bl,0,sizeof(bl));
		memset(pos,0,sizeof(pos));
		pp=0;tot=0;
		for(R_ int i=1;i<=m;i++){
			a[i].l=read();
			a[i].r=read();
			t[++pp]=a[i].l;
			t[++pp]=a[i].r;
		}
		sort(t+1,t+1+pp);
		s.clear();
		for(R_ int i=1;i<=m;++i){
			a[i].l=lower_bound(t+1,t+1+pp,a[i].l)-t;
			a[i].r=lower_bound(t+1,t+1+pp,a[i].r)-t;
		}
		sort(a+1,a+1+m,cmp);
		for(R_ int i=1;i<=m;++i){
			pos[a[i].l]=i;
			s.insert(a[i].l);
		}
		for(R_ int i=1;i<=m;++i){
			if(!bl[i]){
				++tot;
				if(tot>n)break;
				int x=i;
				do{
					bl[x]=tot;
					++as[tot];
					s.erase(a[x].l);
					if(!s.size())break;
					it=s.end();--it;
					if(*it<a[x].r)break;
					it=s.upper_bound(a[x].r);
					x=pos[*it];
				}while(x);
			}
		}
	}
	void qzh(){
		for(R_ int i=1;i<=n;++i)as[i]+=as[i-1];
	}
}T1,T2;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	T1.m=read();
	T2.m=read();
	T1.solve();
	T2.solve();
	T1.qzh();
	T2.qzh();
	for(int i=0;i<=n;++i)ans=max(ans,T1.as[i]+T2.as[n-i]);
	cout<<ans<<"\n";
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16


2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
