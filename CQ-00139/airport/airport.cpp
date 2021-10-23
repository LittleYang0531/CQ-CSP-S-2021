#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=4e5+5;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m1,m2,cnt,lsh[N],id[N],val[N],ans1[N],ans2[N],ans;
//id : 时刻 i 到达站台的飞机编号 
//ans : 当分配了 i 个站台时的答案 
//val : 时刻 i 是否有飞机离开 
struct node{
	int l,r;
	bool operator <(const node &a)const {
		return l<a.l;
	}
}a[N],b[N];
int getx(int x) {
	return lower_bound(lsh+1,lsh+1+cnt,x)-lsh;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++) {
		a[i].l=read(),a[i].r=read();
		lsh[++cnt]=a[i].l;
		lsh[++cnt]=a[i].r;
	}
	for(int i=1;i<=m2;i++) {
		b[i].l=read(),b[i].r=read();
		lsh[++cnt]=b[i].l;
		lsh[++cnt]=b[i].r;
	}
	sort(lsh+1,lsh+1+cnt);
	for(int i=1;i<=m1;i++) {
		a[i].l=getx(a[i].l);
		a[i].r=getx(a[i].r);
	}
	for(int i=1;i<=m2;i++) {
		b[i].l=getx(b[i].l);
		b[i].r=getx(b[i].r);
	}
	sort(a+1,a+1+m1);
	sort(b+1,b+1+m2);
    for(int i=1;i<=m1;i++) {
    	id[a[i].l]=a[i].r;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=cnt;j++) {
			val[j]=0;
		}
		int now=i;
		for(int j=1;j<=cnt;j++) {
			if(val[j]) now++;
			if(id[j]&&now) {
				val[id[j]]++;
				now--;
				ans1[i]++;
			}
		}
	}
	for(int i=1;i<=cnt;i++) {
		id[i]=0;
	}
	for(int i=1;i<=m2;i++) {
		id[b[i].l]=b[i].r;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=cnt;j++) {
			val[j]=0;
		}
		int now=i;
		for(int j=1;j<=cnt;j++) {
			if(val[j]) now++;
			if(id[j]&&now) {
				val[id[j]]++;
				now--;
				ans2[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++) ans1[i]=max(ans1[i-1],ans1[i]),ans2[i]=max(ans2[i-1],ans2[i]);
	for(int i=0;i<=n;i++) {
		ans=max(ans,ans1[i]+ans2[n-i]);
	}
	printf("%d",ans);
}
