#include<bits/stdc++.h>
#define RI register int
using namespace std;
const int N=1000005;
int a[N],zc[N],ans[N],n,bb[N];
vector<int>q;
template<typename T>
void Read(T &t){
	t=0;
	char c;
	int f=1;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-1;
	while(c>='0'&&c<='9')(t*=10)+=c-'0',c=getchar();
	t*=f;
}
bool compare(){
	for(RI i=1;i<=2*n;i++){
		if(ans[i]>zc[i])return true;
		else if(ans[i]<zc[i]){
			return false;
		}
	}
	return true;
}
bool check(){
	for(RI i=1;i<=n;i++){
		if(bb[i]!=bb[2*n-i+1])return false;
	}
	return true;
}
void dfs(int step,int l,int r){
	if(step>2*n){
		if(!check())return;
		if(compare()){
			for(RI i=1;i<=2*n;i++){
				ans[i]=zc[i];
			}
		}
		return;
	}
	int zcc=a[l];
	zc[step]=0;
	bb[step]=a[l];
	dfs(step+1,l+1,r);
	bb[step]=0;
	
	zcc=a[r];
	zc[step]=1;
	bb[step]=a[r];
	dfs(step+1,l,r-1);
	bb[step]=0;
	zc[step]=0;
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	Read(t);
	while(t--){
		Read(n);
		for(RI i=1;i<=n*2;i++){
			Read(a[i]);
		}
		if(n>20){
			for(RI i=1;i<=2*n;i++)printf("L");
			return 0;
		} 
		/*int flag=1,flagg=1;
		for(RI i=1;i<=n;i++){
			if(flagg==0&&a[i]!=a[2*n-i+1])flag=0;
			if(a[i]==a[2*n-i+1])flagg=0;
		}
		if(flag==0){
			puts("-1");
		}*/
		memset(ans,0x3f,sizeof(ans));
		memset(zc,0,sizeof(zc));
		dfs(1,1,n*2);
		if(ans[1]==0x3f3f3f3f)puts("-1");
		else{
			for(RI i=1;i<=n*2;i++){
				if(ans[i]==1)printf("R");
				else printf("L");
			}
			printf("\n");
		}
	}
	return 0;
}

