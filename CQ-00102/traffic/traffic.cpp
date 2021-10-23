#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=55;
struct node{
	int val,id,c;
}a[N<<1];
int n,tg=0,T,ans,vx[N][N],vy[N][N],mpx[N*N],mpy[N*N],Q,m,cl[N][N],tot;
void work(){
	int i,j,res=0;
	for(i=1;i<=Q;i++){
		if(a[i].id>=1&&a[i].id<=m){
			if(cl[1][a[i].id]!=a[i].c)res+=a[i].val;
		}
		else if(a[i].id>m&&a[i].id<=n+m){
			if(cl[a[i].id-m][m]!=a[i].c)res+=a[i].val;
		}
		else if(a[i].id>n+m&&a[i].id<=2*m+n){
			if(cl[n][m-(a[i].id-n-m)+1]!=a[i].c)res+=a[i].val;
		}
		else{
			if(cl[n-(a[i].id-2*m-n)+1][1]!=a[i].c)res+=a[i].val;
		}
	}
	for(i=1;i<n;i++){
		for(j=1;j<=m;j++){
			if(cl[i][j]!=cl[i+1][j])res+=vx[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<m;j++){
			if(cl[i][j]!=cl[i][j+1])res+=vy[i][j];
		}
	}
	ans=min(ans,res);
}
void Force(int dep){
	if(dep==n*m+1){work();return;}
	cl[mpx[dep]][mpy[dep]]=0;Force(dep+1);
	cl[mpx[dep]][mpy[dep]]=1;Force(dep+1);
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int i,j;
	scanf("%d%d%d",&n,&m,&T);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			tot++;mpx[tot]=i,mpy[tot]=j;
		}
	}
	for(i=1;i<=n-1;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&vx[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<m;j++){
			scanf("%d",&vy[i][j]);
		}
	}
	while(T--){
		scanf("%d",&Q);ans=1e9;
		for(i=1;i<=Q;i++)scanf("%d%d%d",&a[i].val,&a[i].id,&a[i].c);
		Force(1);printf("%d\n",ans);
	}
}
