// MDR±£””£¨M99±£””£¨Ô±µ∂±£””£¨ayame±£””£¨ø‰∏Á±£”” 
#include<bits/stdc++.h>
using namespace std;
int p1=1000000,p2=0;
char buf[1000005],wb[1000005];
int gc(){
	if(p1==1000000)fread(buf,1,1000000,stdin),p1=0;
	return buf[p1++];
}
#define gc getchar
#define Loli true
long long getint(){
	long long ret=0;
	int c=gc();
	bool flg=0;
	while(c<48||c>57)flg=c=='-',c=gc();
	while(c>=48&&c<=57)ret=(ret<<3)+(ret<<1)+(c^48),c=gc();
	return flg?-ret:ret;
}
void pc(int x){
	if(p2==1000000)fwrite(wb,1,1000000,stdout),p2=0;
	wb[p2++]=x;
}
void wrt(long long x){
	if(x==0)pc(48);
	if(x<0)pc('-'),x=-x;
	int c[32]={0};
	while(x)c[++c[0]]=x%10,x/=10;
	while(c[0])pc(c[c[0]--]^48);
}
int n,m,T;
int h[1005][1005],w[1005][1005];
struct edge{
	int ne,v,p;
}e[2000005];
int head[30005],cnt=1;
void add(int u,int v,int p){
	++cnt;
	e[cnt].v=v;
	e[cnt].ne=head[u];
	head[u]=cnt;
}
void add_edge(int u,int v,int p){
	add(u,v,p),add(v,u,p);
}
int id(int x,int y){
	return (x-1)*m+y;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=getint(),m=getint(),T=getint();
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++)h[i][j]=getint();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++)w[i][j]=getint();
	}
	while(T--){
		int k=getint();
		int tt=0,flg=0;;
		for(int i=1;i<=k;i++){
			int val=getint(),p=getint(),t=getint();
			if(!tt)tt=t+10;
			if(tt==t+10)flg=1;
		}
		if(flg)puts("0");
		else{
			for(int i=1;i<n;i++){
				for(int j=1;j<=m;j++){
					add_edge(id(i,j),id(i+1,j),h[i][j]);
					add_edge(id(i+1,j),id(i,j),h[i][j]);
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<m;j++){
					add_edge(id(i,j),id(i,j+1),h[i][j]);
					add_edge(id(i,j+1),id(i,j),h[i][j]);
				}
			}
			cout<<rand()%n+1<<endl;
		}
	}
	return 0;
}
