#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define inf 0x7fffffff
using namespace std;
int T,n;
int a[1000005],b[1000005];
int head,tail,top;
int ans[1000005],z[1000005],topz;
void copy() {
	for(int i=1;i<=(n<<1);++i)
		ans[i]=z[i];
}
void print() {
	for(int i=1;i<=(n<<1);++i)
		printf("%d",b[i]);
	puts("");
}
int bo() {
	for(int i=1;i<=n;i++)
		if(b[i]!=b[n*2-i+1])
			return 0;
	return 1;
}
void dfs(int x) {
	if(x>(n<<1)) {
//		print();
		if(!bo()) return ;
//		puts("1");
		int f=0;
		for(int i=1;i<=(n<<1);++i) {
			if(ans[i]>z[i]) {
				f=1;
				break;
			}	
			else if(ans[i]<z[i])
				break;
		}
		if(f)
			copy();
		return ;
	}
	b[++top]=a[++head];
	z[++topz]=1;
	dfs(x+1);
	--top,--head;
	--topz;
	b[++top]=a[--tail];
	z[++topz]=2;
	dfs(x+1);
	--top,++tail;
	--topz;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T) {
		scanf("%d",&n);
		head=0;
		tail=n*2+1;
		top=0;
		topz=0;
		memset(ans,0x3f,sizeof(ans));
		for(int i=1;i<=(n<<1);i++)
			scanf("%d",&a[i]);
		dfs(1);
		if(ans[1]==0x3f3f3f3f) {
			puts("-1");
			continue;
		}
		for(int i=1;i<=(n<<1);i++) {
			if(ans[i]==1)
				printf("L");
			else if(ans[i]==2)
				printf("R");
		}
		puts("");
	}
	return 0;
}
//sto CRN GYH orz
//1
//5
//4 1 2 4 5 3 1 2 3 5
