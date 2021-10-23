#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=505,mod=1e9+7;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
char s[maxn];
int n,k;
ll f[maxn][maxn][4],g[maxn][maxn],ans;
bool pd[maxn][maxn];
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
//	cout<<((sizeof(f)+sizeof(g)+sizeof(pd))>>20);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1; i<=n; i++)
		for(int j=i; j<=n&&j-i<k; j++) {
			if(s[j]=='('||s[j]==')')break;
			pd[i][j]=1;
//			cout<<i<<' '<<j<<"*\n"; 
		}
	for(int i=2; i<=n; i++)f[i][i-1][0]=1;
	for(int i=1; i<=n; i++)
		if(pd[i][i])f[i][i][3]=1;
	for(int l=1; l<n; l++)
		for(int i=1; i<=n-l; i++) {
			int j=i+l;
			if((s[i]=='?'||s[i]=='(')&&(s[j]=='?'||s[j]==')'))
				g[i][j]=(f[i+1][j-1][0]+f[i+1][j-1][1]+f[i+1][j-1][2]+g[i+1][j-1]+pd[i+1][j-1])%mod;//独立括号
			f[i][j][3]=pd[i][j];
			for(int k=i; k<j; k++) {
				if(pd[i][k])
					f[i][j][3]=(f[i][j][3]+f[k+1][j][1])%mod,f[i][j][2]=(f[i][j][2]+f[k+1][j][0]+g[k+1][j])%mod;
				if(g[i][k])
					f[i][j][0]=(f[i][j][0]+g[i][k]*(g[k+1][j]+f[k+1][j][0]+f[k+1][j][2]))%mod,f[i][j][1]=(f[i][j][1]+g[i][k]*(f[k+1][j][1]+f[k+1][j][3]))%mod;
			}
//			cout<<i<<' '<<j<<' '<<g[i][j]<<' '<<f[i][j][0]<<' '<<f[i][j][1]<<' '<<f[i][j][2]<<' '<<f[i][j][3]<<endl;
		}
	printf("%lld",(g[1][n]+f[1][n][0])%mod);
	return 0;
}
//你是一个一个一个，一个一个一个哼哼啊啊啊啊啊啊啊啊啊啊啊啊啊1145141919810

