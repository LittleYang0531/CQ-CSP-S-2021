#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int readint(){
	int x=0,f=1;char s=getchar();
	#define sc (s=getchar())
	while(s<'0'||s>'9'){
		if(s=='-')
			f=-1;
		sc;
	}
	while(s>='0'&&s<='9'){
		x=(x<<3)+(x<<1)+(s^48);
		sc;
	}
	#undef sc
	return x*f;
}
struct zz{
	int a,b;
}s[maxn],t[maxn];
int ans1[maxn],ans2[maxn];
bool cmp(const zz &x,const zz &y){
	return x.a<y.a;
}
int main (){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n=readint(),m1=readint(),m2=readint();
	for(int i=1;i<=m1;i++)
		s[i].a=readint(),s[i].b=readint();
	sort(s+1,s+m1+1,cmp);
	for(int i=1;i<=m2;i++)
		t[i].a=readint(),t[i].b=readint();
	sort(t+1,t+m2+1,cmp);
	if(n>=m1+m2){
		printf("%d\n",n);
		return 0;
	}
	for(int k=1;k<=n;k++){
		priority_queue<int,vector<int>,greater<int> > q;
		if(k>=m1)
			ans1[k]=m1;
		for(int j=1;j<=k;j++)
			q.push(0);
		int cnt=0;
		for(int i=1;i<=m1;i++){
			if(s[i].a>q.top()){
				q.pop();
				q.push(s[i].b);
				cnt++;
			}
		}
		ans1[k]=cnt;
	}
	for(int k=1;k<=n;k++){
		priority_queue<int,vector<int>,greater<int> > q;
		if(k>=m2)
			ans2[k]=m2;
		for(int j=1;j<=k;j++)
			q.push(0);
		int cnt=0;
		for(int i=1;i<=m2;i++){
			if(t[i].a>q.top()){
				q.pop();
				q.push(t[i].b);
				cnt++;
			}
		}
		ans2[k]=cnt;
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		maxx=max(ans1[i]+ans2[n-i],maxx);
	}
	cout<<maxx<<endl;
	return 0;
}
