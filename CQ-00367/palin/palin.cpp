#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
int T,n,a[N<<1],flag=0,an[N<<1];
string minn,as;
inline void dfs(int pos){
	if(pos>2*n){
		int i=1,j=2*n;
		string ss,ans;
		for(int k=1;k<=2*n;k++){
			if(an[k]==1) ans+='L';
			else ans+='R';
		}
		for(int k=0;k<2*n;k++){
			if(ans[k]=='L') ss+=(a[i]+'0'),i++;
			else ss+=(a[j]+'0'),j--;
		}
		for(int k=0;k<=n;k++){
			if(ss[k]!=ss[2*n-1-k]) return;
		}
		if(ss<minn) minn=ss,as=ans,flag=1;
		return;
	}
	an[pos]=1;dfs(pos+1);
	an[pos]=2,dfs(pos+1);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);minn.clear();
		for(int i=1;i<=n*2;i++) scanf("%d",&a[i]),minn+='S';flag=0;
		dfs(1);
		if(!flag) printf("-1\n");
		else cout<<as<<endl;
	}
	return 0;
}
