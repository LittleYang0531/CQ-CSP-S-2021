#include<bits/stdc++.h>
using namespace std;
int n,guonei,guowai;
int add_num=0;
int ans=0;
struct node{
	int btim,etim;
};
node a[100005];
node b[100005];
int dp_a[100005];
int dp_b[100005];
int vis[100005];
bool cmp(node x,node y){
	return x.btim<y.btim;
}
void add_guonei(){
	int sy=0;
	for(register int i=1;i<=guonei;i++){
		if(!vis[i]&&a[i].btim>sy){
			sy=a[i].etim;
			vis[i]=1;
			add_num++;
		}
	}
}
void add_guowai(){
	int sy=0;
	for(register int i=1;i<=guowai;i++){
		if(!vis[i]&&b[i].btim>sy){
			sy=b[i].etim;
			vis[i]=1;
			add_num++;
		}
	}
}
int main(){
	//usage();
	ifstream rosein("airport1.in");
	ofstream roseout("airport.out");
	//#define rosein cin
	//#define roseout cout
	rosein>>n>>guonei>>guowai;
	for(register int i=1;i<=guonei;i++){
		rosein>>a[i].btim>>a[i].etim;
	}
	for(register int i=1;i<=guowai;i++){
		rosein>>b[i].btim>>b[i].etim;
	}
	if(n>=(guonei+guowai)){
		roseout<<guonei+guowai;
		return 0;
	}
	sort(a+1,a+guonei+1,cmp);
	sort(b+1,b+guowai+1,cmp);
	for(register int i=1;i<=n;i++){
		add_num=0;
		add_guonei();
		dp_a[i]=dp_a[i-1]+add_num;
	}
	memset(vis,0,sizeof vis);
	for(register int i=1;i<=n;i++){
		add_num=0;
		add_guowai();
		dp_b[i]=dp_b[i-1]+add_num;
		ans=max(ans,dp_b[i]+dp_a[n-i]);
	}
	roseout<<max(ans,dp_a[n]);
	return 0;
}
