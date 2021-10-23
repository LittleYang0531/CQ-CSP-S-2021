#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int T,n,arr[1000005],brr[1000005];
char ans[1000005];
bool fl=0;
bool ck(){
	for(int i=1,j=n+n;j>i;j--,i++){
		if(brr[i]!=brr[j])return 0;
	}
	return 1;
}
void dfs(int l,int r,int sum){
	if(fl)return;
	if(sum==2*n){
		if(ck()){
			for(int i=1;i<=sum;i++)cout<<ans[i];
			fl=1;
		}
		return;
	}
	if(l>r)return;
	sum++;
	brr[sum]=arr[l];
	ans[sum]='L';
	dfs(l+1,r,sum);
	brr[sum]=0;
	ans[sum]='\0';
	brr[sum]=arr[r];
	ans[sum]='R';
	dfs(l,r-1,sum);
	brr[sum]=0;
	ans[sum]='\0';
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
	fl=0;
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++){
		scanf("%d",&arr[i]);
	}
	dfs(1,2*n,0);
	if(!fl)printf("-1");
	puts("");
}
	return 0;
}
