#include<bits/stdc++.h>
using namespace std;
int n,m,k,numa[400005],numb[400005],suma[400005],sumb[400005],aa[400005],bb[400005],ans,ma[400005],ma1[400005];
struct st{
	int l,r;
}a[400005],b[400005];
struct st1{
	int v,l,r;
}sum[1600005],sum1[1600005];
struct st3{
	int v,id;
}op[400005];
bool cmp(st x,st y){
	return x.l<y.l;
}
bool cmp1(st3 x,st3 y){
	return x.v<y.v;
}
void build(int x,int l,int r){
	sum[x].l=l;
	sum[x].r=r;
	sum1[x].l=l;
	sum1[x].r=r;
	if(l==r){
		sum[x].v=sum1[x].v=1;
		return;
	}
	build(x*2,l,l+r>>1);
	build(x*2+1,(l+r>>1)+1,r);
	sum[x].v=sum[x*2].v+sum[x*2+1].v;
	sum1[x].v=sum1[x*2].v+sum1[x*2+1].v;
}
void update(int x,int y,int p){
	if(sum[p].l==sum[p].r){
		sum[p].v+=y;
		return;
	}
	if(x<=sum[2*p].r)update(x,y,2*p);
	else update(x,y,2*p+1);
	sum[p].v=sum[p*2].v+sum[p*2+1].v;
}
int Sum(int p,int l,int r){
	if(l==r)return l;
	if(sum[2*p].v){
		return Sum(2*p,sum[2*p].l,sum[2*p].r);
	}else{
		return Sum(2*p+1,sum[2*p+1].l,sum[2*p+1].r);
	}
}
void update1(int x,int y,int p){
	if(sum1[p].l==sum1[p].r){
		sum1[p].v+=y;
		return;
	}
	if(x<=sum1[2*p].r)update1(x,y,2*p);
	else update1(x,y,2*p+1);
	sum1[p].v=sum1[p*2].v+sum1[p*2+1].v;
}
int Sum1(int p,int l,int r){
	if(l==r)return l;
	if(sum1[2*p].v){
		return Sum1(2*p,sum1[2*p].l,sum1[2*p].r);
	}else{
		return Sum1(2*p+1,sum1[2*p+1].l,sum1[2*p+1].r);
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	build(1,1,400000);
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
		op[2*i-1].v=a[i].l;
		op[2*i-1].id=2*i-1;
		op[2*i].v=a[i].r;
		op[2*i].id=2*i;
	}
	sort(op+1,op+2*n+1,cmp1);
	for(int i=1;i<=2*n;i++){
		if(op[i].id%2){
			int kk=Sum(1,1,400000);
			ma[op[i].id+1]=kk;
			update(kk,-1,1);
			aa[kk]++;
			numa[op[i].id/2+1]=kk;
		}else{
			update(ma[op[i].id],1,1);
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&b[i].l,&b[i].r);
		op[2*i-1].v=b[i].l;
		op[2*i-1].id=2*i-1;
		op[2*i].v=b[i].r;
		op[2*i].id=2*i;
	}
	sort(op+1,op+2*m+1,cmp1);
	for(int i=1;i<=2*m;i++){
		if(op[i].id%2){
			int kk=Sum1(1,1,400000);
			ma1[op[i].id+1]=kk;
			update1(kk,-1,1);
			bb[kk]++;
			numb[op[i].id/2+1]=kk;
		}else{
			update1(ma1[op[i].id],1,1);
		}
	}
	for(int i=1;i<=k;i++)suma[i]=suma[i-1]+aa[i],sumb[i]=sumb[i-1]+bb[i];
	for(int i=0;i<=k;i++){
		ans=max(suma[i]+sumb[k-i],ans);
	}
	printf("%d",ans);
	return 0;
}
//1 5 1
//3 8 2
//6 10 2
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
*/

