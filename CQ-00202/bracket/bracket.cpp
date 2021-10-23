#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int mod=1000000007;
int n,k;
char s[600];
char ex[600];
char hp[3]={'(',')','*'};
void print() {
	printf("!%s!\n",ex+1);
//	int i;
//	printf("!");
//	for(i=1;i<=n;++i)
//		printf("%c",ex[i]);
//	puts("!");
	return;
}
bool check() {
	int zuo=0;
	int nu;
	int i;
	int nl,nr;
	//print();
	for(i=1;i<=n;++i) {
		nu=0;
		if(ex[i]=='(') {
			++zuo;
			if(i!=1&&i!=n-1&&ex[i+1]==')')
				return 0;
		}
			
		else if(ex[i]==')')
			--zuo;
		else if(ex[i]=='*') {
			nl=i;
			while(i<=n&&ex[i]=='*') {
				++i;
				++nu;
				if(nu>k)
					return 0;
			}
			nr=i-1;
			--i;
			//printf("[%c %c]\n",ex[nl],ex[nr]);
			if(nl==1||nr==n)
				return 0;
		}
		if(zuo<0)
			return 0;
	}
	if(nu>k||zuo!=0)
		return 0;
	return 1;
}
int dfs(int i) {
	//printf("%d\n",i);
	if(i>n) {
		bool p;
		p=check();
		//print();
		//printf("%d\n",p);
		if(p==1) {
			return 1;
		}
			
		return 0;
	}
	while(s[i]!='?'&&i<=n) {
		++i;
	}
	if(i>n)
		return dfs(i)%mod;
	int ans=0;
	for(int j=0;j<=2;++j) {
		ex[i]=hp[j];
		ans+=dfs(i+1);
		ans%=mod;
	}
	//printf("%d %d\n",i,ans);
	//print();
	//if(i==n&&ans==0)
	//	ans=(dfs(i+1))%mod;	
	return ans%mod;
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int i;
	if(n<=100) {
		int nu;
		for(i=1;i<=n;++i) {
			nu=0;
			while(i<=n&&s[i]=='*') {
				++nu;
				++i;
			}
		}
		for(i=1;i<=n;++i)
			if(s[i]!='?')
				ex[i]=s[i];
		if(nu>k)//存在一条*长度大于k 
			printf("0");
		else
			printf("%d",dfs(1)%mod);
	}
	
	return 0;
}
