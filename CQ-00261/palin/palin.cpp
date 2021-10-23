#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,a[500005],b[500005],ans=-1;
char steps[500005];
bool ifans;
bool check(){
	for(int i=1;i<=n;i++){
		if(b[i]!=b[n*2-i+1])return false;
	}
	return true;
}
void dfs(int cnt,int al,int ar,bool flag,int scnt){
	if(al>n*2||ar<1)return;
	if(ifans)return;
	if(flag==1){
		b[cnt]=a[al];
	}
	else{
		b[cnt]=a[ar];
	}
	if(cnt==n*2&&check()){
		cout<<"L"; 
		for(int i=1;i<=scnt;i++){
			cout<<steps[i];
		}
		cout<<endl;
		ifans=1;
		return;
	}
	steps[++scnt]='L';
	dfs(cnt+1,al+1,ar,1,scnt);
	steps[scnt]='R';
	dfs(cnt+1,al,ar-1,0,scnt);
}
signed main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","r",stdin);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		ifans=0;
		cin>>n;
		for(int i=1;i<=n*2;i++){
			cin>>a[i];
			cout<<"L";
		}
		memset(b,0,sizeof(b));
		cout<<endl;
	}
	return 0;
}
