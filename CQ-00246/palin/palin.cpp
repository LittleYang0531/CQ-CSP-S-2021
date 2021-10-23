#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e6+5;
int a[N],n,T,cl[N],ans[N];
bool dfs(int l,int r){
	if(l==r+1){
		for(int i=1;i<=n;i++) if(cl[i]!=cl[2*n-i+1]) return 0;
		return 1;
	}
	cl[0]++;
	cl[cl[0]]=a[l];
	ans[cl[0]]=0;
	if(dfs(l+1,r)) return 1;
	cl[cl[0]]=a[r];
	ans[cl[0]]=1;
	if(dfs(l,r-1)) return 1;
	cl[0]--;
	return 0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		cl[0]=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		if(!dfs(1,2*n)) printf("-1\n");
		else{
			for(int i=1;i<=2*n;i++) printf("%c",ans[i]==0?'L':'R');
			printf("\n");
		}
	}
	return 0;
}
