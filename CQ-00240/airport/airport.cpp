#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5;

void file(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
}
int read(){
	int s=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}

//struct BIT{
//	int c[N<<1];
//	void clear(){memset(c,0,sizeof(c));}
//	int lowbit(int x){return -x&x;}
//	void add(int x,int v){for(;x<N<<1;x+=lowbit(x))c[x]+=v;}
//	int ask(int x){int r=0;for(;x;x-=lowbit(x))r+=c[x];return r;}
//}bit;
struct Plane{
	int l,r;
}a[N],b[N];
int tmp[N<<1],d[N<<1],tonga[N],tongb[N];
int fga[N],fgb[N],reva[N<<1],revb[N<<1];
int n,m1,m2,cnt;
bool vis[N<<1];

bool cmp(Plane a,Plane b){
	return a.l<b.l;
}
void solve1(){
	int ans=0;
	for(int i=0;i<=n;++i){//国内 i 个 ,国外 n-i 个 
		int res=0,now=0,last=0;
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=m1<<1;++j){
			if(fga[j]==1){
				if(now+1<=i)now++,res++,vis[a[reva[j]].r]=1;
			}else if(vis[j])now--;
		}
		memset(vis,0,sizeof(vis));
		int tmp=res; res=now=last=0;
		for(int j=1;j<=m2<<1;++j){
			if(fgb[j]==1){
				if(now+1<=n-i)now++,res++,vis[b[revb[j]].r]=1;
			}else if(vis[j])now--;
		}
		ans=max(ans,tmp+res);
	}
	printf("%lld\n",ans);
}
void solve2(){
	int ans=0;
	for(int i=1;i<=m1;++i)d[a[i].l]++,d[a[i].r+1]--;
	for(int i=1;i<=m1*2+1;++i)
		d[i]+=d[i-1],tonga[d[i]]+=fga[i]==1;
	memset(d,0,sizeof(d));
	for(int i=1;i<=m2;++i)d[b[i].l]++,d[b[i].r+1]--;
	for(int i=1;i<=m2*2+1;++i)
		d[i]+=d[i-1],tongb[d[i]]+=fgb[i]==1;
	for(int i=1;i<=n;++i)
		tonga[i]+=tonga[i-1],tongb[i]+=tongb[i-1];
	for(int i=0;i<=n;++i)
		ans=max(ans,tonga[i]+tongb[n-i]);
	printf("%lld\n",ans);
}

signed main(){
	file();
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;++i)
		a[i].l=read(),a[i].r=read(),
		tmp[++cnt]=a[i].l,tmp[++cnt]=a[i].r;
	sort(tmp+1,tmp+1+cnt);
	int len=unique(tmp+1,tmp+1+cnt)-tmp-1;
	for(int i=1;i<=m1;++i)
		a[i].l=lower_bound(tmp+1,tmp+1+cnt,a[i].l)-tmp,
		a[i].r=lower_bound(tmp+1,tmp+1+cnt,a[i].r)-tmp;
	cnt=0;
	for(int i=1;i<=m2;++i)
		b[i].l=read(),b[i].r=read(),
		tmp[++cnt]=b[i].l,tmp[++cnt]=b[i].r;
	sort(tmp+1,tmp+1+cnt);
	len=unique(tmp+1,tmp+1+cnt)-tmp-1;
	for(int i=1;i<=m2;++i)
		b[i].l=lower_bound(tmp+1,tmp+1+cnt,b[i].l)-tmp,
		b[i].r=lower_bound(tmp+1,tmp+1+cnt,b[i].r)-tmp;
	sort(a+1,a+m1+1,cmp),sort(b+1,b+m2+1,cmp);
	for(int i=1;i<=m1;++i)fga[a[i].l]=1,fga[a[i].r]=-1,reva[a[i].l]=i;
	for(int i=1;i<=m2;++i)fgb[b[i].l]=1,fgb[b[i].r]=-1,revb[b[i].l]=i;
	if(n<=5000&&m1+m2<=5000)solve1();
	else solve2();
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
