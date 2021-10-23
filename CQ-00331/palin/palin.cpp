#include<bits/stdc++.h>
using namespace std;
int a[100005];
int choice[100005];
char choose[100005];
int n,T;
bool stop=0;
int l,r;
void dfs(int x){
	if(stop)return;
	if(x==2*n+1){
		printf("%s",choose+1);
		stop=1;
	}
	if(x>n){
		if(a[l]==choice[2*n-x+1]){
			choose[x]='L';
			++l;
			dfs(x+1);
			--l;
		}
		else if(a[r]==choice[2*n-x+1]){
			choose[x]='R';
			--r;
			dfs(x+1);
			++r;
		}
	}
	else{
		choice[x]=a[l];
		choose[x]='L';
		++l;
		dfs(x+1);
		choice[x]=a[r];
		choose[x]='R';
		--l,--r;
		dfs(x+1);
		++r;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		bool flag=1;
		for(int i=1;i<=n*2;++i)scanf("%d",&a[i]),flag&=(i<=n||a[i]==a[2*n-i]);
		if(flag){
			for(int i=1;i<=n;++i)printf("L");
			for(int i=1;i<=n;++i)printf("R");
		}
		else{
			stop=0,l=1,r=2*n;
			dfs(1);
			if(stop==0)printf("-1");
		}
		puts("");
	}
	return 0;
}
