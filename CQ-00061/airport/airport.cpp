#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m1,m2,ans;
struct line{
	int l,r;
	bool operator < (const line &x)const{
		if(l!=x.l) return l<x.l;
		return r<x.r;
	}
} a[maxn],b[maxn];
bool vis[maxn];
priority_queue<int>Q;//保存使用结束时间点 
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;++i) cin>>a[i].l>>a[i].r;
	for(int i=1;i<=m2;++i) cin>>b[i].l>>b[i].r;
	sort(a+1,a+m1+1);
	sort(b+1,b+m2+1);
	if(n<=5000 && m1+m2<=5000){
		for(int num1=0;num1<=n;++num1){
			while(!Q.empty()) Q.pop();
			int num2=n-num1;
			int now=num1,res=0;
			for(int i=1;i<=m1;++i){
				while(!Q.empty() && -Q.top()<a[i].l){
					Q.pop();
					++now;
				}
				if(now){
					Q.push(-a[i].r);
					--now;
					++res;
				}
			}
			now=num2;
			while(!Q.empty()) Q.pop();
			for(int i=1;i<=m2;++i){
				while(!Q.empty() && -Q.top()<b[i].l){
					Q.pop();
					++now;
				}
				if(now){
					Q.push(-b[i].r);
					--now;
					++res;
				}
			}
			if(res>ans) ans=res;
		}
		cout<<ans;
	}
	else{
		srand(time(NULL));
		int cnt=0;
		while(cnt<n&&cnt<=2000){
			++cnt;
			int num1=rand()%n+1;
			while(!Q.empty()) Q.pop();
			int num2=n-num1;
			int now=num1,res=0;
			for(int i=1;i<=m1;++i){
				while(!Q.empty() && -Q.top()<a[i].l){
					Q.pop();
					++now;
				}
				if(now){
					Q.push(-a[i].r);
					--now;
					++res;
				}
			}
			now=num2;
			while(!Q.empty()) Q.pop();
			for(int i=1;i<=m2;++i){
				while(!Q.empty() && -Q.top()<b[i].l){
					Q.pop();
					++now;
				}
				if(now){
					Q.push(-b[i].r);
					--now;
					++res;
				}
			}
			if(res>ans) ans=res;
		}
		cout<<ans;
	}
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
