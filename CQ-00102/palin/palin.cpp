#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2005;
int n,b[N],a[N],tg=0,T;char ans[N];
void Force(int dep,int l,int r){
	if(tg)return;
	if(dep==2*n+1){
		int it=0;
		for(int i=1;i<=n;i++){
			if(b[i]!=b[2*n-i+1])it=1;
		}
		if(it==0){
			for(int i=1;i<=2*n;i++){
				putchar(ans[i]);
			}tg=1;puts("");
		}
		return;
	}
	b[dep]=a[l],ans[dep]='L';Force(dep+1,l+1,r);
	b[dep]=a[r],ans[dep]='R';Force(dep+1,l,r-1);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int i;
	scanf("%d",&T);
	while(T--){
		memset(b,0,sizeof(b));
		scanf("%d",&n);tg=0;
		for(i=1;i<=2*n;i++)scanf("%d",&a[i]);
		Force(1,1,n*2);if(!tg)puts("-1");
	}
}
