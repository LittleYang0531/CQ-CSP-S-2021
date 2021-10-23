#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int inf=0x7fffffff;
inline int read(){
	int x=0;char p=getchar();
	while(p<'0'||p>'9')p=getchar();
	while(p>='0'&&p<='9')x=(x<<3)+(x<<1)+(p^48),p=getchar();
	return x;
}
inline void pnum(int x){
	if (x>9) pnum(x/10);
	putchar(x%10+'0');
}
struct edge{
	int l,r;
}w1[100001],w2[100001];
int n,a1,a2,ans,an;
inline int find1(int num){
	priority_queue<int> Q;
	an=0;
	if (!num) return 0;
	for (int i=1;i<=a1;i++){
		while(Q.size()&&-Q.top()<w1[i].l) Q.pop();
		if (Q.size()<num)Q.push(-w1[i].r),an++;
	}
	return an;
}
inline int find2(int num){
	priority_queue<int> Q;
	an=0;
	if (!num) return 0;
	for (int i=1;i<=a2;i++){
		while(Q.size()&&-Q.top()<w2[i].l) Q.pop();
		if (Q.size()<num)Q.push(-w2[i].r),an++;
	}
	return an;
}
inline bool cmp(edge &a,edge &b){
	return a.l<b.l;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),a1=read(),a2=read();
	for (int i=1;i<=a1;i++) w1[i].l=read(),w1[i].r=read();
	for (int i=1;i<=a2;i++) w2[i].l=read(),w2[i].r=read();
	sort(w1+1,w1+a1+1,cmp),sort(w2+1,w2+a2+1,cmp);
	for (int i=0;i<=n;i++)ans=max(ans,find1(i)+find2(n-i));
	pnum(ans);
	return 0;
}
