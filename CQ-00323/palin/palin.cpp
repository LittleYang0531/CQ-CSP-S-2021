#include<bits/stdc++.h>
#define loop(i,from,to) for(int i=(from);i<=(to);++i)
#define reset(a,x) memset(a,x,sizeof a)
using namespace std;
const int maxn=10;
int T,n,step,tot,a[maxn*2+1],path[maxn*2+1];
char s[maxn*2+2];
bool check(void){
	loop(i,1,n)if(path[i]!=path[n*2-i+1])return false;
	return true;
}
bool dfs(int l,int r){
	if(l>r)return check();
	s[++tot]='L',path[tot]=a[l];
	if(dfs(l+1,r))return true;
	s[tot]='R',path[tot]=a[r];
	if(dfs(l,r-1))return true;
	--tot;
	return false; 
}
int main(){
	freopen("palin.in","r",stdin),freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),reset(s,0),tot=0;
		loop(i,1,n*2)scanf("%d",&a[i]);
		if(dfs(1,n*2))puts(s+1);
		else puts("-1");
	}
	return 0;
}
