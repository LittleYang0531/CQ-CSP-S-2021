#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m1, m2, tot, to, dp[2][100005], vis[0][100005], ans, ovo;
struct qwq{
	int a, b, c;
	bool operator <(const qwq &A) const{
		if(A.a == a) return A.b > b;
		return A.a > a;
	}
}pla[2][100005];
signed main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i = 1; i <= m1; ++i)
		scanf("%d%d",&pla[0][i].a,&pla[0][i].b);
		
	for(int i = 1; i <= m2; ++i)
		scanf("%d%d",&pla[1][i].a,&pla[1][i].b);
		
	sort(pla[0]+1,pla[0]+1+m1);
	sort(pla[1]+1,pla[1]+1+m2);
//	
//	for(int i = 1; i <= m1; ++i)
//		cout<<pla[0][i].a<<" "<<pla[0][i].b<<"\n";
//	cout<<"\n";
//	
//	for(int i = 1; i <= m2; ++i)
//		cout<<pla[1][i].a<<" "<<pla[1][i].b<<"\n";
//	cout<<"\n";
//	
	for(int i = 1; i <= m1; ++i){
		int QAQ = 0;
		for(int j = i+1; j <= m1; ++j)
			if(!vis[0][j] && pla[0][i].b <= pla[0][j].a){
				QAQ=j;
				break;
			}
		if(QAQ == 0){
			if(vis[0][i] == 0){
				dp[0][++to]=1;
				pla[0][i].c=to;
//				cout<<i<<" "<<tot<<"\n";
			}
			continue;
		}
		if(!pla[0][i].c){
			pla[0][i].c=++to;
			dp[0][pla[0][i].c]=1;
		}
		++dp[0][pla[0][i].c];
		pla[0][QAQ].c = pla[0][i].c;
		vis[0][QAQ]=1;
//		cout<<i<<" "<<QAQ<<" "<<tot<<"\n";
	}/*cout<<"\n";*/
	for(int i = 1; i <= m2; ++i){
		int QAQ = 0;
		for(int j = i+1; j <= m2; ++j)
			if(!vis[1][j] && pla[1][i].b <= pla[1][j].a){
				QAQ=j;
				break;
			}
		if(QAQ == 0){
			if(vis[1][i] == 0){
				dp[1][++tot]=1;
				pla[1][i].c=tot;
//				cout<<i<<" "<<tot<<"\n";
			}
			continue;
		}
		if(!pla[1][i].c){
			pla[1][i].c=++tot;
			dp[1][pla[1][i].c]=1;
		}
		++dp[1][pla[1][i].c];
		pla[1][QAQ].c = pla[1][i].c;
		vis[1][QAQ]=1;
//		cout<<i<<" "<<QAQ<<"\n";
	}/*cout<<"\n";*/
//	sort(dp[0]+1,dp[0]+1+to,comp);
//	sort(dp[1]+1,dp[1]+1+tot,comp);
//	for(int i = 1; i <= to; ++i)
//		cout<<dp[0][i]<<"\n";
	for(int i = 1; i <= n; ++i)
		dp[0][i]+=dp[0][i-1], dp[1][i]+=dp[1][i-1]/*,
		cout<<dp[0][i]<<" "<<dp[1][i]<<"\n"*/;
	for(int i = 0; i <= n; ++i)
		ans=max(ans,max(dp[0][i]+dp[1][n-i],dp[1][i]+dp[0][n-i]));
	cout<<ans<<"\n";
	return 0;
}
