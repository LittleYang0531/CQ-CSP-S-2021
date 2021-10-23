#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int T,n,a[2*N+5];
int ch[2*N+5],flag,tmp[2*N+5],len;
int check()
{
	int l=1,r=2*n;len=0;
	for(int i=1; i<=n; i++)
	{
		if(ch[i]=='L') tmp[++len]=a[l],l++;
		else tmp[++len]=a[r],r--;
	}
	int v=n;
	for(int i=n; i>=1; i--)
		if(a[l]==tmp[i]) ch[++v]='L',++l;
		else if(a[r]==tmp[i]) ch[++v]='R',--r;
		else return 0;
	return 1;
}
void dfs(int p)
{
	if(p==n+1) {if(check()) {for(int i=1; i<=2*n; i++) printf("%c",ch[i]);puts("");flag=1;}return;}
	ch[p]='L';dfs(p+1);if(flag) return;
	ch[p]='R';dfs(p+1);if(flag) return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);flag=0;
		for(int i=1; i<=2*n; i++) scanf("%d",&a[i]);
		dfs(1);if(!flag) puts("-1");
	}
	return 0;
}
