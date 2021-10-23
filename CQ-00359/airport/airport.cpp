#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,m1,m2;
int ans,tot,cnt,maxx,now;
int end[100005];
int vst[100005];
struct o1 {
	int s,e;
} a[100005];
struct o2 {
	int s,e;
} b[100005];
bool cmp1(o1 x,o1 y) {
	return x.s<y.s;
}
bool cmp2(o2 x,o2 y) {
	return x.s<y.s;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1; i<=m1; i++) {
		scanf("%d%d",&a[i].s,&a[i].e);
	}
	sort(a+1,a+m1+1,cmp1);
	for(int i=1; i<=m2; i++) {
		scanf("%d%d",&b[i].s,&b[i].e);
	}
	sort(b+1,b+m2+1,cmp2);
	for(int i=0; i<=min(5000,n); i++) {
		cnt=i;
		ans=0; 
		now=tot=0;
		for(int j=1; j<=m1; j++) {
			now=1;
			while(a[j].s>end[now]&&now<=tot&&cnt<=i) {
				if(vst[now]==1) {
					now++;
					continue;
				}
				vst[now]=1;
				if(cnt<i) cnt++;
				if(now<tot) now++;
				if(cnt==i||now==tot) break;
			}
			if(cnt>0) {
				cnt--;
				end[++tot]=a[j].e;
				sort(end+1,end+tot+1);
			}
		}
//		cout<<tot<<" ";
		for(int j=1; j<=tot; j++) end[j]=0,vst[j]=0;
		ans+=tot;
		cnt=n-i;
		now=tot=0;
		for(int j=1; j<=m2; j++) {
			now=1;
			while(b[j].s>end[now]&&now<=tot&&cnt<=n-i) {
				if(vst[now]==1) {
					now++;
					continue;
				}
				vst[now]=1;
				if(cnt<n-i) cnt++;
				if(now<tot) now++;
				if(cnt==n-i&&now==tot) break;
			}
			if(cnt>0) {
				cnt--;
				end[++tot]=b[j].e;
				sort(end+1,end+tot+1);
			}
		}
//		cout<<tot<<endl;
		for(int j=1; j<=tot; j++) end[j]=0,vst[j]=0;
		maxx=max(maxx,ans+tot);
	}
	printf("%d",maxx);
	return 0;
}
