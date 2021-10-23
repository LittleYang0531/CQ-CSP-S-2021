#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005],cnt=0;
int t;
char c[500005];
bool flag=0;
void dfs(int x,int l1,int r1){//正在执行第x次操作 
	if(x>2*n){
		flag=1;
		return;
	}
	for(int i=1;i<=2;i++){
		if(i==1){
			if(x>=n+1){
				if(a[l1]!=b[2*n+1-x]) continue;
			}
			b[++cnt]=a[l1];
			c[cnt]='L'; 
			dfs(x+1,l1+1,r1);
			if(flag) return;
			cnt--;
		}else{
			if(x>=n+1){
				if(a[r1]!=b[2*n+1-x]) continue;
			}
			b[++cnt]=a[r1];
			c[cnt]='R'; 
			dfs(x+1,l1,r1-1);
			if(flag) return;
			cnt--;
		}
	}	
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		cnt=0;flag=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
		}dfs(1,1,2*n);
		if(flag)
		for(int i=1;i<=2*n;i++) cout<<c[i];
		else cout<<-1;
		cout<<endl;
	}
	return 0;
}

