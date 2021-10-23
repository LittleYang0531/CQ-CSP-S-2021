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
int s,a[500005],b[500005];
bool nv;
void sol1(){
	int w=0;
	b[1]=b[s]=0;
	for(int i=2;i<=s;++i)
		if(a[i]==a[1]){w=i;break;}
	for(int l=2,r=s,x=w,y=w,u=2,v=s-1;l!=x||r!=y;){
		if(l!=x)
			if(l+1!=x&&a[l]==a[x-1]){
				b[u++]=b[v--]=0;
				++l;--x;
				continue;
			}else if(a[l]==a[y+1]){
				b[u++]=0;b[v--]=1;
				++l;++y;
				continue;
			}
		if(r!=y)
			if(a[r]==a[x-1]){
				b[u++]=1;b[v--]=0;
				--r;--x;
				continue;
			}else if(r-1!=y&&a[r]==a[y+1]){
				b[u++]=b[v--]=1;
				--r;++y;
				continue;
			}
		return;
	}nv=1;
}void sol2(){
	int w=0;
	b[1]=1;b[s]=0;
	for(int i=1;i<s;++i)
		if(a[i]==a[s]){w=i;break;}
	for(int l=1,r=s-1,x=w,y=w,u=2,v=s-1;l!=x||r!=y;){
		if(l!=x)
			if(l+1!=x&&a[l]==a[x-1]){
				b[u++]=b[v--]=0;
				++l;--x;
				continue;
			}else if(a[l]==a[y+1]){
				b[u++]=0;b[v--]=1;
				++l;++y;
				continue;
			}
		if(r!=y)
			if(a[r]==a[x-1]){
				b[u++]=1;b[v--]=0;
				--r;--x;
				continue;
			}else if(r-1!=y&&a[r]==a[y+1]){
				b[u++]=b[v--]=1;
				--r;++y;
				continue;
			}
		return;
	}nv=1;
}
int main(){fre("palin");
	for(int T=read;T--;){
		s=read;nv=0;s<<=1;
		for(int i=1;i<=s;++i)a[i]=read;
		sol1();
		if(!nv)sol2();
		if(nv)for(int i=1;i<=s;++i)putchar(b[i]?'R':'L');
		else printf("-1");putchar('\n');
	}
	return 0;
}

