#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,ans=0;
struct air{
	int l,r;
}a[100005],b[100005];
int c[100005],d[100005],tc=0,td=0;
int e[100005],f[100005];
bool flag;
bool cmp(air a,air b){
	return a.l<b.l;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for (int i=1;i<=m1;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	for (int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].l,&b[i].r);
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for (int i=1;i<=m1;i++){
		flag=true;
		for (int l=1;l<=tc;l++){
			if (c[l]<a[i].l){
				c[l]=a[i].r;
				e[l]++;
				flag=false;
				break;
			}
		}
		if (flag){
			c[++tc]=a[i].r;
			e[tc]++;
		}
	}
	for (int i=1;i<=m2;i++){
		flag=true;
		for (int l=1;l<=td;l++){
			if (d[l]<b[i].l){
				d[l]=b[i].r;
				f[l]++;
				flag=false;
				break;
			}
		}
		if (flag){
			d[++td]=b[i].r;
			f[td]++;
		}
	}
	for (int i=1;i<=n;i++){
		e[i]+=e[i-1];
		f[i]+=f[i-1];
	}
	for (int i=0;i<=n;i++){
		ans=ans>(e[i]+f[n-i])?ans:e[i]+f[n-i];
	}
	printf("%d",ans);
	return 0;
}
