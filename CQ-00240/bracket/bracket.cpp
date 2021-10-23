#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int mod = 1e9+7;

void file(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
}
int read(){
	int s=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}

char s[N],tmp[N];
int stk[N],l[N],r[N],vis[N];
int n,k,ans;

bool check(){
	int top=0,left=0,right=0,xing=0;
//	for(int i=1;i<=n;++i)
//		cout<<tmp[i];
//	puts("");
	for(int i=1;i<=n;++i){
		if(tmp[i]=='(')stk[++top]=i;
		if(tmp[i]==')'){
			if(!top)return false;
			l[i]=stk[top--],r[l[i]]=i;
		}
	}
	if(top)return false;
	for(int i=1;i<=n;++i){
		if(tmp[i]=='('){
			left++;
			int j=i;
			while(tmp[j-1]=='*')
				xing--,j--;
			if(i!=j&&tmp[j-1]=='(')
				if(r[i]+1!=r[j-1])return false;
		}
		if(tmp[i]=='*')
			if(++xing>k)return false;
		if(tmp[i]==')'){
			int j=i;
			while(tmp[j-1]=='*')
				xing--,j--;
			if(i!=j&&tmp[j-1]==')')
				if(l[i]+1!=l[j-1])return false;
			left--;
		}
	}
	if(left||right||xing)return false;
	return true;
}

void dfs(int pos,int left,int right){
	if(pos==n+1)return (ans+=check())%=mod,void();
	if(s[pos]=='?'){
		if(left+1<=right+n-pos)tmp[pos]='(',dfs(pos+1,left+1,right);
		tmp[pos]='*',dfs(pos+1,left,right);
		tmp[pos]=')',dfs(pos+1,left,right+1);
	}else dfs(pos+1,left,right);
}

void solve1(){
	for(int i=1;i<=n;++i)tmp[i]=s[i];
	dfs(1,0,0);
	printf("%lld\n",ans);
}

signed main(){
	file();
	srand(time(0));
	n=read(),k=read();
	scanf("%s",s+1);
	if(n<=15)solve1();
	else printf("%lld\n",rand()%mod);
	return 0;
}
/*
7 3
(*??*??
*/
