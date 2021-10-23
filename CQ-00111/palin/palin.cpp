#include<algorithm>
#include<cstdio>
typedef unsigned ui;
const int M=5e5+5,mod=1e9+7;
int n,T,a[M];ui p[M],ip[M],hash[M];
ui l[M],r[M];int top,stk[M];char ans[M],s[M];bool f,vis[M];
int L,R;
inline ui Hash(const int&L,const int&R){
	return 1ull*(hash[R]-hash[L]+mod)*ip[L]%mod;
}
inline bool check(const int&L,const int&R){
	int i,h1(0),h2(0),tp;
	for(tp=0,i=L;i<=R;++i)if(!vis[i])h1=(h1+1ull*a[i]*p[++tp])%mod;
	for(tp=0,i=R;i>=L;--i)if(!vis[i])h2=(h2+1ull*a[i]*p[++tp])%mod;
	return h1==h2;
}
inline void end(){
	if(f){
		for(int i=1;i<=n;++i){
			if(s[i]<ans[i]){
				for(i=1;i<=n;++i)ans[i]=s[i];
			}
			if(s[i]>ans[i])break;
		}
	}
	else{
		f=true;for(int i=1;i<=n;++i)ans[i]=s[i];
	}
}
inline bool todo(int L1,int R1,int L2,int R2){
	if(Hash(L1,R1)==Hash(L2,R2)){
		R1-=L1-1;while(R1--)s[++L]='L';
		R2-=L2-1;while(R2--)s[R--]='R';
		return end(),true;
	}
}
inline void make(int L1,int R1,int L2,int R2){
	int i,pL1,pR1,pL2,pR2;L=0;R=n;
	while(true){
		pL1=L1;pR1=R1;pL2=L2;pR2=R2;if(todo(L1,R1,L2,R2))return end();
		for(i=1;L1+i-1<=R1&&L1+i-1<R1-i+1;++i)if(a[L1+i-1]^a[R1-i+1])break;
		if(i^1){
			while(--i)s[++L]='L',s[R--]='L',++L1,--R1;if(todo(L1,R1,L2,R2))return end();
			if(R1+1==L1&&R2+1==L2)return end();continue;
		}
		for(i=1;L1+i-1<=R1&&L2+i-1<=R2&&L1;++i)if(a[L1+i-1]^a[L2+i-1])break;
		if(i^1){
			while(--i)s[++L]='L',s[R--]='R',++L1,++L2;if(todo(L1,R1,L2,R2))return end();
			if(R1+1==L1&&R2+1==L2)return end();continue;
		}
		for(i=1;L2+i-1<=R2&&L2+i-1<R2-i+1;++i)if(a[L2+i-1]^a[R2-i+1])break;
		if(i^1){
			while(--i)s[++L]='R',s[R--]='R',++L2,--R2;if(todo(L1,R1,L2,R2))return end();
			if(R1+1==L1&&R2+1==L2)return end();continue;
		}
		for(i=1;L1+i-1<=R1&&L2+i-1<=R2;++i)if(a[R1-i+1]^a[R2-i+1])break;
		if(i^1){
			while(--i)s[++L]='R',s[R--]='L',--R1,--R2;if(todo(L1,R1,L2,R2))return end();
			if(R1+1==L1&&R2+1==L2)return end();continue;
		}
		if(L1==pL1&&R1==pR1&&L2==pL2&&R2==pR2)return;
	}
}
signed main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int i;scanf("%d",&T);p[0]=ip[0]=1;p[1]=13331;ip[1]=133822550;
	for(i=2;i<=500000;++i)p[i]=13331ull*p[i-1]%mod,ip[i]=133822550ull*ip[i-1]%mod;
	while(T--){
		scanf("%d",&n);n<<=1;f=false;
		for(i=1;i<=n;++i)scanf("%d",a+i);
		for(i=1;i<=n;++i)hash[i]=(hash[i-1]+1ull*p[i]*a[i])%mod;
		if(n>=5000){
			for(i=2;i<=n;++i)if(a[i]==a[1])break;
			for(int j=-5;j<=5;++j)if(i+j>=1&&i+j<=n)make(1,i+j,i+j+1,n);
		}
		else for(i=1;i<=n;++i)make(1,i,i+1,n);ans[n]='L';
		if(!f)printf("-1\n");
		else{
			for(i=1;i<=n;++i)printf("%c",ans[i]);printf("\n");
		}
	}
}
