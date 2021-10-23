#include<bits/stdc++.h>
using namespace std;
long long f[505][505],a[505],b[505],c[505],d[505],n,k;string s;
const int p=1000000007;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>s;
	a[0]=s[0]=='?';b[0]=s[0]=='*';c[0]=s[0]=='(';d[0]=s[0]==')';
	for(int i=1;i<n;++i){
		a[i]=a[i-1]+(s[i]=='?');
		b[i]=b[i-1]+(s[i]=='*');
		c[i]=c[i-1]+(s[i]=='(');
		d[i]=d[i-1]+(s[i]==')');
	}
	if(a[n-1]==0)return cout<<0,0;
	for(int l=2;l<=n;++l){
		for(int i=0,j=l+i-1;i<n;++i){
			if(a[j]-a[i-1]==0){
				if(d[j]-d[i-1]==c[j]-c[i-1]&&s[i]=='('&&s[j]==')')f[i][j]=1;
				else f[i][j]=0;
			}
			if(s[i]!='('&&s[i]!='?'||s[j]!=')'&&s[j]!='?')continue;
			else{
				for(int k=i;k<j;++k)f[i][j]=(f[i][j]+f[i][k]*f[k+1][j])%p;
				
			}
		}
	}
	cout<<f[0][n-1];
	return 0;
}
