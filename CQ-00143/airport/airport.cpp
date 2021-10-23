#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &n){
	T w=1;n=0;
	char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<1)+(n<<3)+(ch&15);ch=getchar();}
	n*=w;
}
const int N=100005;
int n,m1,m2,ans=0,cs[N];
struct PL{
	int l,r;
	friend bool operator<(PL a,PL b){
		return a.r>b.r;
	}
}p1[N],p2[N];
bool cmp(PL a,PL b){return a.l<b.l;}
priority_queue<PL>q;
inline int solve(int n1){
	while(!q.empty())q.pop();
	int cnt=0,ans=0;
	for(int i=1;i<=m1;++i){
		while(!q.empty()&&q.top().r<p1[i].l){q.pop();cnt--;}
		if(cnt<n1){q.push(p1[i]);cnt++;ans++;}
	}
	while(!q.empty())q.pop();
	cnt=0;
	for(int i=1;i<=m2;++i){
		while(!q.empty()&&q.top().r<p2[i].l){q.pop();cnt--;}
		if(cnt<n-n1){q.push(p2[i]);cnt++;ans++;}
	}
	return ans;
}
int ma(int a,int b){return a>b?a:b;}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n);read(m1);read(m2);
	for(int i=1;i<=m1;++i){
		read(p1[i].l);read(p1[i].r);
	}
	for(int i=1;i<=m2;++i){
		read(p2[i].l);read(p2[i].r);
	}
	sort(p1+1,p1+1+m1,cmp);sort(p2+1,p2+1+m2,cmp);
	if(n<=5000&&m1+m2<=5000){
		for(int i=0;i<=n;++i)
			ans=ma(ans,solve(i));
	}
	else{
		for(int i=0;i<=n;i++)cs[i]=i;
		random_shuffle(cs,cs+1+n);
		ans=ma(ans,solve(n/2));
		int KK=50000000/n/17-3;
		for(int i=0;i<=KK;i++)
			ans=ma(ans,solve(cs[i]));
	}
	printf("%d\n",ans);
	return 0;
}
