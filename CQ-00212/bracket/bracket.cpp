#include<bits/stdc++.h>
using namespace std;
char s[505],c[505];
int n,k,ans;
bool ch(int l,int r){
	cerr<<l<<' '<<r<<endl;
	if(l==r)return 1;
	int a=0,b=0;
	for(int i=l;i<=r;i++){
		if(c[i]=='(')a++;
		if(c[i]==')')a--;
		if(c[i]=='*')b++;
		else b=0;
		if(b>k)return 0;
		if(a<0)return 0;
	}
	if(l==1&&r==n&&b!=0)return 0;
	if(a!=0)return 0;
	for(int i=1;i<=n;){
		int j=i;
		if(c[i]=='*'){
			while(c[j]=='*')j++;
			if(j-i>k)return 0;
		}
		else{
			int d=1;
			while(j<=n&&d!=0){
				j++;
				if(c[j]=='(')d++;
				if(c[j]==')')d--;
			}
			if(!ch(i+1,j-1))return 0;
			i=j;
		}
	}
	return 1;
}
void dfs(int i){
	if(i>n){
		cerr<<c+1<<' '<<ans<<endl;
		if(ch(1,n))ans++;
		return;
	}
	if(s[i]=='?'){
		c[i]='(';
		dfs(i+1);
		c[i]=')';
		dfs(i+1);
		c[i]='*';
		dfs(i+1);
	}
	else{
		c[i]=s[i];
		dfs(i+1);
	}
	
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d\n",&n,&k);
	scanf("%s",s+1);
	dfs(1);
	printf("%d",ans);
	return 0;
}
