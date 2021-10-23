#include<bits/stdc++.h>
using namespace std;
int n,t,a[2005],flag,b[2005];
char ch[2005];
void dfs(int x,int l,int r){
	if(x==2*n+1){
		int flag2=0;
		for(int i=1;i<=n;i++){
			if(b[i]!=b[n*2-i+1]){
				flag2=1;break;
			}
		}
		if(flag2==0){
			flag=1;
			for(int i=1;i<=2*n;i++)printf("%c",ch[i]);
		}
		return;
	}
	if(flag==1)return;
	b[x]=a[l];ch[x]='L';dfs(x+1,l+1,r);
	if(flag==1)return;
	b[x]=a[r];ch[x]='R';dfs(x+1,l,r-1);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","r",stdout);
	cin>>t;
	while(t--){
		flag=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			if(a[i]!=a[n*2-i+1]){
				flag=1;break;
			}
		}
		if(flag==0){
			for(int i=1;i<=2*n;i++)printf("L");
		}else{
			flag=0;
			dfs(1,1,2*n);
			if(flag==0)printf("-1");
		}
		puts("");
	}
	return 0;
}
