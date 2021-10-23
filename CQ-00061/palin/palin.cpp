#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,a[maxn];
int opt[maxn],seq[maxn],tmp[maxn],return_flag;
bool check(){
	int al=1,ar=2*n;
	int sl=2*n,sr=2*n+1;
	for(int i=1;i<=2*n;++i){
		if(opt[i]==1){
			seq[sr++]=a[al++];
		}
		else{
			seq[sr++]=a[ar--];
		}
	}
	int tmptot=0;
	for(int i=sl+1;i<=sr-1;++i){
		tmp[++tmptot]=seq[i];
	}
	for(int i=1;i<=n;++i){
		if(tmp[i]!=tmp[tmptot-i+1]) return 0;
	}
	return 1;
}
void dfs(int now){
	if(return_flag) return;
	if(now>2*n){
		if(check()){
			for(int i=1;i<=2*n;++i){
				if(opt[i]==1) cout<<"L";
				else cout<<"R";
			}
			cout<<"\n";
			return_flag=1;
		}
		return;
	}
	opt[now]=1;//l
	dfs(now+1);
	opt[now]=2;
	dfs(now+1);
	opt[now]=0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=2*n;++i) cin>>a[i];
		return_flag=0;
		dfs(1);
		if(!return_flag) cout<<"-1\n";
	}
	return 0;
}
//LRRLLRRRRL
