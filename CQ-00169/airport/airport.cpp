#include <bits/stdc++.h>
using namespace std;
const int mxn=1e5+5;
int n,m1,m2,mx,ans,sum,cnt;
int cti[mxn],cto[mxn],whi[mxn],who[mxn],lst[mxn];
struct plane {
	int a,b;
	bool operator <(const plane &A) const{
		return A.a > a;//从小到大 
	}
}in[mxn],out[mxn];
int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++) 
		in[i].a=read(),in[i].b=read();
	for(int i=1;i<=m2;i++) 
		out[i].a=read(),out[i].b=read();
	sort(in+1,in+1+m1);
	sort(out+1,out+1+m2); 
	for(int i=1;i<=m1;i++) {
		int now=cnt+1;
		for(int j=1;j<=cnt;j++) 
		if(in[i].a>lst[j]) {
			now=j;lst[j]=in[i].b;break;
		}
		if(now==cnt+1) cnt++,lst[cnt]=in[i].b;
		whi[i]=now;
//		printf("<%d> %d\n",i,whi[i]);
		cti[now]++;
	}
//	printf("\n");
	memset(lst,0,sizeof(lst));
	cnt=0;
	for(int i=1;i<=m2;i++) {
		int now=cnt+1;
		for(int j=1;j<=cnt;j++) 
		if(out[i].a>lst[j]) {
			now=j,lst[j]=out[i].b;break;
		}
		if(now==cnt+1) cnt++,lst[cnt]=out[i].b;
		who[i]=now;
//		printf("<%d> %d\n",i,who[i]);
		cto[now]++;
	}
	for(int i=1;i<=n;i++) ans+=cti[i];
	sum=ans;
//	for(int i=1;i<=n;i++) printf("<%d> %d\n",i,cti[i]);
//	printf("\n");
//	for(int i=1;i<=n;i++) printf("<%d> %d\n",i,cto[i]);
//	printf("%d ",sum);
	for(int i=1;i<=n;i++) {
		sum=sum+cto[i]-cti[n-i+1]; 
//		printf("%d ",sum);
		ans=max(ans,sum);
	}
	printf("%d ",ans);
}
//the first
//14:50~16:00
//40pts
//O(n^2)
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
