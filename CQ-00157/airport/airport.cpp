#include<queue>
#include<cstdio>
#include<algorithm>
const int maxn=5005;
struct _{
	int l, r;
	bool operator<(const _ q)const{ return r>q.r; }
}a[maxn],b[maxn];
int n,m1,m2,p,u,d,ans;
std::priority_queue<_>q;
inline bool cmp(_ x,_ y){ return x.l<y.l; }
inline int max(int x,int y){ return x>y?x:y; }
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i)
		scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=1;i<=m2;++i)
		scanf("%d%d",&b[i].l,&b[i].r);
	std::sort(a+1,a+m1+1,cmp);
	std::sort(b+1,b+m2+1,cmp);
	for(int i=0;i<=n;++i){
		u=0; d=0; p=i;
		while(q.size()) q.pop();
		for(int j=1;j<=m1;++j){
			while(q.size()&&q.top().r<a[j].l){ q.pop(); ++p; }
			if(p){ ++u; q.push(a[j]); --p; }
		}
		p=n-i;
		while(q.size()) q.pop();
		for(int j=1;j<=m2;++j){
			while(q.size()&&q.top().r<b[j].l){ q.pop(); ++p; }
			if(p){ ++d; q.push(b[j]); --p; }
		}
		ans=max(ans,u+d);
	}
	printf("%d",ans);
	return 0;
}

