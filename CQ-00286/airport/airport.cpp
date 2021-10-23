#include<bits/stdc++.h>
using namespace std;
long long t,n,m1,m2,c[200005],d[200005],ans[100005],ans2[100005],tnt=0,tot=0,tot2=0,t1[200005],t2[200005],d1[100005],d2[100005];
struct node{
	long long e;
	bool operator <(const node &A) const{
		return e>A.e;
	}
};
priority_queue<node> q;
struct ok{
	long long x,y;
	bool operator <(const ok &A) const{
		return y>A.y;
	}
}a[100005],b[100005];
priority_queue<ok> q2;
long long find(long long k,long long g){
	long long f=1,mid,l;
	if(g==1){
		l=2*m1;
		while(f<=l){
			mid=(f+l)>>1;
			if(c[mid]==k) return mid;
			if(c[mid]<k) f=mid+1;
			else l=mid-1;
		}
	} 
	else{
		l=2*m2;	
		while(f<=l){
			mid=(f+l)>>1;
			if(d[mid]==k) return mid;
			if(d[mid]<k) f=mid+1;
			else l=mid-1;
		}
	} 
	
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for(long long i=1;i<=m1;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		c[i]=a[i].x,c[i+m1]=a[i].y;
	}
	for(long long i=1;i<=m2;i++){
		scanf("%lld%lld",&b[i].x,&b[i].y);
		d[i]=b[i].x,d[i+m2]=b[i].y;
	}
	sort(c+1,c+m1+m1+1);
	sort(d+1,d+1+m2+m2);
	for(long long i=1;i<=m1;i++) t1[find(a[i].x,1)]=find(a[i].y,1),t1[find(a[i].y,1)]=-1;
	for(long long i=1;i<=m2;i++) t2[find(b[i].x,2)]=find(b[i].y,2),t2[find(b[i].y,2)]=-1;
	for(long long i=100000;i>=1;i--) q.push((node){i});
	for(long long i=1;i<=m1*2;i++){
		t=q.top().e;
		if(t1[i]>0){
			q2.push((ok){t,t1[i]});
			ans[t]++;
			q.pop();
		}
		if(t1[i]<0){
			q.push((node){q2.top().x});
			q2.pop();
		}
	}
	for(long long i=1;i<=m2*2;i++){
		t=q.top().e;
		if(t2[i]>0){
			q2.push((ok){t,t2[i]});
			ans2[t]++;
			q.pop();
		}
		if(t2[i]<0){
			q.push((node){q2.top().x});
			q2.pop();
		}
	}
	for(long long i=1;i<=n;i++) ans[i]+=ans[i-1],ans2[i]+=ans2[i-1];
	for(long long i=0;i<=n;i++) tnt=max(tnt,ans[i]+ans2[n-i]);
	printf("%lld",tnt);
	return 0;
}
