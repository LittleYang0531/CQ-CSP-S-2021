#include<bits/stdc++.h>
#define van long long
using namespace std;

//bool ppppp;time_t st=clock();
ifstream ywhin("traffic.in");
ofstream ywhout("traffic.out");
const van MaxN=510;
van dp[MaxN][MaxN][2];
van n,m,t;
van w1[MaxN][MaxN],w2[MaxN][MaxN];
//bool pppppp;

//void Output_Runner_Information() {
//	cout<<"Memory Usage: "<<(&pppppp-&ppppp)/1024.0/1024.0<<"MB"<<endl;
//	cout<<"Time Usage: "<<(clock()-st)/1000.0<<"s"<<endl;
//}

int main() {
	ywhin>>n>>m>>t;
	for (int i=1;i<n;i++) {
		for (int j=1;j<=m;j++) ywhin>>w1[i][j];
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<m;j++) ywhin>>w2[i][j];
	}
	for (int tt=1;tt<=t;tt++) {
		van num;ywhin>>num;
		for (int i=1;i<=num;i++) {
			van x,p,col;
			ywhin>>x>>p>>col;
			if (p<=m) dp[1][p][1-col]+=x;
			else if (p<=m+n) dp[p-n][m][1-col]+=x;
			else if (p<=2*m+n) dp[n][2*m-p+n+1][1-col]+=x;
			else dp[2*n+2*m-p+1][1][1-col]+=x;
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				dp[i][j][0]+=min(dp[i-1][j][0],dp[i-1][j][1]+w1[i-1][j]);
				dp[i][j][1]+=min(dp[i-1][j][1],dp[i-1][j][0]+w1[i-1][j]);
				dp[i][j][0]+=min(dp[i][j-1][0],dp[i][j-1][1]+w2[i][j-1]);
				dp[i][j][1]+=min(dp[i][j-1][1],dp[i][j-1][0]+w2[i][j-1]);
			}
		}
//		for (int i=1;i<=n;i++) {
//			for (int j=1;j<=m;j++) cout<<dp[i][j][0]<<" ";
//			cout<<endl;
//		}
//		for (int i=1;i<=n;i++) {
//			for (int j=1;j<=m;j++) cout<<dp[i][j][1]<<" ";
//			cout<<endl;
//		}
		ywhout<<min(dp[n][m][0],dp[n][m][1])<<endl;
	}
//	Output_Runner_Information();
	return 0;
}

