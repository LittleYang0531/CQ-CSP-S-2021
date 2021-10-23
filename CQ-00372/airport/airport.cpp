#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct hh {int l,r;} a[N],b[N];
int cmp(hh x,hh y) {return x.l<y.l;}
int n,m1,m2,ansa[N],ansb[N],id[N],cnta,cntb;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].l,&b[i].r);
	}
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	for(int i=1;i<=m1;i++){
		int flag=1;
		for(int j=1;j<=cnta;j++){
			if(a[i].l>=a[id[j]].r){
				id[j]=i;
				ansa[j]++;
				flag=0;
				break;
			}
		}
		if(flag){
			ansa[++cnta]=1;
			id[cnta]=i;
		}
	}
	for(int i=1;i<=m2;i++){
		int flag=1;
		for(int j=1;j<=cntb;j++){
			if(b[i].l>=b[id[j]].r){
				id[j]=i;
				ansb[j]++;
				flag=0;
				break;
			}
		}
		if(flag){
			ansb[++cntb]=1;
			id[cntb]=i;
		}
	}
	for(int i=1;i<=cnta;i++) ansa[i]=ansa[i-1]+ansa[i];
	for(int i=1;i<=cntb;i++) ansb[i]=ansb[i-1]+ansb[i];
	int ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,ansa[i]+ansb[n-i]);
	}
	printf("%d",ans);
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
