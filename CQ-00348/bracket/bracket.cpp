#include<bits/stdc++.h>
#define ll long long
using namespace std;
ifstream in("bracket.in");
ofstream out("bracket.out");
//bool happy1041;
//ll time1=clock();
//
const ll N=5e2;
string s;
ll n,ok,abaaba=0,ans=0;
int vis[N+10],mmap[N+10],lkhs[N+10],q[N+10],qto=0;
//
//
void dfs(int dep,int lnum,int rnum,int lth){
	if(lth>ok||lnum<rnum||(lnum-rnum>n-dep+1)) return;
	if(dep>n){
		if(lnum==rnum&&mmap[n]==1){
			qto=0;
			bool llb=0;
			for(int i=1; i<=n; ++i){
				lkhs[i]=lkhs[i-1];
				if(mmap[i]==0){
					q[++qto]=i;
					++lkhs[i];
				} 
				if(mmap[i]==1){
					if(mmap[i-1]==2&&mmap[q[qto]+1]==2&&lkhs[i]-lkhs[q[qto]]>0){
						llb=1;
						break;
					}
					else{
						--qto;
					}
				}
			}
			if(!llb){
				++ans;
			} 
		}
		return;
	}
	if(!vis[dep]){
		mmap[dep]=0;
		dfs(dep+1,lnum+1,rnum,0);
		mmap[dep]=1;
		dfs(dep+1,lnum,rnum+1,0);
		mmap[dep]=2;
		dfs(dep+1,lnum,rnum,lth+1);
	}
	else if(vis[dep]==1){
		mmap[dep]=0;
		dfs(dep+1,lnum+1,rnum,0);
	}
	else if(vis[dep]==2){
		mmap[dep]=1;
		dfs(dep+1,lnum,rnum+1,0);
	}
	else if(vis[dep]==3){
		mmap[dep]=2;
		dfs(dep+1,lnum,rnum,lth+1);
	}
}
//
//bool Happy1041;
//void usage(){
//	ll time2=clock();
//	cout<<(&Happy1041-&happy1041)/1024/1024<<" Mb, "<<time2-time1<<" ms" ;
//}
int main(){
	in>>n>>ok;
	in>>s;
	bool lb=0;
	for(int i=0; i<n; ++i){
		if(s[i]=='(') vis[i+1]=1;
		else if(s[i]==')') vis[i+1]=2;
		else if(s[i]=='*') vis[i+1]=3;
	}
//	if(s[0]!='('&&s[0]!='?'){
//		lb=1;
//	}
//	if(s[n-1]!=')'&&s[n-1]!='?'){
//		lb=1;
//	}
//	if(lb){
//		out<<"a";
//		out<<0;
//	} 
//	else{
		mmap[1]=0;
		q[++qto]=1;
		dfs(2,1,0,0);
		out<<ans;
//	}
	return 0;
//	usage();
}

