#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 200012
int n,al,m1,m2,c1,c2,c[N],d[N],ans=0,w[N],f[N];
struct Po{int x,v;}a[N],b[N];
inline bool cmp(Po x,Po y){return x.x<y.x;}
inline void cha(int x,int v){for(;x<=al;x+=x&(-x))w[x]+=v;}
inline int As(int x){int res=0;for(;x;x&=(x-1))res+=w[x];return res;}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);al=max(m1,m2);int i,x,y,l,r,mid,res;
	for(i=1;i<=m1;i++){scanf("%d%d",&x,&y);a[++c1]=(Po){x,i};a[++c1]=(Po){y,-i};}
	for(i=1;i<=m2;i++){scanf("%d%d",&x,&y);b[++c2]=(Po){x,i};b[++c2]=(Po){y,-i};}
	sort(a+1,a+c1+1,cmp);sort(b+1,b+c2+1,cmp);m1=m2=0;
	for(i=1;i<=c1;i++)
	if(a[i].v>0)
	{
		l=1;r=al;res=0;while(l<=r){mid=(l+r)>>1;if(mid>As(mid)){res=mid;r=mid-1;}else l=mid+1;}
		cha(f[a[i].v]=c[++m1]=res,1);
	}
	else cha(f[-a[i].v],-1);
	for(i=1;i<=c2;i++)
	if(b[i].v>0)
	{
		l=1;r=al;res=0;while(l<=r){mid=(l+r)>>1;if(mid>As(mid)){res=mid;r=mid-1;}else l=mid+1;}
		cha(f[b[i].v]=d[++m2]=res,1);
	}
	else cha(f[-b[i].v],-1);
	sort(c+1,c+m1+1);sort(d+1,d+m2+1);
	for(i=0;i<=n;i++)ans=max(ans,(int)((upper_bound(c+1,c+m1+1,i)-c-1)+(upper_bound(d+1,d+m2+1,n-i)-d-1)));
	printf("%d",ans);return 0;
}
