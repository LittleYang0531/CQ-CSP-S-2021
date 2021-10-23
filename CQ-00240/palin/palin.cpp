#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;

void file(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
}
int read(){
	int s=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}

char ans[N<<1];
int a[N<<1],cho[N<<1];
int T,n,fg;

bool check(){
	int i=0;
	cho[0]='(',cho[2*n+1]=')'; 
	while(cho[n-i]==cho[n+1+i])++i;
	if(i==n)return true;
	else return false;
}
void dfs(int pos,int l,int r){
	if(pos==n*2+1)return fg=check(),void();
	if(fg)return ;if(pos<=n||a[l]==cho[2*n-pos+1])cho[pos]=a[l],ans[pos]='L',dfs(pos+1,l+1,r);
	if(fg)return ;if(pos<=n||a[r]==cho[2*n-pos+1])cho[pos]=a[r],ans[pos]='R',dfs(pos+1,l,r-1);
}

signed main(){
	file();
	T=read();
	while(T--){
		n=read(),fg=0;
		for(int i=1;i<=n<<1;++i)
			a[i]=read();
		dfs(1,1,n*2);
		if(fg){
			for(int i=1;i<=n<<1;++i)
				putchar(ans[i]);
			puts("");
		}else puts("-1");
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
