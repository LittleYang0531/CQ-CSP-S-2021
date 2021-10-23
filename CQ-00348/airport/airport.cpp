#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)>>1)
using namespace std;
ifstream in("airport.in");
ofstream out("airport.out");
//bool happy1041; 
//ll time1=clock();
//
const ll N=1e5;
struct node{
	ll x,y;
};
node a[N+10],b[N+10];
ll anum[N+10],bnum[N+10],T[4*N+10];
//
bool cmp(node a,node b){
	if(a.x<b.x||(a.x==b.x&&a.y<b.y)) return true;
	return false;
}
void que(ll l,ll r,ll ord,ll st,ll en,ll lx){
	if(l==r){
		if(T[ord]<st){
			if(lx==1)
			++anum[l];
			else 
			++bnum[l];
			T[ord]=en;
		} 
		return;
	}
	if(T[ord*2]<st) que(l,mid,ord*2,st,en,lx);
	else que(mid+1,r,ord*2+1,st,en,lx);
	T[ord]=min(T[ord*2],T[ord*2+1]);
}
//
//bool Happy1041;
//void usage(){
//	ll time2=clock();
//	cout<<(&Happy1041-&happy1041)/1024/1024<<" Mb, "<<time2-time1<<" ms" ;
//}
int main(){
	ll n,m1,m2;
	in>>n>>m1>>m2;
	for(int i=1; i<=m1; ++i){
		in>>a[i].x>>a[i].y;
	}
	for(int i=1; i<=m2; ++i){
		in>>b[i].x>>b[i].y;
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int i=1; i<=m1; ++i){
		que(1,n,1,a[i].x,a[i].y,1);
	}
	memset(T,0,sizeof(T));
	for(int i=1; i<=m2; ++i){
		que(1,n,1,b[i].x,b[i].y,2);
	}
	for(int i=1; i<=n; ++i){
		anum[i]+=anum[i-1];
//		out<<anum[i]<<" ";
	}
//	out<<endl;
	for(int i=1; i<=n; ++i){
		bnum[i]+=bnum[i-1];
//		out<<bnum[i]<<" ";
	}
//	out<<endl;
	ll ans=0;
	for(int i=0; i<=n; ++i){
		ans=max(ans,anum[i]+bnum[n-i]);
	}
	out<<ans;
	return 0;
//	usage();
}
