#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int T,n,a[1000001],b[1000001],h,t;
bool v[1000001],p[1000001];
bool dfs(int s) {
	if(s==2*n+1) return 1;
	if(s>n) {
		int x=b[n-(s-n)+1];
		if(a[h]==x) {
			p[s]=0;
			h++;
			if(dfs(s+1)) return 1;
			h--;
			return 0;
		}
		if(a[t]==x) {
			p[s]=1;
			t--;
			if(dfs(s+1)) return 1;
			t++;
			return 0;
		}
		return 0;
	} else {
		if(!v[a[h]]) {
			b[s]=a[h];
			p[s]=0;
			h++;
			v[a[h]]=1;
			if(dfs(s+1)) return 1;
			h--;
			v[a[h]]=0;
		}
		if(!v[a[t]]) {
			b[s]=a[t];
			p[s]=1;
			t--;
			v[a[t]]=1;
			if(dfs(s+1)) return 1;
			t++;
			v[a[t]]=0;
		}
		return 0;
	}
}
void print() {
	for(int i=1; i<=2*n; i++)
		if(p[i]) putchar('R');
		else putchar('L');
	puts("");
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		if(n>30) {
			puts("-1");
			continue;
		}
		h=1;
		t=2*n;
		for(int i=1; i<=2*n; i++)
			scanf("%d",a+i);
		if(dfs(1)) print();
		else puts("-1");
	}
	return 0;
}
