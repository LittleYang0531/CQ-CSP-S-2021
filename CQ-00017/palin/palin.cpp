#include<bits/stdc++.h>
using namespace std;

#define N 500005

namespace CSP_P{
	#define f(a,b,i) for(int i=a;i<=b;i++)
	#define f_(a,b,i) for(int i=a;i>=b;i--)
	#define LL long long
	#define db double 
	#define U unsigned
	#define ULL U LL
	#define gc() getchar()
	
	const int inf=0x3f3f3f3f,INF=0x7fffffff;
	const LL infll=0x3f3f3f3f3f3f3f3fll,INFll=0x7fffffffffffffffll;
	
	template<typename T>void read(T &num){
		num=0;
		T f=1;
		char c=gc();
		while(!isdigit(c)){
			if(c=='-')f=-1;
			c=gc();
		}
		while(isdigit(c)){
			num=(num<<1)+(num<<3)+(c^48);
			c=gc();
		}
		num*=f;
	}
	template<typename T,typename ... Agrs>void read(T &x,Agrs &...agrs){
		read(x);
		read(agrs...);
	}
} 
using namespace CSP_P;

int n;

int a[2*N];

int b[2*N],tot=0,f=0;
char c[2*N];

void dfs(int l,int r){
//	cout<<l<<" "<<r<<endl;
	if(f)return;
	if(l>r){
	
//	cout<<endl;
		f(1,n,i){
			if(b[i]!=b[2*n-i+1])return;
		}
		f(1,2*n,i)printf("%c",c[i]);
		printf("\n");
		f=1;
		return ;
	}
	b[++tot]=a[l];
	c[tot]='L';
	dfs(l+1,r);
	c[tot]='R';
	b[tot]=a[r];
	dfs(l,r-1);tot--;
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	read(T);
	while(T--){
		read(n);
		
		f(1,2*n,i)read(a[i]);
		if(n>=20){
			printf("-1\n");
			continue;
		}
		tot=0;
		f=0;
		dfs(1,2*n);
		if(!f)printf("-1\n");
	}
	return 0;
}
