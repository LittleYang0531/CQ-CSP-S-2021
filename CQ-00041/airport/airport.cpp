#include<bits/stdc++.h>
using namespace std;
long long n,p,q,fa[100005],fa1[100005],xin[100005],xin1[100005],tot,tot1,d[100005],d1[100005],maxn;
struct dog{long long x,y;}a[100005],b[100005];
bool cmp(dog x,dog y){return x.x<y.x;}
long long gf(long long x){return x==fa[x]?x:fa[x]=gf(fa[x]);}
long long gf1(long long x){return x==fa1[x]?x:fa1[x]=gf1(fa1[x]);}
void merge(long long x,long long y){long long i=gf(x),j=gf(y);if(i!=j) fa[j]=i;}
void merge1(long long x,long long y){long long i=gf1(x),j=gf1(y);if(i!=j) fa1[j]=i;}
queue<long long> e;
priority_queue<long long,vector<long long>,greater<long long> > q1,q2;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&p,&q);
	for(long long i=1;i<=p;fa[i]=i,i++) scanf("%lld%lld",&a[i].x,&a[i].y);
	for(long long i=1;i<=q;fa1[i]=i,i++) scanf("%lld%lld",&b[i].x,&b[i].y);
	sort(a+1,a+p+1,cmp);
	sort(b+1,b+q+1,cmp);
	for(long long i=1;i<=p;i++){
		if(q1.empty()){
			q1.push(a[i].y*1000000+(1000000-i));
		}
		else if(q1.top()>a[i].x*1000000){
			q1.push(a[i].y*1000000+(1000000-i));
		}else {
			long long minn=0x3f3f3f3f3f3f3f;
			while(!q1.empty()&&!(q1.top()>a[i].x*1000000)){
				long long g=q1.top();e.push(g),q1.pop();
				minn=min(-g%1000000+1000000,minn);
			}
			merge(minn,i);
			q1.push(a[i].y*1000000+(1000000-minn));
			while(!e.empty()){
				long long rt=e.front();e.pop();
				if(-rt%1000000+1000000!=minn) q1.push(rt);
			}	
		}
	}
	for(long long i=1;i<=q;i++){
		if(q2.empty()){
			q2.push(b[i].y*1000000+(1000000-i));
		}
		if(q2.top()>b[i].x*1000000){
			q2.push(b[i].y*1000000+(1000000-i));
		}else {
			long long minn=0x3f3f3f3f3f3f3f;
			while((!q2.empty())&&q2.top()<(b[i].x*1000000)){
				long long g=q2.top();e.push(g),q2.pop();
				minn=min(-g%1000000+1000000,minn);
			}
			merge1(minn,i);
			q2.push(b[i].y*1000000+(1000000-minn));
			while(!e.empty()){
				long long rt=e.front();e.pop();
				if(-rt%1000000+1000000!=minn) q2.push(rt);
			}	
		}
	}
	for(long long i=1;i<=p;i++){
		if(fa[i]==i) xin[i]=++tot;
	}
	for(long long i=1;i<=q;i++){
		if(fa1[i]==i) xin1[i]=++tot1;
	}
	for(long long i=1;i<=p;i++)
		d[xin[gf(i)]]++;
	for(long long i=1;i<=q;i++)
		d1[xin1[gf1(i)]]++;
	for(long long i=1;i<=tot;i++)
		d[i]+=d[i-1];
	for(long long i=1;i<=tot1;i++)
		d1[i]+=d1[i-1];
	for(long long i=0;i<=n;i++){
		maxn=max(d[i]+d1[n-i],maxn);
	}
	printf("%lld",maxn);
	return 0;
}
