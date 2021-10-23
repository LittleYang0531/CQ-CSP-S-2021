#include<bits/stdc++.h>
using namespace std;
int n,K;
char s[505];
int f[505][505][2];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>K;
	cin>>s+1;
	for(int i=1;i<=n;++i){
		if(s[i]=='*'||s[i]=='?') f[i][i][1]=1;
	}
	for(int i=2;i<=n;++i){
		if(s[i-1]=='(' && s[i]=='?') f[i-1][i][0]=1;
		if(s[i-1]=='?' && s[i]==')') f[i-1][i][0]=1;
		if(s[i-1]=='?' && s[i]=='?') f[i-1][i][0]=f[i-1][i][1]=1;
		if(s[i-1]=='*' && s[i]=='?') f[i-1][i][1]=1;
		if(s[i-1]=='?' && s[i]=='*') f[i-1][i][1]=1;
	}
	for(int l=3;l<=n;++l){
		for(int i=1;i+l-1<=n;++i){
			int j=i+l-1;
			if(s[i]=='('){
				if(s[j]==')' || s[j]=='?')
					f[i][j][0]=f[i+1][j-1][0]+f[i+1][j-1][1];
			} else if(s[i]=='?'){
				if(s[j]==')')
					f[i][j][0]=f[i+1][j-1][0]+f[i+1][j-1][1];
				else if(s[j]=='?'){
					f[i][j][0]+=f[i+1][j-1][0]*2+f[i+1][j-1][1];
					f[i][j][1]+=f[i+1][j-1][1];
				}
				else if(s[j]=='*'){
					f[i][j][1]+=f[i+1][j-1][1];
					f[i][j][0]+=f[i+1][j-1][0];
				}
			} else if(s[i]=='*'){
				if(s[j]=='*'||s[j]=='?'){
					f[i][j][1]+=f[i+1][j-1][1];
					f[i][j][0]+=f[i+1][j-1][0];
				}
			}
			for(int k=i;k<j;++k){
				f[i][j][1]+=(f[i][k][1]&&f[k+1][j][1]);
				f[i][j][0]+=(f[i][k][1]&&f[k+1][j][0])+
							(f[i][k][0]&&f[k+1][j][1])+
							(f[i][k][0]&&f[k+1][j][0]);
			}
			if(j-i+1>K) f[i][j][1]=0;
//			cout<<"f["<<i<<","<<j<<",0]="<<f[i][j][0]<<"\n";
//			cout<<"f["<<i<<","<<j<<",1]="<<f[i][j][1]<<"\n";
		}
	}
	cout<<f[1][n][0]+f[1][n][1];
	return 0;
}
