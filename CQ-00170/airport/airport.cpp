#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m1,m2,sum1[maxn],sum2[maxn],pre1[maxn],pre2[maxn],ans;
struct node{
	int a,b;
	bool operator <(const node &t) const{
		return a<t.a;
	}
}f1[maxn],f2[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return res;
}
inline void work1(){
	for(int i=1;i<=m1;i++)
		for(int j=1;j<=n;j++)
			if(f1[i].a>pre1[j]){
				pre1[j]=f1[i].b;
				for(int k=j;k<=n;k++)
					sum1[k]++;
				break;
			}
}
inline void work2(){
	for(int i=1;i<=m2;i++)
		for(int j=1;j<=n;j++)
			if(f2[i].a>pre2[j]){
				pre2[j]=f2[i].b;
				for(int k=j;k<=n;k++)
					sum2[k]++;
				break;
			}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)
		f1[i].a=read(),f1[i].b=read();
	for(int i=1;i<=m2;i++)	
		f2[i].a=read(),f2[i].b=read();
	stable_sort(f1+1,f1+m1+1);
	stable_sort(f2+1,f2+m2+1);
	work1();
	work2();
	for(int i=0;i<=n;i++)
		ans=max(ans,sum1[i]+sum2[n-i]);
	printf("%d\n",ans);
	return 0;
}
