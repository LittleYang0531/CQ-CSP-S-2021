#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
const int N=1e6+10;
int n,a[N],blk[N];
int b[N],lst[N];
int op[N],tp;
bool check(int p){
	if(blk[p])return 0;
	return blk[b[p]+1]||blk[b[p]-1];
}
void output(int L,int R){
	int nl=L-1,nr=R+1;
	Rof(i,n,1){
		if(op[i]==0){
			int p=b[nl--];
			if(p==L)op[++tp]=0,L++;
			else if(p==R)op[++tp]=1,R--;
			else assert(0);
		}else{
			int p=b[nr++];
			if(p==L)op[++tp]=0,L++;
			else if(p==R)op[++tp]=1,R--;
			else assert(0);
		}
	}
	For(i,1,2*n)putchar(op[i]?'R':'L');puts("");
}
signed main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=read();while(T--){
		n=read();For(i,1,2*n)a[i]=read();
		memset(lst,0,sizeof lst);
		memset(blk,0,sizeof blk);
		int L=0,R=0;
		For(i,1,2*n){
			if(!lst[a[i]])lst[a[i]]=i;
			else b[lst[a[i]]]=i,b[i]=lst[a[i]];
		}
		op[tp=1]=0,L=2,R=2*n,blk[b[1]]=1;For(i,2,n){
			if(check(L))op[++tp]=0,blk[b[L]]=1,L++;
			else if(check(R))op[++tp]=1,blk[b[R]]=1,R--;
			else break;
		}
		if(tp==n){output(L,R);continue;}
		memset(blk,0,sizeof blk);
		op[tp=1]=1,L=1,R=2*n-1,blk[b[2*n]]=1;For(i,2,n){
			if(check(L))op[++tp]=0,blk[b[L]]=1,L++;
			else if(check(R))op[++tp]=1,blk[b[R]]=1,R--;
			else break;
		}
		if(tp==n){output(L,R);continue;}
		puts("-1");
	}
	return 0;
}

