#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){ll a=0;int b=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9'){a=(a<<1)+(a<<3)+(c^48);c=getchar();}return a*b;}
const int MAX_N = 1e6 + 9;
int n;
int a[MAX_N];
int tmp[MAX_N];
char ans[MAX_N];
inline bool IsHuiWen(){
	for(int i=1,j=2*n;i<=n;++i,--j) if(tmp[i]!=tmp[j]) return 0;
	return 1;
}
bool f;
inline void dfs(int now,int l,int r){
	if(f) return;
	if(l == r){
		tmp[now] = a[l];
		ans[now] = 'L';
		if(IsHuiWen()){
			for(int i=1;i<=2*n;++i)putchar(ans[i]);
			putchar('\n');
			f=1;
		}
		return;
	}
	if(a[l]<=a[r]){
		tmp[now] = a[l],ans[now]='L',dfs(now+1,l+1,r);
		tmp[now] = a[r],ans[now]='R',dfs(now+1,l,r-1);
	}else{
		tmp[now] = a[r],ans[now]='R',dfs(now+1,l,r-1);
		tmp[now] = a[l],ans[now]='L',dfs(now+1,l+1,r);
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	T = read();
	while(~--T){
		n = read();
		for(int i=1;i<=2*n;++i) a[i] = read();
		f=0; 
		dfs(1,1,2*n);
		if(!f) printf("-1\n");
	}
	return 0;
}
