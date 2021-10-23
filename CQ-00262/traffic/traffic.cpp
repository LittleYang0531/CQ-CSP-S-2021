#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,t,k,limit,id[503][503],flag;
ll ans;
bool color[5003];
struct star{
	int u,v;
	ll val;
}edge[5003];
void dfs(int uid){
	if(uid>id[n][m]){
		ll cnt=0;
		for(int i=1;i<=flag;i++)if(color[edge[i].u]!=color[edge[i].v])cnt+=edge[i].val;
		ans=min(ans,cnt);return;
	}
	color[uid]=1;dfs(uid+1);
	color[uid]=0;dfs(uid+1);
}
int main(){
	freopen("traffic.in","r",stdin);freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);ll tmp;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)id[i][j]=(i-1)*m+j;
	for(int i=1;i<n;i++)
	for(int j=1;j<=m;j++){
		scanf("%lld",&tmp);edge[++flag]=(star){id[i][j],id[i+1][j],tmp};
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<m;j++){
		scanf("%lld",&tmp);edge[++flag]=(star){id[i][j],id[i][j+1],tmp};
	}int save=flag;
	while(t--){
		int tmpo;flag=save;ans=LLONG_MAX/2;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%lld%d",&tmp,&tmpo);
			if(tmpo<=m)tmpo=id[1][tmpo];
			else if(tmpo<=n+m)tmpo=id[tmpo-m][m];
			else if(tmpo<=2*m+n)tmpo=id[n][m-(tmpo-m-n)+1];
			else tmpo=id[n-(tmpo-2*m-n)+1][1];
			edge[++flag]=(star){tmpo,id[n][m]+i,tmp};
			scanf("%d",&tmpo);color[id[n][m]+i]=tmpo;
		}
		dfs(1);printf("%lld\n",ans);
	}
	return 0;
}
