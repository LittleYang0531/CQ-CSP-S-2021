#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define P pair<int,int>
#define fi first
#define se second
//#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
int n,m1,m2,h[N<<1],s[N<<1];P a[N],b[N];
void brute_force(){
	int ans=0;
	for(int i=0;i<=m1&&i<=n;i++){
		int j=max(n-i,0);
		int tmp=0;
		for(int p=1,q=1;p<=m1;p++){
			while(a[p].fi>=q) s[q]+=s[q-1],q++;
			if(s[a[p].fi]<i) s[a[p].fi]++,tmp++,s[a[p].se]--;
		}for(int p=0;p<=m1*2+1;p++) s[p]=0;
		for(int p=1,q=1;p<=m2;p++){
			while(b[p].fi>=q) s[q]+=s[q-1],q++;
			if(s[b[p].fi]<j) s[b[p].fi]++,tmp++,s[b[p].se]--;
		}ans=max(ans,tmp);
		for(int p=0;p<=m2*2+1;p++) s[p]=0;
	}printf("%d",ans);
}inline int getcnt(int x){
	int y=max(n-x,0);
	int res=0;
	for(int p=1,q=1;p<=m1;p++){
		while(a[p].fi>=q) s[q]+=s[q-1],q++;
		if(s[a[p].fi]<x) s[a[p].fi]++,res++,s[a[p].se]--;
	}for(int p=0;p<=m1*2+1;p++) s[p]=0;
	for(int p=1,q=1;p<=m2;p++){
		while(b[p].fi>=q) s[q]+=s[q-1],q++;
		if(s[b[p].fi]<y) s[b[p].fi]++,res++,s[b[p].se]--;
	}for(int p=0;p<=m2*2+1;p++) s[p]=0;
	return res;
}int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1+m2;i++){
		int x,y;scanf("%d%d",&x,&y);
		i<=m1?a[i]=P(x,y):b[i-m1]=P(x,y);
	}sort(a+1,a+1+m1);sort(b+1,b+1+m2);
	for(int i=1;i<=m1;i++) h[i]=a[i].fi,h[m1+i]=a[i].se;
	sort(h+1,h+1+m1*2);
	for(int i=1;i<=m1;i++){
		a[i].fi=lower_bound(h+1,h+1+m1*2,a[i].fi)-h;
		a[i].se=lower_bound(h+1,h+1+m1*2,a[i].se)-h;
	}for(int i=1;i<=m2;i++) h[i]=b[i].fi,h[m2+i]=b[i].se;
	sort(h+1,h+1+m2*2);
	for(int i=1;i<=m2;i++){
		b[i].fi=lower_bound(h+1,h+1+m2*2,b[i].fi)-h;
		b[i].se=lower_bound(h+1,h+1+m2*2,b[i].se)-h;
	}if(m1+m2<=6000&&n<=6000){brute_force();return 0;}
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid1=(2*l+r)/3,mid2=(2*r+l)/3;
		int tmp1=getcnt(mid1),tmp2=getcnt(mid2);
		if(tmp1>tmp2) r=mid2-1,ans=max(ans,tmp1);
		else l=mid1+1,ans=max(ans,tmp2);
	}printf("%d",ans);
	return 0;
}
