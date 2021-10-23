#include<bits/stdc++.h>
using namespace std;
inline int read(){
	register int x=0,f=1;
	register char c=getchar();
	while(c<'0' or c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' and c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
int n,k;
char s[1000];
int f[1000][1000];
//void check(){
//	      ccf dies as soon as possible
//}       is there any problem here?
//void dfs()
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int cnt=0;
	n=read(); k=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) if(s[i]=='?') cnt++;
	printf("%d",int(pow(3,cnt))/(n-k)-1);
	return 0;
}
