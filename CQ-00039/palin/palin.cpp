#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mxdt=100000;
char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int T,n,a[1000005],tp[1000005],opp[1000005];
int s[1000005],opt[1000005],top;
void output(int l,int r){
	for(int i=1;i<=n;++i){
		putchar(opt[i]?'R':'L');
	}
	for(int i=n;i;--i){
		if(a[l]==s[i])putchar('L'),++l;
		else putchar('R'),--r;
	}
	puts("");
}
bool dfs(int l,int r,int L,int R,int dep){
	if(l==L&&r==R){
		output(L,R);return 1;
	}
	if(l!=L&&(opp[l]==L-1||opp[l]==R+1)){
		s[dep+1]=a[l];opt[dep+1]=0;
		return dfs(l+1,r,min(L,opp[l]),max(R,opp[l]),dep+1);
	}
	if(r!=R&&(opp[r]==L-1||opp[r]==R+1)){
		s[dep+1]=a[r];opt[dep+1]=1;
		return dfs(l,r-1,min(L,opp[r]),max(R,opp[r]),dep+1);
	}
	return 0;
}
int main(){
//	system("fc palin.out palin2.ans");
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read()+1;
	while(--T){
		n=read();
		for(int i=1;i<=n;++i)tp[i]=0;
		for(int i=1;i<=2*n;++i)opp[i]=s[i]=opt[i]=0;
		for(int i=1;i<=(n<<1);++i){
			a[i]=read();
			if(tp[a[i]]){
				opp[tp[a[i]]]=i;
				opp[i]=tp[a[i]];
			}
			else tp[a[i]]=i;
		}
		s[1]=a[1];opt[1]=0;
		if(!dfs(2,n<<1,opp[1],opp[1],1)){
			s[1]=a[n<<1];opt[1]=1;
			if(!dfs(1,2*n-1,opp[n<<1],opp[n<<1],1)){
				puts("-1");
			}
		}
	}
	return 0;
}
