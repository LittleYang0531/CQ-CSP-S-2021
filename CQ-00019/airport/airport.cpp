#include<bits/stdc++.h>
#define _I inline
#define _R register
#define mod 998244353
#define INF 0x3f3f3f3f
#define eps 1e-4
#define memset(x,y) memset(x,y,sizeof(x))
#define memcpy(x,y) memcpy(x,y,sizeof(x))
#define ll long long
#define ull unsigned long long
using namespace std;
//char buf[1<<19],*p1=buf,*p2=buf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<19,stdin)),p1==p2)?EOF:*p1++;
int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	if(f)x=-x;return x;
}
const int N=100005;
int n,as,m1,m2,num,b[N*2],c[N*2],val[N*2],ans1[N],ans2[N],ans,ls[N*16],rs[N*16],mn[N*16],tag[N*16];
struct note{int l,r;}a[N];
bool cmp(note aa,note bb){return aa.l<bb.l;}
void pushup(int x){mn[x]=min(mn[x<<1],mn[x<<1|1]);}
void down(int x,int tg){tag[x]+=tg;if(mn[x]!=INF)mn[x]+=tg;}
void pushdown(int x){
	if(!tag[x])return;
	if(ls[x<<1])down(x<<1,tag[x]);if(ls[x<<1|1])down(x<<1|1,tag[x]);
	tag[x]=0;
}
void build(int x,int l,int r){
	ls[x]=l;rs[x]=r;mn[x]=INF;if(l==r){if(c[l])mn[x]=0;else mn[x]=INF;return;}
	int mid=(l+r)>>1;build(x<<1,l,mid);build(x<<1|1,mid+1,r);pushup(x);
}
void revise(int x,int l,int r,int val0){
	if(l>rs[x]||r<ls[x])return;
	if(l<=ls[x]&&rs[x]<=r){down(x,val0);return;}
	pushdown(x);
	revise(x<<1,l,r,val0);revise(x<<1|1,l,r,val0);
	pushup(x);
}
void revise(int x,int k){
	if(k>rs[x]||k<ls[x])return;
	if(k<=ls[x]&&rs[x]<=k){mn[x]=INF;return;}
	pushdown(x);
	revise(x<<1,k);revise(x<<1|1,k);
	pushup(x);
}
int find(int x,int l,int r,int val){
	if(l>rs[x]||r<ls[x]||mn[x]>=val)return 0;
	if(ls[x]==rs[x])return ls[x];
	int mid=(ls[x]+rs[x])>>1;
	int tmp=find(x<<1,l,r,val);if(tmp)return tmp;else return find(x<<1|1,l,r,val);
}
signed main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(_R int i=1;i<=m1;++i)a[i].l=read(),a[i].r=read(),b[++num]=a[i].l,b[++num]=a[i].r;sort(b+1,b+num+1);
	for(_R int i=1;i<=m1;++i)a[i].l=lower_bound(b+1,b+num+1,a[i].l)-b,a[i].r=lower_bound(b+1,b+num+1,a[i].r)-b;
	sort(a+1,a+m1+1,cmp);for(_R int i=1;i<=m1;++i)c[a[i].l]=i;build(1,1,num);
	for(_R int k=1,as=0;k<=n;++k){
		for(_R int i=1;i<=num;++i){
			i=find(1,i,num,k);if(!i)break;++as;
			revise(1,a[c[i]].l,a[c[i]].r,1);
			revise(1,i);
			int tmp=c[i];c[i]=0;i=a[tmp].r;
		}ans1[k]=as;
	}
	m1=m2;num=0;memset(val,0);memset(c,0);memset(tag,0);
	for(_R int i=1;i<=m1;++i)a[i].l=read(),a[i].r=read(),b[++num]=a[i].l,b[++num]=a[i].r;sort(b+1,b+num+1);
	for(_R int i=1;i<=m1;++i)a[i].l=lower_bound(b+1,b+num+1,a[i].l)-b,a[i].r=lower_bound(b+1,b+num+1,a[i].r)-b;
	sort(a+1,a+m1+1,cmp);for(_R int i=1;i<=m1;++i)c[a[i].l]=i;build(1,1,num);
	for(_R int k=1,as=0;k<=n;++k){
		for(_R int i=1;i<=num;++i){
			i=find(1,i,num,k);if(!i)break;++as;
			revise(1,a[c[i]].l,a[c[i]].r,1);
			revise(1,i);
			int tmp=c[i];c[i]=0;i=a[tmp].r;
		}ans2[k]=as;
	}
	for(_R int i=0;i<=n;++i)ans=max(ans,ans1[i]+ans2[n-i]);cout<<ans;
	return 0;
}
