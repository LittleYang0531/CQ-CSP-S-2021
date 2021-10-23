#include<bits/stdc++.h>
#define INF 1000000007
using namespace std;
int n,k;
char a[505],c[505],d[505];
int ans;
bool hf(char b[]){
	int len=strlen(b);
	if(b[0]=='('&&b[len-1]==')'&&len-2<=k)return true;
	int i;
	for(i=0;i<len;i++){
		if(b[i]==')')break;
	}
	int j;
	for(j=i;j<len;j++){
		if(b[j]=='(')break;
	}
	if(j-i+1<=k){
		bool flag=0;
		for(int k=i;k<=j;k++)
			if(b[k]!='*')flag=1;
		if(!flag){
			for(int k=1;k<=i;k++)c[k]=b[k];
			for(int k=j;k<len;k++)d[k]=b[k];
			if(hf(c)&&hf(d))return 1;
		}
	}
	if(b[0]=='('&&b[len-1]==')'){
		int k;
		for(k=1;k<len-1;k++){
			if(b[k]!='*')break;
		}
		int l;
		for(l=len-2;l>=1;l--){
			if(b[l]!='*')break;
		}
		for(int x=k;x<=l;x++)c[x]=b[x];
		if(hf(c))return true;
	}
	return false;
}
void dfs(int step){
	if(step==n){
		if(hf(a))ans++;
		return;
	}
	if(a[step]=='?'){
		a[step]='(';
		dfs(step+1);
		a[step]=')';
		dfs(step+1);
		a[step]='*';
		dfs(step+1);
	}
	else dfs(step+1);
	return;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	cin>>a;
	if(n>0)
		dfs(0);
	printf("%d",ans);
	return 0;
}
