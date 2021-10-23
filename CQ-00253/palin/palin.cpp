#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int Maxn=5e5;
int a[Maxn*2+5],b[2*Maxn+5],x[2*Maxn+5],y[2*Maxn+5],T,n,ans;
void dfs(int dep,int head,int tail) {
	if(dep>n) {
		for(ri i=n;i>=1;i--) {
			if(a[head]==b[i]) {
				y[2*n-i+1]=0;
				++head;
			}
			else if(a[tail]==b[i]) {
				y[2*n-i+1]=1;
				--tail;
			}
			else return ;
		}
		for(ri i=1;i<=2*n;i++)
			if(x[i]!=y[i]) {
				if(x[i]<y[i])return ;
				for(ri j=1;j<=2*n;j++)x[j]=y[j];
				return ;
			}
		return ;
	}
	else {
		b[dep]=a[head];y[dep]=0;
		dfs(dep+1,head+1,tail);
		b[dep]=a[tail];y[dep]=1;
		dfs(dep+1,head,tail-1);
	}
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(ri i=1;i<=2*n;i++)scanf("%d",&a[i]),x[i]=2;
		dfs(1,1,2*n);
		if(x[1]==2) {
			printf("-1\n");
			continue;
		}
		for(ri i=1;i<=2*n;i++)putchar(x[i]?'R':'L');
		puts("");
	}
	return 0;
}

