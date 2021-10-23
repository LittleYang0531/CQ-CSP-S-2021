#include<bits/stdc++.h>
#define low_bit(x) x&-x
using namespace std;
const int N=1e5+2;
struct Plane{
	int a,b;
}gn[N],gw[N];
int n,m1,m2;
map<int,int> mp;
inline int cmp(Plane x,Plane y){
	return x.a<y.a;
}
bool vis[N];
int tree[N*2+2];
inline void add(int x,int v){
	for(int i=x;i<=2*(m1+m2);i+=low_bit(i)) tree[i]+=v;  
}
inline int ask(int x){
	int res=0;
	for(int i=x;i;i-=low_bit(i)) res+=tree[i];
	return res;
}
inline int work(Plane g[],int num,int n){
	memset(vis,false,sizeof vis);
	memset(tree,0,sizeof tree);
	int gs=0,res=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(g[j].b<g[i].a&&vis[j]){
				gs--;
				add(mp[g[j].b]+1,1),add(mp[g[j].a],-1);
				vis[j]=false;
			}
		}
		if(gs<num){
			gs++;res++;
			add(mp[g[i].a],1),add(mp[g[i].b]+1,-1);
			vis[i]=true;
		}
	}
	return res;
}
int sx[N<<1],sx2[N<<1];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d %d",&gn[i].a,&gn[i].b),sx[i*2-1]=gn[i].a,sx[i*2]=gn[i].b;
	for(int i=1;i<=m2;i++) scanf("%d %d",&gw[i].a,&gw[i].b),sx2[i*2-1]=gw[i].a,sx2[i*2]=gw[i].b;
	sort(gn+1,gn+m1+1,cmp);sort(gw+1,gw+m2+1,cmp);
	sort(sx+1,sx+m1*2+1),sort(sx2+1,sx2+m2*2+1);
	for(int i=1;i<=m1*2;i++){
		mp[sx[i]]=i;
	}
	for(int i=1;i<=m2*2;i++){
		mp[sx2[i]]=i;
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		int pos=work(gn,i,m1),pos2=work(gw,n-i,m2);
		ans=max(ans,pos+pos2);
	}
	printf("%d",ans);
	return 0;
}
