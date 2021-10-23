#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int N=1e5+7;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;(ch<'0'||ch>'9');ch=getchar()) if(ch=='-') f=-1;
	for(;(ch>='0'&&ch<='9');ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
int n,ma,mb;
struct tr{
	int l,r;
}g[N],ji[N];
int dp1[N],dp2[N];
int fl1[N],fl2[N];
int li[N],cnt;
inline int f(tr ll,tr rr){
	return ll.l<rr.l;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),ma=read(),mb=read();
	for(int i=1;i<=ma;i++) g[i].l=read(),g[i].r=read();
	sort(g+1,g+1+ma,f);
	for(int i=1;i<=mb;i++) ji[i].l=read(),ji[i].r=read();
	sort(ji+1,ji+1+mb,f);
	for(int i=1;i<=n;i++){
		int kai=0;
		for(int t=1;t<=ma;t++){
			if(!fl1[t]){
				kai=t;
				break;
			}
		}
		cnt=0;
		if(kai!=0){
			li[++cnt]=kai;
			for(int t=kai+1;t<=ma;t++){
				if(fl1[t]) continue;
				if(g[li[cnt]].r<g[t].l) li[++cnt]=t;
			}
			for(int t=1;t<=cnt;t++) fl1[li[t]]=1;
		}
		dp1[i]=dp1[i-1]+cnt;
	}
	for(int i=1;i<=n;i++){
		int kai=0;
		for(int t=1;t<=mb;t++){
			if(!fl2[t]){
				kai=t;
				break;
			}
		}
		cnt=0;
		if(kai!=0){
			li[++cnt]=kai;
			for(int t=kai+1;t<=mb;t++){
				if(fl2[t]) continue;
				if(ji[li[cnt]].r<ji[t].l) li[++cnt]=t;
			}
			for(int t=1;t<=cnt;t++) fl2[li[t]]=1;
		}
		dp2[i]=dp2[i-1]+cnt;
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,dp1[i]+dp2[n-i]);
	}
	cout<<ans;
}
