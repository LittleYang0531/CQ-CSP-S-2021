#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
int T;
int a[2*N];
int ans[2*N];//1=l,2=r;
vector<int> lsh;
bool vis[N];//ÊÇ·ñ´æÔÚ¹ı
int l=1,r;
int b[N];

bool check(){
	int ll=l,rr=r;
	for(int i=n+1;i<=2*n;i++){
		int j=2*n-i+1;
		if(a[l]!=b[j]&&a[r]!=b[j]){
			l=ll,r=rr;
			return false;
		}
		if(a[l]==b[j]){
			ans[i]=1;
			l++;
		}else{
			ans[i]=2;
			r--;
		}
	}
	return true;
}

bool dfs(int point){
	if(point>n){
		if(check()){
//			puts("233");
			return true;	
		}
//		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
//		puts("");
		return false;
	}
	if(!vis[a[l]]){
		vis[a[l]]=true;
		ans[point]=1;
		b[point]=a[l];
		l++;
		if(dfs(point+1)) return true;
		l--;
		vis[a[l]]=false;
	}
	if(/*a[l]!=a[r]&&*/!vis[a[r]]){
		vis[a[r]]=true;
		ans[point]=2;
		b[point]=a[r];
		r--;
		if(dfs(point+1)) return true;
		r++;
		vis[a[r]]=false;
	}
	return false;
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		l=1,r=2*n;
		memset(vis,false,sizeof vis);
		memset(ans,0,sizeof ans);
		memset(b,0,sizeof b);
		lsh.clear();
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
			lsh.push_back(a[i]);
		}
		sort(lsh.begin(),lsh.end());
		lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
		for(int i=1;i<=2*n;i++){
			a[i]=lower_bound(lsh.begin(),lsh.end(),a[i])-lsh.begin()+1;
		}
		if(!dfs(1)) printf("-1\n");
		else{
			for(int i=1;i<=2*n;i++) printf("%c",ans[i]==1?'L':'R'); 
			puts("");
		}
	}
	return 0;
}

