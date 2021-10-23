#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const unsigned int N=1e4;
int a[N],n;
bool flag;
string res;
bool check(int *x){
	for(register int i=1;i<=n;i++){
		if(x[i]!=x[2*n-i+1])
		return false;
	}
	return true;
}
string mx(string a,string b){
	if(a.length()!=b.length())
	return b;
	int len=a.length();
	for(register int i=0;i<len;i++){
		if(a[i]!=b[i])
		return a[i]<b[i]?a:b;
	}
	return a;
}
void dfs(int *x,int l,int r,int dep,string ans){
	//if(ans=="LRRLLRRRRL"){
	//	for(register int i=1;i<=n*2;i++)
	//	printf("%d ",x[i]);
	//	puts("");
	//}
	//printf("dep=%d l=%d r=%d\n",dep,l,r);
	//if(flag)
	//return;
	if(dep>=n*2+1){
		//cout<<ans<<endl;
		if(check(x)){
			flag=true;
			res=mx(res,ans);
			//cout<<ans<<endl;
			//for(register int i=1;i<=2*n;i++)
			//printf("%d ",x[i]);
			//puts("");
			//cout<<ans<<endl;
		}
		return;
	}
	x[dep]=a[r];
	dfs(x,l,r-1,dep+1,"R"+ans);
	x[dep]=a[l];
	dfs(x,l+1,r,dep+1,"L"+ans);
}
void solve(){
	flag=false;
	scanf("%d",&n);
	for(register int i=1;i<=n*2;i++)
	scanf("%d",&a[i]);
	int x[N];
	string tmp="";
	dfs(x,1,n*2,1,tmp);
	if(!flag)
	puts("-1");
	else
	cout<<res<<endl;
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	solve();
	return 0;
}
