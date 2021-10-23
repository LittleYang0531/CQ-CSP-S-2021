#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<cmath>
#include<vector>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch-48);
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x)write(x/10);
	putchar(x%10+48);
}
int T,n,a[1000005],len,A[1000005];
bool flag=0;
char ans[1000005],nans[1000005];
void dfs(int l,int r){
	if(l>r){
		for(int i=1;i<=n;i++)
			if(A[i]!=A[n-i+1])return ;
		if(!flag){
			flag=1;
			for(int i=1;i<=n;i++)ans[i]=nans[i];
		}else{
			for(int i=1;i<=n;i++){
				if(ans[i]==nans[i])continue;
				if(ans[i]<nans[i])return ;
				ans[i]=nans[i];
			}
		}
		return ;
	}
	nans[++len]='L';
	A[len]=a[l];
	dfs(l+1,r);
	--len;
	nans[++len]='R';
	A[len]=a[r];
	dfs(l,r-1);
	--len;
}
signed main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		n=read()*2;
		flag=0;
		for(int i=1;i<=n;i++)a[i]=read();
		dfs(1,n);
		if(!flag)puts("-1");
		else{
			for(int i=1;i<=n;i++)printf("%c",ans[i]);
			puts("");
		}
	}
	return 0;
	
}

