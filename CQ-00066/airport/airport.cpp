#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
const int Maxx=1000005,Maxn=2005,INF=0x3f3f3f3f,Mod=1e9+7;
inline int read()
{
	int res=0;char bj=0,ch=getchar();
	while(ch<'0'||ch>'9')bj|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9')res=(res<<1)+(res<<3)+(ch^48),ch=getchar();
	return bj?-res:res;
}
void print(int x){
	if(x>9)print(x/10);
	putchar(x%10^48);
}
inline void printnum(int x,char ch)
{
	if(x<0)putchar('-'),x=-x;
	print(x),putchar(ch);
}
struct Plane {
	int a,b;
	inline bool operator < (const Plane &tp) const {
		return a<tp.a;
	}
}A[Maxx],B[Maxx];
int n,cnt,tmp[Maxx<<2],id[Maxx<<2],fa[Maxx],fb[Maxx],tg[Maxx];
inline void Solve(Plane A[],int m,int f[]){
	priority_queue<int,vector<int>,greater<int> >pq;
	for(int i=1,r=max(n,m);i<=r;++i)pq.push(i);
	memset(id,0,sizeof(int)*(cnt+1));
	for(int i=1;i<=m;++i)id[A[i].a]=i,id[A[i].b]=-i;
	for(int i=1;i<=cnt;++i){
		if(id[i]>0)tg[id[i]]=pq.top(),pq.pop();//,cout<<tg[id[i]]<<"??";
		else if(id[i])pq.push(tg[-id[i]]);
	}
	for(int i=1;i<=m;++i)++f[tg[i]];
	for(int i=1;i<=n;++i)f[i]+=f[i-1];
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();int ma=read(),mb=read();
	for(int i=1;i<=ma;++i)tmp[++cnt]=A[i].a=read(),tmp[++cnt]=A[i].b=read();
	for(int i=1;i<=mb;++i)tmp[++cnt]=B[i].a=read(),tmp[++cnt]=B[i].b=read();
	sort(tmp+1,tmp+cnt+1),cnt=unique(tmp+1,tmp+cnt+1)-tmp-1;
	for(int i=1;i<=ma;++i){
		A[i].a=lower_bound(tmp+1,tmp+cnt+1,A[i].a)-tmp;
		A[i].b=lower_bound(tmp+1,tmp+cnt+1,A[i].b)-tmp;
	}
	for(int i=1;i<=mb;++i){
		B[i].a=lower_bound(tmp+1,tmp+cnt+1,B[i].a)-tmp;
		B[i].b=lower_bound(tmp+1,tmp+cnt+1,B[i].b)-tmp;
	}
	Solve(A,ma,fa),Solve(B,mb,fb);
	int Ans=0;
	for(int i=0;i<=n;++i)Ans=max(Ans,fa[i]+fb[n-i]);
//	for(int i=0;i<=n;++i)cout<<fa[i]<<" ";puts("fa");
//	for(int i=0;i<=n;++i)cout<<fb[i]<<" ";puts("fb");
	cout<<Ans<<"\n";
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
