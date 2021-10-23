#include<bits/stdc++.h>
using namespace std;
const int N=505,P=1e9+7;
int n,k,t[N],f[N][N];char s[N];
int xxx(int l,int r){return (r-l+1<=k)&&(r-l+1==t[r]-t[l-1]);}
int dfs(int l,int r){
	if(f[l][r])return f[l][r];
	if((s[l]!='('&&s[l]!='?')||(s[r]!=')'&&s[r]!='?'))return 0;
	for(int i=l+2;i<=r-1;i++)
	if(xxx(i+1,r-1))f[l][r]+=dfs(l+1,i),f[l][r]-=f[l][r]>=P?P:0;
	for(int i=r-2;i>=l+1;i--)
	if(xxx(l+1,i-1))f[l][r]+=dfs(i,r-1),f[l][r]-=f[l][r]>=P?P:0;
	for(int a=l+1;a<=r-2;a++)
	for(int b=r-1;b>=a+1;b--)
	if(xxx(a+1,b-1))f[l][r]=(1ll*dfs(l,a)*dfs(b,r)+f[l][r])%P;
	if(xxx(l+1,r-1))f[l][r]++,f[l][r]-=f[l][r]>=P?P:0;
	return f[l][r];
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;i++)
	t[i]=t[i-1]+(s[i]=='*'||s[i]=='?');
	printf("%d",dfs(1,n));
	return 0;
}

