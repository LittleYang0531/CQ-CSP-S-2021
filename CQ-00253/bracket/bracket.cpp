#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int Maxn=5e2;
char s[Maxn+5];
int a[Maxn+5],n,k,ans;
void dfs(int dep,int now,int ed) {
	if(dep>n) {
		if(now==0&&ed==0) {
			int cnt=0;
			for(ri i=2;i<n;i++) {
				int x=i;
				while(a[x]==0)++x;
				--x;
				if(i>x)continue;
				if(a[i-1]+a[x+1]!=0) {
					++cnt;
					if(cnt>=2)return ;
				}
				else cnt=0;
				i=x;
			}
			++ans;
		}
		return ;
	}
	else {
		if(s[dep]!='?') {
			if(s[dep]=='(') {
				a[dep]=1;
				dfs(dep+1,now+1,0);
			}
			else if(s[dep]==')') {
				if(now) {
					a[dep]=-1;
					dfs(dep+1,now-1,0);
				}
			}
			else if(dep!=1) {
				a[dep]=0;
				dfs(dep+1,now,ed+1);
			}
		}
		else {
			if(ed<k&&dep!=1) {
				a[dep]=0;
				dfs(dep+1,now,ed+1);
			}
			a[dep]=1;
			dfs(dep+1,now+1,0);
			if(now) {
				a[dep]=-1;
				dfs(dep+1,now-1,0);
			}
		}
	}
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	dfs(1,0,0);
	printf("%d\n",ans);
	return 0;
}
