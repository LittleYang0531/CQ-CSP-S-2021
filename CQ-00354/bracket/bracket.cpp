#include <iostream>
#include <cstdio>
using namespace std;
const int mod = 1e9+7;
inline int rd() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
		x=(x<<3)+(x<<1)+c-48,c=getchar();
	return x*f;
}
int n,sb,num,top,tot;
long long sum=0;
string s;
void dfs(int x,int k,int fuckccf) {//第i个字符，有k个前括号，**个*
	if(x==n&&k==0) {
		sum++;
		sum%=mod;
//		puts("");
		return ;
	} else if(x==n)return ;
	if(s[x]=='?') {
		if(k) {
//			printf(")");
			dfs(x+1,k-1,0);    //)
		}
//		printf("(");
		dfs(x+1,k+1,0);//(
		if(fuckccf<=sb) {
//			printf("*");
			dfs(x+1,k,fuckccf+1);//*
		}
	} else if(s[x]=='*'){
//		printf("*");
		dfs(x+1,k,fuckccf+1);
	}
	else if(s[x]=='('){
//		printf("(");
		dfs(x+1,k+1,fuckccf);
	}
	else if(s[x]==')'){
//		putchar(')');
		dfs(x+1,k-1,fuckccf);
	}
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&sb);
	cin>>s;
	dfs(0,0,0);
	printf("%lld",sum/2);
	return 0;
}
