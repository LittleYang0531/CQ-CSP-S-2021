#include<bits/stdc++.h>
#define ll long long
//#define in cin
//#define out cout
using namespace std;
ifstream in("palin.in");
ofstream out("palin.out");
//bool happy1041;
//ll time1=clock();
//
const ll N=5e5;
ll n,zl,zr;
ll a[N+10],dy[N+10][5],ord[N+10];
bool ans[2*N+10];
bool vis[N+10];
//
bool dfs(ll dep,ll l,ll r){
	if(dep>n) return true;
	ll t;
	bool lb=0;
	if(l<zl){
		t=dy[a[l]][2];
//		out<<l<<" "<<t<<endl;
		if(t==zl-1||t==zr+1){
			if(t==zl-1) --zl;
			else ++zr;
			lb=dfs(dep+1,l+1,r);
			if(lb){
				ans[dep]=0;
				ord[dep]=a[l];
			}
		} 
	}
	if(!lb&&r>zr){
		t=dy[a[r]][1];
//		out<<r<<" "<<t<<endl;
		if(t==zl-1||t==zr+1){
			if(t==zl-1) --zl;
			else ++zr;
			lb=dfs(dep+1,l,r-1);
			if(lb){
				ans[dep]=1;
				ord[dep]=a[r];
			}
		} 
	}
	return lb;
}
//
//bool Happy1041;
//void usage(){
//	ll time2=clock();
//	cout<<(&Happy1041-&happy1041)/1024/1024<<" Mb, "<<time2-time1<<" ms" ;
//}
int main(){
	ll t;
	in>>t;
	for(int hp=1; hp<=t; ++hp){
		in>>n;
		for(int i=1; i<=2*n; ++i){
			in>>a[i];
			vis[a[i]]^=1;
			if(vis[a[i]]==1) dy[a[i]][1]=i;
			else dy[a[i]][2]=i;
		}
//		for(int i=1; i<=n; ++i){
//			out<<dy[i][1]<<" "<<dy[i][2]<<endl;
//		}
		bool abb;
		zl=dy[a[1]][2],zr=dy[a[1]][2];
		ans[1]=0;
		ord[1]=a[1];
		abb=dfs(2,2,2*n);
		if(abb){
			for(int i=1; i<=n; ++i){
				if(!ans[i]) out<<"L";
				else out<<"R";
			}
			for(int i=n; i>=1; --i){
				if(ord[i]==a[zl]){
					out<<"L";
					++zl;
				} 
				else{
					out<<"R";
					--zr;
				}
			}
			out<<endl;
		}
		else{
			zl=dy[a[2*n]][1],zr=dy[a[2*n]][1];
			ans[1]=1;
			ord[1]=a[2*n];
			abb=dfs(2,1,2*n-1);
			if(abb){
			for(int i=1; i<=n; ++i){
				if(!ans[i]) out<<"L";
				else out<<"R";
			}
			for(int i=n; i>=1; --i){
			if(ord[i]==a[zl]){
				out<<"L";
				++zl;
			} 
			else{
				out<<"R";
				--zr;
			}
			}
			out<<endl;
			}
			else out<<-1<<endl;
		}
	}
	return 0;
//	usage();
}

