#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
const int N=510;
LL ans=0;
int len,k,wen[N],z[N],you[N];
char s[N];
bool pd(){
	int tot=0;
	for(int i=1;i<=len;i++){
		if(s[i]=='('){
			if(s[i+1]=='*') z[++tot]=1;
			else z[++tot]=0;
		}
		if(s[i]==')'){
			if(s[i-1]=='*'&&z[tot]==2){
				return false;
			}
			tot--; 
			z[tot]++;
		}
	}
	return true;
}
void dfs(int x,int xing,int zuo){
	if(x==len+1){
		if(zuo||xing) return;
		if(pd()) ans++, ans%=mod;
		return;
	}
	if(s[x]=='?'){
		if(xing+1<=k&&x!=1){// *
			s[x]='*';
			dfs(x+1,xing+1,zuo);
			s[x]='?';
		}
		if(wen[len]-wen[x]+you[len]-you[x]>=zuo+1){// (
			s[x]='(';
			dfs(x+1,0,zuo+1);
			s[x]='?';
		}
		if(zuo>0){// )
			s[x]=')';
			dfs(x+1,0,zuo-1);
			s[x]='?';
		}
	}
	else{
		if(s[x]=='*'){
			if(xing+1>k) return;
			dfs(x+1,xing+1,zuo);
		}
		if(s[x]=='('){
			if(wen[len]-wen[x]+you[len]-you[x]<zuo+1) return;
			dfs(x+1,0,zuo+1);
		}
		if(s[x]==')'){
			if(zuo==0) return;
			dfs(x+1,0,zuo-1);
		}
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&len,&k);
	scanf("%s",s+1);
	for(int i=1;i<=len;i++){
		wen[i]=wen[i-1];
		you[i]=you[i-1];
		if(s[i]=='?') wen[i]++;
		if(s[i]==')') you[i]++;
	}
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
/*
100 18
?*?????)?????*????????*??(*???????*????????????*???*?????*?????*??????*****??*??????????*???????????
860221334

7 3 
(*??*??

10 2
???(*??(?)
*/
