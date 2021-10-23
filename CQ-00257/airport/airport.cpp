#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
typedef long long ll;
int n,m1,m2,m;
int pl[N],pr[N];
int kl[N],kr[N];
struct OGC {
	int num,id;
} DIY[N];
bool cmp(OGC a,OGC b) {
	return a.num<b.num;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1; i<=m1; i++) {
		scanf("%d%d",&pl[i],&pr[i]);
		DIY[++m].num=pl[i];
		DIY[++m].num=pr[i];
	}
	for(int i=1; i<=m2; i++) {
		scanf("%d%d",&kl[i],&kr[i]);
		DIY[++m].num=kl[i];
		DIY[++m].num=kr[i];
	}
	sort(DIY+1,DIY+m+1,cmp);
	for(int i=1; i<=m; i++) {
		DIY[i].id=i;
		for(int j=1; j<=m1; j++) {
			if(DIY[i].num==pl[j]) {
				pl[j]=DIY[i].id;
				break;
			}
			if(DIY[i].num==pr[j]) {
				pr[j]=DIY[i].id;
				break;
			}
		}
		for(int j=1; j<=m2; j++) {
			if(DIY[i].num==kl[j]) {
				kl[j]=DIY[i].id;
				break;
			}
			if(DIY[i].num==kr[j]) {
				kr[j]=DIY[i].id;
				break;
			}
		}
	}
	int cnt1=0,cnt2=0;
	for(int i=1;i<=m;i++){
		int op=0;
		for(int j=0;j<=n;j++){
			DIY[op++].id-=kl[op];
			if(DIY[kl[j]].num==kr[j])break;
		}
		for(int j=0;j<=n;j++){
			DIY[op--].num-=pl[op];
			if(DIY[pl[j]].id==pr[j])break;
		}
		for(int j=0;j<=n;j++){
			DIY[op++].num-=kr[op];
			if(DIY[kr[j]].num==kl[j])break;
		}
		for(int j=0;j<=n;j++){
			DIY[op--].id-=pr[op];
			if(DIY[pr[j]].id==pl[j])break;
		}
	}
	printf("%d",m1+m2);
	return 0;
}
