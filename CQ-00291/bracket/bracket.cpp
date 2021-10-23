#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int mod=1000000007;
inline int read(){
	int x=0;char p=getchar();
	while(p<'0'||p>'9')p=getchar();
	while(p>='0'&&p<='9')x=(x<<3)+(x<<1)+(p^48),p=getchar();
	return x;
}
inline void pnum(int x){
	if (x>9) pnum(x/10);
	putchar(x%10+'0');
}
int n,k,c[505][3],top=0,g[505];
char s[505];
int dfs(int q,int l){
	int ans=0;
	if (q>=n||n-q<top) return (!top);
	if (c[q][0]!=-1) {
		top++,ans=(ans+dfs(q+1,0))%mod;
		if (!c[q][0])top--;
	}
	if (c[q][1]!=-1){
		if (top){top--,ans=(ans+dfs(q+1,0))%mod;}
		else if (c[q][1]==1)return 0;if (c[q][1]!=1)top++;
	}
	if (c[q][2]!=-1){
		if (l<k||(!g[top]||!l)) g[top]=1,ans=(ans+dfs(q+1,l+1))%mod;
		else if (c[q][2]==1)return 0;
	}
	return ans;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	scanf("%s",s);
	for (int i=0;i<n;i++){
		if (s[i]=='(')c[i][0]=1,c[i][1]=c[i][2]=-1;
		else if (s[i]==')')c[i][1]=1,c[i][0]=c[i][2]=-1;
		else if (s[i]=='*')c[i][2]=1,c[i][1]=c[i][0]=-1;
	}
	pnum(dfs(0,0));
	return 0;
}
