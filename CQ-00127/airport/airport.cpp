#include <bits/stdc++.h>
using namespace std;
const int N=4e5+5;
struct Node{
	int l,r;Node(){}
	Node(int L,int R){l=L,r=R;}
}a[N],b[N];
int dif[N];
bool cmp(Node x,Node y){
	return x.l<y.l;}
int n,m1,m2,d[N];
int lowbit(int x){return x&(-x);}
void add(int x,int l){
	while(x<N)
		d[x]+=l,x+=lowbit(x);
}
int ask(int x){
	int res=0;
	while(x)
		res+=d[x],x-=lowbit(x);
	return res;
}
int solve(int x){
	int res=0,cnt=0;
	for(int i=1;i<=m1;++i)
		if(cnt-ask(a[i].l)>=x)
			++res;
		else	++cnt,add(a[i].r,1);
	memset(d,0,sizeof(d)),cnt=0;
	for(int i=1;i<=m2;++i)
		if(cnt-ask(b[i].l)>=n-x)
			++res;
		else	++cnt,add(b[i].r,1);
	memset(d,0,sizeof(d));
	return res;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	int cnt=0;
	for(int i=1;i<=m1;++i)
		scanf("%d %d",&a[i].l,&a[i].r),
		dif[++cnt]=a[i].l,dif[++cnt]=a[i].r;
	for(int i=1;i<=m2;++i)
		scanf("%d %d",&b[i].l,&b[i].r),
		dif[++cnt]=b[i].l,dif[++cnt]=b[i].r;
	sort(dif+1,dif+cnt+1);
	for(int i=1;i<=m1;++i)
		a[i].l=lower_bound(dif+1,dif+cnt+1,a[i].l)-dif,
		a[i].r=lower_bound(dif+1,dif+cnt+1,a[i].r)-dif;
	for(int i=1;i<=m2;++i)
		b[i].l=lower_bound(dif+1,dif+cnt+1,b[i].l)-dif,
		b[i].r=lower_bound(dif+1,dif+cnt+1,b[i].r)-dif;
	sort(a+1,a+m1+1,cmp),sort(b+1,b+m2+1,cmp);
	int l=0,r=n,lmid=(l+r)>>1,rmid=(lmid+r)>>1;
	while(l<r){
		if(lmid==rmid)	lmid=l,rmid=r;
		if(solve(lmid)>solve(rmid))	l=lmid+1;
		else	r=rmid-1;
		lmid=(l+r)>>1,rmid=(lmid+r)>>1;
	}
//	printf("%d",solve(2));
//	printf("%d\n",l);
	printf("%d",m1+m2-solve(l));
	return 0;
}
