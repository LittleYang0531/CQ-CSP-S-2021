#include<bits/stdc++.h>
using namespace std;
const int M=3e5+5;
int n,m,k,xsh,cnt,ans,sum[M],sum2[M],tot;
int lsh[M],vis[M];
struct node{
	int l,r;
};
node a[M],b[M];
struct pp{
	int x,y,z;
};
pp yzk[M];
bool cmp(node x,node y){
	return x.l<y.l;
}
bool cmmp(pp l,pp r){
	return l.x<r.x;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&k,&n,&m);
	xsh=2*n+2*m+5;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].l,&a[i].r);
		lsh[++cnt]=a[i].l;
		lsh[++cnt]=a[i].r;
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&b[i].l,&b[i].r);
		lsh[++cnt]=b[i].l;
		lsh[++cnt]=b[i].r;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+m+1,cmp);
	sort(lsh+1,lsh+cnt+1);
	cnt=unique(lsh+1,lsh+cnt+1)-(lsh+1);
	for(int i=1;i<=n;i++){
		a[i].l=lower_bound(lsh+1,lsh+cnt+1,a[i].l)-lsh;
		a[i].r=lower_bound(lsh+1,lsh+cnt+1,a[i].r)-lsh;
	}
	for(int i=1;i<=m;i++){
		b[i].l=lower_bound(lsh+1,lsh+cnt+1,b[i].l)-lsh;
		b[i].r=lower_bound(lsh+1,lsh+cnt+1,b[i].r)-lsh;
	}
	int lst=0;
	for(int i=1;i<=n;i++){
		yzk[++tot].x=a[i].l;
		yzk[tot].y=0;
		yzk[tot].z=i;
		yzk[++tot].x=a[i].r;
		yzk[tot].y=1;
		yzk[tot].z=i;
	}
	sort(yzk+1,yzk+tot+1,cmmp);
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=1;i<=xsh;i++){
		q.push(i);
	}
	for(int i=1;i<=tot;i++){
		if(yzk[i].y==0){
			int op=q.top();
			sum[op]++;
			vis[yzk[i].z]=op;
			q.pop();
		}
		else{
			int xpx=vis[yzk[i].z];
			q.push(xpx);
		}
	}
	for(int i=0;i<=xsh;i++){
		vis[i]=0;
	}
	while(q.size()) q.pop();
	tot=0;
	for(int i=1;i<=m;i++){
		yzk[++tot].x=b[i].l;
		yzk[tot].y=0;
		yzk[tot].z=i;
		yzk[++tot].x=b[i].r;
		yzk[tot].y=1;
		yzk[tot].z=i;
	}
	sort(yzk+1,yzk+tot+1,cmmp);
	//priority_queue<int>q;
	for(int i=1;i<=xsh;i++){
		q.push(i);
	}
	for(int i=1;i<=tot;i++){
		if(yzk[i].y==0){
			int op=q.top();
			sum2[op]++;
			vis[yzk[i].z]=op;
			q.pop();
		}
		else{
			int xpx=vis[yzk[i].z];
			q.push(xpx);
		}
	}
	for(int i=1;i<=k;i++){
		sum[i]+=sum[i-1];
		sum2[i]+=sum2[i-1];
	}
	//printf("%d\n",sum[3]);
	for(int i=0;i<=k;i++){
		ans=max(ans,sum[i]+sum2[k-i]);
	}
	printf("%d",ans);
	return 0;
}
