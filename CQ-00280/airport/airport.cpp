#include<bits/stdc++.h>
using namespace std;
inline int Rd() {
	int s=0; char fl=0,c=getchar();
	while(c<'0'||c>'9') fl|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return fl?-s:s;
}
//512MB

const int N=1e5+5,inf=1e9;

struct node{
	int l,r;
	inline char operator <(const node &u) const{
		return l<u.l;
	}
} a[N];

int n,m[2],sum[2][N];
int num[2],bl[N];

int tmp[N<<1];

int mn[N<<3],pos[N<<3];

void Build(int x,int l,int r) {
	mn[x]=1e9,pos[x]=0; if(l==r) return;
	int mid=l+r>>1; Build(x<<1,l,mid),Build(x<<1|1,mid+1,r);
}

inline void Pushup(int x) {
	if(mn[x<<1]<mn[x<<1|1]) pos[x]=pos[x<<1],mn[x]=mn[x<<1];
	else pos[x]=pos[x<<1|1],mn[x]=mn[x<<1|1];
}

void Insert(int x,int l,int r,int d,int v,int po) {
	if(l==r) return mn[x]=v,pos[x]=po,void(); int mid=l+r>>1;
	d<=mid?Insert(x<<1,l,mid,d,v,po):Insert(x<<1|1,mid+1,r,d,v,po);
	Pushup(x);
}

int minn,id;

void Query(int x,int l,int r,int ql,int qr) {
	if(ql<=l&&r<=qr) {
		if(mn[x]<minn) minn=mn[x],id=pos[x];
		return;
	}
	int mid=l+r>>1;
	if(ql<=mid) Query(x<<1,l,mid,ql,qr);
	if(qr>mid) Query(x<<1|1,mid+1,r,ql,qr);
}

int main() {
//	system("fc airport.out airport1.ans");
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=Rd(),m[0]=Rd(),m[1]=Rd();
	for(int t=0; t<2; ++t) {
		int sign=0;
		for(int i=1; i<=m[t]; ++i) {
			a[i]=(node){Rd(),Rd()};
			tmp[++sign]=a[i].l;
			tmp[++sign]=a[i].r;
		}
		sort(a+1,a+m[t]+1); sort(tmp+1,tmp+sign+1);
		sign=unique(tmp+1,tmp+sign+1)-tmp-1;
		Build(1,1,sign);
		
		int now=0;
		for(int i=1; i<=m[t]; ++i) {
			a[i].l=lower_bound(tmp+1,tmp+sign+1,a[i].l)-tmp;
			a[i].r=lower_bound(tmp+1,tmp+sign+1,a[i].r)-tmp;
			
			minn=1e9,id=0;
			Query(1,1,sign,1,a[i].l);
			
			if(minn<1e9) {
				++sum[t][bl[i]=bl[id]];
				Insert(1,1,sign,a[id].r,1e9,0);
			}
			else bl[i]=++now,sum[t][now]=1;
			
			Insert(1,1,sign,a[i].r,bl[i],i);
		}
		for(int i=1; i<=n; ++i) sum[t][i]+=sum[t][i-1];//,cout<<sum[t][i]<<' ';
	}
	
	int ans=0;
	for(int i=0; i<=n; ++i) {
		int tmp=sum[0][i]+sum[1][n-i];
		if(tmp>ans) ans=tmp;
	}
	printf("%d\n",ans);
	return 0;
}

