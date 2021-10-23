#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long n,m1,m2,time_a[100005],time_b[100005],ans,cross_a[100005],cross_b[100005];
struct node{
	int reach,leave;
}a[100005],b[100005];
bool cmp(node x,node y){
	return x.reach<y.reach;
}
inline void sreach_a(int id,int op){
	for(int i=id+1; i<=m1; i++){
		if(a[id].leave<a[i].reach && !cross_a[i]){
			time_a[op]++,cross_a[i]=1,sreach_a(i,op);
			break;
		}
	}
}
inline void sreach_b(int id,int op){
	for(int i=id+1; i<=m2; i++){
		if(b[id].leave<b[i].reach && !cross_b[i]){
			time_b[op]++,cross_b[i]=1,sreach_b(i,op);
			break;
		}
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for(register int i=1; i<=m1; i++) scanf("%d%d",&a[i].reach,&a[i].leave);
	for(register int i=1; i<=m2; i++) scanf("%d%d",&b[i].reach,&b[i].leave);
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
 	for(int i=1; i<=m1; i++){
 		if(cross_a[i]) continue;
 		time_a[i]=1,sreach_a(i,i);
	}
	for(int i=1; i<=m2; i++){
		if(cross_b[i]) continue;
		time_b[i]=1,sreach_b(i,i);
	}
	for(register int i=2; i<=m1; i++) time_a[i]+=time_a[i-1];
	for(register int i=2; i<=m2; i++) time_b[i]+=time_b[i-1];
	for(register int i=0; i<=n; i++){
		ans=max(ans,time_a[i]+time_b[n-i]);
	}
	cout<<ans;
	return 0;
}
