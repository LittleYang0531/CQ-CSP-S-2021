#include <bits/stdc++.h>
using namespace std;

const int N=510;

int n,k;
char ch[N];
int p[N],cnt;
int ans;
int s[N],tp;
int to[N];

void Print(){
	for(int i=1;i<=n;++i)printf("%c",ch[i]);
	printf("\n");
}

bool check(int l,int r){
//	printf("%d %d\n",l,r);
	if(l>r)return 1;
	int cnt=0;
	int res=1;
	bool flag=0;
	for(int i=l;i<=r;++i){
		if(to[i]){
			cnt=0;
			flag=1;
			res&=check(i+1,to[i]-1);
			i=to[i];
		}
		else ++cnt;
//		printf("%d %d\n",i,cnt);
		if(cnt>k){
//			cout<<"asdas";
			return 0;
		}
	}
	if(flag&&ch[l]=='*'&&ch[r]=='*')return 0;
//	printf("%d",res);
	return res;
}

void dfs(int d){
	if(d==cnt+1){
		for(int i=0;i<=n;++i)to[i]=0;
		tp=0;
		for(int i=0;i<=n;++i){
			if(ch[i]=='(')s[++tp]=i;
			else if(ch[i]==')'){
				if(tp==0)return;
				to[s[tp]]=i;
				--tp;
			}
		}
		if(tp>0)return;
//		printf("%d",check(2,6));
//		for(int i=1;i<=n;++i)printf("%d ",to[i]);
		if(ch[1]=='*'||ch[n]=='*')return;
		if((to[1]==n&&check(2,n-1)||(to[1]!=n&&check(1,n)))){
//			Print();
			++ans;
		}
		return;
	}
	ch[p[d]]='*';
	dfs(d+1);
	ch[p[d]]='(';
	dfs(d+1);
	ch[p[d]]=')';
	dfs(d+1);
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	scanf("%s",ch+1);
	for(int i=1;i<=n;++i){
		if(ch[i]=='?')p[++cnt]=i;
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
