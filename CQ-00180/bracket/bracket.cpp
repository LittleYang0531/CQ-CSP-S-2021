#include<bits/stdc++.h>
using namespace std;
# define ll long long
# define read read1<ll>()
# define Type template<typename T>
Type T read1(){
	T t=0;
	char k;
	bool vis=0;
	do (k=getchar())=='-'&&(vis=-1);while('0'>k||k>'9');
	while('0'<=k&&k<='9')t=(t<<3)+(t<<1)+(k^'0'),k=getchar();
	return vis?-t:t;
}
# define fre(k) freopen(k".in","r",stdin);freopen(k".out","w",stdout)
# define mod 1000000007
int f[505][505],n,k,g[505][505];
char str[505];
int sol(int,int);
int sol1(int l,int r){
	if(l>=r)return 0;
	if(str[l]!='('&&str[l]!='?'||str[r]!=')'&&str[r]!='?')return 0;
	if(l+1==r)return g[l][r]=1;
	if(~g[l][r])return g[l][r];
	ll t=0;
	for(int i=l+1;i<r&&i-l-1<=k;++i){
		t+=sol(i,r-1);
		if(str[i]!='*'&&str[i]!='?')break;
	}for(int i=r-1;i>l&&r-i-1<=k;--i){
		if(i!=r-1)t+=sol(l+1,i);
		if(str[i]!='*'&&str[i]!='?')break;
	}bool vis=0;
	if(r-l-1<=k){
		vis=1;
		for(int i=l+1;i<r;++i)if(str[i]!='*'&&str[i]!='?'){vis=0;break;}
		if(vis)t=(t+1)%mod;
	}
	return g[l][r]=t%mod;
}
int sol(int l,int r){
	if(l>=r)return 0;
	if(str[l]!='('&&str[l]!='?'||str[r]!=')'&&str[r]!='?')return 0;
	if(l+1==r)return 1;
	if(~f[l][r])return f[l][r];
	f[l][r]=sol1(l,r);
	ll ans=0,t=0;int la=l;
	for(int i=l+1;i<r;++i){
		while(i-la-1>k)t=(t-sol1(l,la)+mod)%mod,++la;
		ans=(ans+sol(i,r)*t)%mod;
		t=(t+sol1(l,i))%mod;
		if(str[i]!='*'&&str[i]!='?')
			while(la<i)t=(t-sol1(l,la)+mod)%mod,++la;
	}
	return f[l][r]=(f[l][r]+ans)%mod;
}
int main(){fre("bracket");
	memset(f,-1,sizeof(f));
	memset(g,-1,sizeof(g));
	n=read,k=read;
	scanf("%s",str+1);
	cout<<sol(1,n);
	return 0;
}

