#include<stdio.h>
#include<queue>
using namespace std;
#define R register int
#define I inline
#define N 250050
#define M 2004000
int id[501][501],a[501][501],b[501][501],pre[N],Last[N],pos[2005],Next[M],End[M],Cap[M],ct;
I void Link(int x,int y,int c){
	ct++;
	End[ct]=y;
	Cap[ct]=c;
	Next[ct]=Last[x];
	Last[x]=ct;
}
I bool BFS(int S,int T){
	for(R i=1;i<=T;i++){
		pre[i]=0;
	}
	queue<int>Q;
	Q.push(S);
	while(Q.empty()==false){
		int x=Q.front();
		Q.pop();
		for(R i=Last[x];i!=0;i=Next[i]){
			if(Cap[i]!=0&&pre[End[i]]==0){
				pre[End[i]]=i;
				Q.push(End[i]);
			}
		}
	}
	return pre[T]!=0;
}
I int MaxFlow(int S,int T){
	int res=0;
	while(BFS(S,T)==true){
		int cur=1000000;
		for(R i=T;i!=S;i=End[pre[i]^1]){
			if(cur>Cap[pre[i]]){
				cur=Cap[pre[i]];
			}
		}
		res+=cur;
		for(R i=T;i!=S;i=End[pre[i]^1]){
			Cap[pre[i]]-=cur;
			Cap[pre[i]^1]+=cur;
		}
	}
	return res;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,q,x,w,c,S,T,tot=0;
	scanf("%d%d%d",&n,&m,&q);
	for(R i=1;i<=n;i++){
		for(R j=1;j<=m;j++){
			tot++;
			id[i][j]=tot;
		}
	}
	S=tot+1;
	T=S+1;
	for(R i=1;i!=n;i++){
		for(R j=1;j<=m;j++){
			scanf("%d",a[i]+j);
		}
	}
	for(R i=1;i<=n;i++){
		for(R j=1;j!=m;j++){
			scanf("%d",b[i]+j);
		}
	}
	for(R i=1;i<=m;i++){
		pos[i]=id[1][i];
	}
	for(R i=1;i<=n;i++){
		pos[i+m]=id[i][m];
	}
	for(R i=1;i<=m;i++){
		pos[i+n+m]=id[n][m-i+1];
	}
	for(R i=1;i<=n;i++){
		pos[i+n+(m<<1)]=id[n-i+1][1];
	}
	for(R i=1;i<=n+m<<1;i++){
		Link(S,pos[i],0);
		Link(pos[i],S,0);
		Link(pos[i],T,0);
		Link(T,pos[i],0);
	}
	for(R i=q;i!=0;i--){
		ct=1;
		for(R j=1;j<=T;j++){
			Last[j]=0;
		}
		for(R j=1;j!=n;j++){
			for(R k=1;k<=m;k++){
				Link(id[j][k],id[j+1][k],a[j][k]);
				Link(id[j+1][k],id[j][k],a[j][k]);
			}
		}
		for(R j=1;j<=n;j++){
			for(R k=1;k!=m;k++){
				Link(id[j][k],id[j][k+1],b[j][k]);
				Link(id[j][k+1],id[j][k],b[j][k]);
			}
		}
		scanf("%d",&q);
		for(R j=0;j!=q;j++){
			scanf("%d%d%d",&w,&x,&c);
			if(c==0){
				Link(S,pos[x],w);
				Link(pos[x],S,0);
			}else{
				Link(pos[x],T,w);
				Link(T,pos[x],0);
			}
		}
		printf("%d\n",MaxFlow(S,T));
	}
	return 0;
}
