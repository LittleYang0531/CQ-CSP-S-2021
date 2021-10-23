#include<bits/stdc++.h>
using namespace std;
int n,k,ans,cnt,sp[510];
int cntl[510],cntr[510];
char ch[510]; 
bool vis[510];
int check(int now){
	vis[now]=1;
	int x=now+1,l,r;
	while(ch[x]!=')'&&x<n){
		x++;
		if(ch[x]=='('){
			l=x,r=check(l);
			if(r==114514)return r;
			if(ch[l-1]=='*'&&ch[r+1]=='*')return 114514;
			x=r+1;
		}
	}
	for(int i=x+1;i<n-1;i++){
		if(ch[i]=='('&&!vis[i]){
			r=check(i);
			if(r==114514)return r;
		}
	}
	
	return x;
}
void dfs(int x,int cntl,int cntr){
	if(x>cnt){
		for(int i=sp[x-1]+1;i<n;i++){
			if(ch[i]=='(')cntl++;
			else if(ch[i]==')') cntr++;
		}
		if(cntl!=cntr)return ;
		if(check(0)!=114514)ans++;
		return ;
	}
	if(sp[x]==0){
		ch[0]='(';
		dfs(x+1,cntl+1,cntr);
		return ;
	}
	if(sp[x]==n-1){;
		if(cntl-1!=cntr)return ;
		ch[n-1]=')';
		dfs(x+1,cntl,cntr+1);
		return ;
	}
	int cntx=0,now=sp[x-1];
	while(ch[now]=='*'){
		cntx++;
		if(cntx==k)break;
	}
	for(int i=sp[x-1]+1;i<sp[x];i++){
		if(ch[i]=='(')cntl++;
		else if(ch[i]==')') cntr++;
	}
	if(cntx<k){
		ch[sp[x]]='*';
		dfs(x+1,cntl,cntr);
	}
	ch[sp[x]]='(';
	dfs(x+1,cntl+1,cntr);
	if(cntl>cntr){
		ch[sp[x]]=')';
		dfs(x+1,cntl,cntr+1);
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",ch);
	int len=strlen(ch);
	for(int i=0;i<len;i++)if(ch[i]=='?')sp[++cnt]=i;
	if(ch[n-1]=='('||ch[0]==')'){
		puts("0");
		return 0;
	}
	sp[0]=-1;
	dfs(1,0,0); 
	printf("%d",ans);
	return 0;
}

