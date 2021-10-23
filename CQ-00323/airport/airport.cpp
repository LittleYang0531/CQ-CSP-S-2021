#include<bits/stdc++.h>
#define loop(i,from,to) for(int i=(from);i<=(to);++i)
#define reset(a,x) memset(a,x,sizeof a)
#define pair(x,y) make_pair(x,y)
using namespace std;
const int maxn=1e5;
int n,x,y,ans,ending,tot[2],m[2],presum[2][maxn+1];
set<pair<int,int>> airplane;
void read(int &x){
	x=0;
	char t=getchar();
	while(!isdigit(t))t=getchar();
	while(isdigit(t))x=x*10+t-'0',t=getchar();
	return;
}
int main(){
	freopen("airport.in","r",stdin),freopen("airport.out","w",stdout);
	read(n),read(m[0]),read(m[1]);
	loop(opt,0,1){
		loop(i,1,m[opt])read(x),read(y),airplane.insert(pair(x,y));
		while(!airplane.empty()){
			presum[opt][++tot[opt]]=ending=0;
			auto iter=airplane.upper_bound(pair(ending,0));
			while(iter!=airplane.end())
				++presum[opt][tot[opt]],ending=iter->second,airplane.erase(iter),iter=airplane.upper_bound(pair(ending,0));
		}
		loop(i,1,tot[opt])presum[opt][i]+=presum[opt][i-1];
	}
	loop(i,1,n)ans=max(ans,presum[0][i]+presum[1][n-i]);
	printf("%d",ans);
	return 0;
}
