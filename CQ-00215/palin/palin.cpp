#include <cstdio>
namespace Subtask_1{
	const int maxn = 45;
	bool vis[maxn];
	int T,n,a[maxn],leg[maxn];
	int Flag,nd,fir[maxn];
	char tmp[maxn],ans[maxn];
	void DFS(int dep,int cnt){
		if(Flag)return ;
		if(dep == n+1){
			int flag = 1;
			for(int i=1,l=nd+1,r=nd+n;i<=n;++i){
				if(a[l] == fir[n-i+1])tmp[n+i] = 0,++l;
				else if(a[r] == fir[n-i+1])tmp[n+i] = 1,--r;
				else{flag = 0;break;}
			}
			if(flag){Flag = 1;for(int i=1;i<=2*n;++i)ans[i] = tmp[i];}
			return ;
		}
		if(cnt != nd)tmp[dep] = 0,fir[dep] = a[cnt+1],DFS(dep+1,cnt+1);
		if((nd-cnt) != (n-dep+1))tmp[dep] = 1,fir[dep] = a[2*n-(dep-cnt)+1],DFS(dep+1,cnt);
	}
	void Solve(){
		scanf("%d",&T);
		while(T--){
			scanf("%d",&n),Flag = 0;
			for(int i=1;i<=2*n;++i)scanf("%d",&a[i]);
			for(int i=0;i<=n;++i){
				for(int j=1;j<=n;++j)vis[j] = 0;
				for(int j=i+1;j<=i+n;++j)vis[a[j]] = 1;
				leg[i] = 1;
				for(int j=1;j<=n;++j)leg[i] &= vis[j];
			}
			for(int i=n;i>=0;--i)
				if(leg[i])nd = i,DFS(1,0);
			if(!Flag)printf("-1");
			else for(int i=1;i<=2*n;++i)putchar(ans[i]?'R':'L');
			puts("");
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	Subtask_1::Solve();
	return 0;
}
