#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,a[1000005],b[1000005],fl;
char c[1000005];
void dfs(int l){
	if(l>n+1&&b[l-1]!=b[2*n-l+2])return;
	if(l>2*n){fl=1;return;}
	if(!fl)b[l]=a[x++],c[l]='L',dfs(l+1),x--;
	if(!fl)b[l]=a[y--],c[l]='R',dfs(l+1),y++;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n),x=1,y=2*n,fl=0;
		for(int i=1;i<=2*n;i++)scanf("%d",&a[i]),b[i]=0,c[i]='\0';
		dfs(1);
		if(fl)printf("%s\n",c+1);
			else printf("-1\n");
	}
	return 0;
}
