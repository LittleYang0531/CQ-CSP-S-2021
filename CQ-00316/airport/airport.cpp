#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m1,m2,ans,sum1[100005],sum2[100005];
bool v[100005];
struct plane{
	int l,r;
	bool operator<(const plane &T)const{return l<T.l;}
}a[100005],b[100005];
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=1;i<=m2;i++)scanf("%d%d",&b[i].l,&b[i].r);
	sort(a+1,a+m1+1);
	sort(b+1,b+m2+1);
	for(int i=1;i<=n;i++) {
		sum1[i]=sum1[i-1];
		for(int j=1;j<=m1;j++) {
			if(v[j])continue;
			v[j]=1;
			sum1[i]++;
			int l=j,r=m1,mid,x=0;
			while(l<=r) {
				mid=l+r>>1;
				if(a[mid].l>a[j].r)x=mid,r=mid-1;
				else l=mid+1;
			}
			if(!x)break;
			j=x-1;
		}
		if(sum1[i]==m1) {
			for(int j=i;j<=n;j++)sum1[j]=sum1[i];
			break;
		}
	}
	memset(v,0,sizeof(v));
	for(int i=1;i<=n;i++) {
		sum2[i]=sum2[i-1];
		for(int j=1;j<=m2;j++) {
			if(v[j])continue;
			v[j]=1;
			sum2[i]++;
			int l=j,r=m2,mid,x=0;
			while(l<=r) {
				mid=l+r>>1;
				if(b[mid].l>b[j].r)x=mid,r=mid-1;
				else l=mid+1;
			}
			if(!x)break;
			j=x-1;
		}
		if(sum2[i]==m2) {
			for(int j=i;j<=n;j++)sum2[j]=sum2[i];
			break;
		}
	}
	for(int i=0;i<=n;i++)ans=max(ans,sum1[i]+sum2[n-i]);
	printf("%d",ans);
	return 0;
}
