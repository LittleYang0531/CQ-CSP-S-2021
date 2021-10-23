#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
char a[505];
char b[4]={'1','(',')','*'};
string s;
bool check(){
	int l,r;
	for(int i=1;i<=n;i++){
		if(b[i]=='*'){
			l=i;
			break;
		}
	}
	for(r=l;r<=n;r++){
		if(b[r+1]!='*') break;
	}
	if(r-l+1>=k) return false;
	if(b[l-1]=='('&&b[r+1]==')') return true;
}
void dfs(int x,int lt,int rt){
	if(x>n){
		if(lt!=rt) return;
		if(check()){
			ans=(ans+1)%1000000007;
		}
		return;
	}
	if(a[x]=='?'){
		for(int i=1;i<=3;i++){
			a[x]=b[i];
			if(a[x]=='('){
				dfs(x+1,lt+1,rt);
			}if(a[x]==')'){
				dfs(x+1,lt,rt+1);
			}if(a[x]=='*'){
				dfs(x+1,lt,rt);
			}
		}
	}else if(a[x]=='('){
		dfs(x+1,lt+1,rt);
	}else if(a[x]==')'){
		dfs(x+1,lt,rt+1);
	}else{
		dfs(x+1,lt,rt);
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	cin>>s;
	for(int i=0;i<=n-1;i++) a[i+1]=s[i];
	dfs(1,0,0);
	printf("%d\n",ans);
	return 0;
}

