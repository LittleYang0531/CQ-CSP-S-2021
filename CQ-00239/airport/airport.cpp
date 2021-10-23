#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,a,b,tota,totb,res;
bool cant[100005];
struct node {
	int p,ty,id;
} t[200005],r[200005];
bool cmp(node a,node b) {
	return a.p<b.p;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1; i<=m1; i++) {
		scanf("%d%d",&a,&b);
		t[++tota].p=a;
		t[tota].id=i;
		t[++tota].p=b,t[tota].ty=1;
		t[tota].id=i;
	}
	sort(t+1,t+tota+1,cmp);
	for(int i=1; i<=m2; i++) {
		scanf("%d%d",&a,&b);
		r[++totb].p=a;
		r[totb].id=i;
		r[++totb].p=b,r[totb].ty=1;
		r[totb].id=i;
	}
	sort(r+1,r+totb+1,cmp);
	for(int i=0; i<=n; i++) {
		int num=i,ans=0;
		memset(cant,0,sizeof cant);
		if(num>=m1) {
			ans+=m1;
			continue;
		}
		for(int j=1; j<=tota; j++) {
			if(t[j].ty==0) {
				if(num>0) num--,ans++;
				else cant[t[j].id]=1;
			} else if(!cant[t[j].id]) num++;
		}
		num=n-i;
		if(num>=m2) {
			ans+=m2;
			continue;
		}
		memset(cant,0,sizeof cant);
		for(int j=1; j<=totb; j++) {
			if(r[j].ty==0) {
				if(num>0) num--,ans++;
				else cant[r[j].id]=1;
			} else if(!cant[r[j].id]) num++;
		}
		res=max(ans,res);
	}
	printf("%d",res);
	return 0;//orzzzzzzzzzzzzzzz
}
