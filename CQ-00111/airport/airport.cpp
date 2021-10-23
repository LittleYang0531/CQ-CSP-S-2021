#include<algorithm>
#include<cstdio>
const int M=1e5+5;
int n,m1,m2,x[M],y[M],t[M],pre[M];
struct sec{
	int L,R;
	inline bool operator<(const sec&it)const{
		return L<it.L;
	}
}a[M],b[M];
int Find(const int&u){
	return pre[u]==u?u:pre[u]=Find(pre[u]);
}
inline int max(const int&a,const int&b){
	return a>b?a:b;
}
void DFS(const int&i,const int&n){
	if(i==n+1)return;
	int L(i+1),R(n),mid,ans(n+1);
	while(L<=R){
		mid=L+R>>1;
		if(a[i].R<a[Find(mid)].L)ans=mid,R=mid-1;
		else L=mid+1;
	}
	pre[t[i]=ans]=ans-1;DFS(t[i],n);
}
inline void init(sec*a,int*x,const int&n){
	int i,L,R,mid,ans;
	for(i=1;i<=n;++i)pre[i]=i;
	for(i=1;i<=n;++i)if(pre[i]==i)DFS(i,n);
	for(i=n;i>=1;--i)t[i]=t[t[i]]+1;L=0;
	for(i=1;i<=n;++i){
		if(pre[i]^i)continue;
		++L;x[L]=x[L-1]+t[i];if(L==::n)break;
	}
	while(L<::n)++L,x[L]=x[L-1];
	for(i=1;i<=n;++i)t[i]=0;
}
signed main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int i,ans(0);scanf("%d%d%d",&n,&m1,&m2);
	for(i=1;i<=m1;++i)scanf("%d%d",&a[i].L,&a[i].R);std::sort(a+1,a+m1+1);init(a,x,m1);
	for(i=1;i<=m2;++i)scanf("%d%d",&b[i].L,&b[i].R);std::sort(b+1,b+m2+1);init(b,y,m2);
	for(i=0;i<=n;++i)ans=max(ans,x[i]+y[n-i]);printf("%d",ans);
}
