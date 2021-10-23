#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int t,n;
int a[N*2],c[N*2],flag1,flag3,flag4;
char b[N*2],d[2*N];
int pd(){
	for(int i=1;i<=2*n;i++){
		if(b[i]>d[i]){
			return 0;
		}
		else if(b[i]<d[i]){
			return 1;
		}
	}
	return 0;
}
void change(){
	for(int i=1;i<=2*n;i++){
		d[i]=b[i];
	}
}
void dfs(int x){
	if(x==2*n+1){
		int l=1,r=2*n,flag2=0;
		while(1){
			if(l>r)break;
			if(c[l]!=c[r]){
				flag2=1;
				break;
			}
			l++,r--;
		}
		if(!flag2){
			if(!flag4){
				for(int i=1;i<=2*n;i++){
					d[i]=b[i];
				}
				flag4=1;
			}
			else{
				if(pd()){
					change();
				}
			}
		}
		return;
	}
	for(int i=1;i<=2;i++){
		if(i==1){
			b[x]='L';
			c[2*n-x+1]=a[flag1];
			flag1++;
			x++;
			dfs(x);
			x--;
			flag1--;
		}
		else{
			b[x]='R';
			c[2*n-x+1]=a[flag3];
			flag3--;
			x++;
			dfs(x);
			x--;
			flag3++;
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		flag1=1;
		flag3=2*n;
		flag4=0;
		dfs(1);
		if(!flag4){
			printf("-1\n");
		}
		else{
			for(int i=1;i<=2*n;i++){
				printf("%c",d[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
