#include<bits/stdc++.h>
#define van long long
using namespace std;

//bool ppppp;time_t st=clock();
ifstream ywhin("bracket.in");
ofstream ywhout("bracket.out");
const van MaxN=500+10;
const van mod=1e9+7;
const van K=500;
van n,k;
char b[MaxN];
van dp[2][MaxN*2][MaxN];
van l,r;
//bool pppppp;

//void Output_Runner_Information() {
//	cout<<"Memory Usage: "<<(&pppppp-&ppppp)/1024.0/1024.0<<"MB"<<endl;
//	cout<<"Time Usage: "<<(clock()-st)/1000.0<<"s"<<endl;
//}

int main() {
	ywhin>>n>>k;
	for (int i=1;i<=n;i++) ywhin>>b[i];
	if (b[1]=='('||b[1]=='?') dp[1][1][0]=1,l++;
	for (int i=2;i<=n;i++) {
		memset(dp[i%2],0,sizeof dp[i%2]);
		if (b[i]=='*') 
			for (int j=0;j<=l;j++) 
				for (int kk=1;kk<=k;kk++) 
					dp[i%2][j][kk]=dp[1-i%2][j][kk-1];
		if (b[i]=='(') {
			l++;for (int j=1;j<=l;j++) 
				for (int kk=0;kk<=k;kk++) 
					dp[i%2][j][0]+=dp[1-i%2][j-1][kk],
					dp[i%2][j][0]%=mod;
		}
		if (b[i]==')') {
			for (int j=0;j<=l-1;j++) 
				for (int kk=0;kk<=k;kk++) 
					dp[i%2][j][0]+=dp[1-i%2][j+1][kk],
					dp[i%2][j][0]%=mod;
		}
		if (b[i]=='?') {
			l++;
			for (int j=0;j<=l;j++) 
				for (int kk=1;kk<=k;kk++) 
					dp[i%2][j][kk]+=dp[1-i%2][j][kk-1],
					dp[i%2][j][kk]%=mod;
			for (int j=1;j<=l;j++) 
				for (int kk=0;kk<=k;kk++) 
					dp[i%2][j][0]+=dp[1-i%2][j-1][kk],
					dp[i%2][j][0]%=mod;
			for (int j=0;j<=l-1;j++) 
				for (int kk=0;kk<=k;kk++) 
					dp[i%2][j][0]+=dp[1-i%2][j+1][kk],
					dp[i%2][j][0]%=mod;
		}
//		cout<<i<<endl;
//		for (int j=0;j<=l;j++) {
//			cout<<j<<" ";
//			for (int kk=0;kk<=k;kk++) {
//				cout<<dp[i][j][kk]<<" ";
//			}cout<<endl;
//		}cout<<endl;
	}
	ywhout<<dp[n%2][0][0]<<endl;
//	Output_Runner_Information();
	return 0;
}
