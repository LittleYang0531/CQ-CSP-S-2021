#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1000000007;
int n,k,nums=0,ans=0;
bool qs[505];
char str[505],th[3]={'*','(',')'};
inline bool test(){
	int t=0,p=0;
	if(str[1]!='('||str[n]!=')') return 0;
	for(int i=2;i<=n-1;i++) {
		if(str[i]=='(') t++;
		if(str[i]==')')t--;
		if(t<0) return 0;
	}
	if(t!=0) return 0;
	for(int i=2;i<=n-1;i++){
		if(str[i]=='*')p++;
		if(str[i]=='('||str[i]==')')p=0;
		if(p>k) return 0;
		if(n-i>3&&str[i]=='*'&&str[i+1]=='('&&str[i+2]==')'&&str[i]=='*') return 0;
	}
	return 1;
}
inline void dfs(int bb){
	if(bb>n) {
//		for(int i=0;i<=n;i++) printf("%c",str[i]);
		if(test()) ans++;
//		printf("fin\n");
		return ;
	}
	if(!qs[bb]) {
		dfs(bb+1);
		return ;
	}
	for(int i=0;i<3;i++){
		str[bb]=th[i];
		dfs(bb+1);
	}
	return ;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	memset(qs,0,sizeof(qs));
	cin>>str;
	for(int i=1;i<=n;i++){
		if(str[i]=='?') qs[i]=1;
	}
	for(int i=1;i<=n;i++){
		dfs(1);
	}
	printf("%d",ans);
	
	return 0;
}
