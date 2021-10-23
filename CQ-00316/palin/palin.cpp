#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,a[200005],v[200005],v2[200005];
bool dfs(int l,int r,string sum,string p) {
	if(p.length()>n&&p[p.length()-1]!=p[n-p.length()+n])return 0;;
	if(l==r) {
		sum+='L';
		p+=a[l]+'0';
		cout<<sum<<endl;
		return 1;
	}
	if(dfs(l+1,r,sum+'L',p+(char)(a[l]+'0')))return 1;	
	if(dfs(l,r-1,sum+'R',p+(char)(a[r]+'0')))return 1;
	return 0;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		memset(v,0,sizeof(v));
		memset(v2,0,sizeof(v2));
		for(int i=1;i<=n*2;i++)scanf("%d",a+i),v[a[i]]++,v2[a[i]]++;
		if(n>20) {
			for(int i=1;i<=n*2;i++)putchar('L');
			putchar('\n');
		}else {
			bool ok=1;
			for(int i=1;i<=n;i++){
				if(v[a[i]]&1) {
					puts("-1");
					break;
				}
			}
			if(!ok)continue;
			if(!dfs(1,2*n,"",""))puts("-1");
		}
	}
	return 0;
}
