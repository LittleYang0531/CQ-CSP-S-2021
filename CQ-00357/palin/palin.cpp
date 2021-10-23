#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int Case,n,a[N],b[N];
inline void Solve1(void){
	int i,j,l,r,flag;
	deque<int>q;
	for(i=0;i<1<<(n*2);++i){
		l=1,r=n*2;q.clear();*b=0;
		for(j=n*2;j;--j)if((i>>(j-1))&1)b[++*b]=(a[r--]);
		else b[++*b]=(a[l++]);
		for(flag=0,j=1;j<=n*2;++j)if(b[j]^b[n*2-j+1]){flag=1;break;}
		if(!flag){
			for(j=n*2;j;--j)putchar(!((i>>(j-1))&1)?'L':'R');putchar('\n');
			return ;
		}
	}puts("-1");
}
//inline char Check(int l,int r){
//	int i;
//	for(i=l;i<=r;++i){
//		for(j=i;j<=)
//	}
//}
//inline void Solve2(void){//钦定某个东西 
//	int i,j;
//	for(i=1;i<=2*n;++i)v[a[i]].push_back(i);
//	for(i=1;i<=n;++i)p[i]={v[i][0],v[i][1]};
//	for(i=1;i<=2*n;++i){
//		
//	}
//} 
inline void Solve(void){
	int i;scanf("%d",&n);
	for(i=1;i<=2*n;++i)scanf("%d",a+i);
	if(n<=10)return Solve1();
}
int main(void){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&Case);
	while(Case--)Solve();
	return 0;
}



