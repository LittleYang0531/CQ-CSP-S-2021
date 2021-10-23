#include<bits/stdc++.h>
using namespace std;
const int maxn=106;
long long n,k,dp[maxn][maxn][maxn][maxn],ans,mod=1e9+7;
string s;
char ch[maxn];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	memset(dp,0,sizeof(dp));
	scanf("%lld%lld",&n,&k);
	cin>>s;
	dp[0][0][0][0]=1;
	for(int i=1;i<=n;i++)ch[i]=s[i-1];
//	printf("papapa%c\n",ch[1]);
	for(int i=1;i<=n;i++){
//		printf("i=%d\n",i);
		for(int j=0;j<=n;j++){
//			printf("	j=%d\n",j);
			for(int p=0;p<=j;p++){
//				printf("		p=%d\n",p);
				if(ch[i]=='('&&j){
					for(int q=0;q<=k;q++){
						dp[i][j][p][0]+=dp[i-1][j-1][p][q];
//						printf("			q=%d\n				%d\n",0,dp[i][j][p][0]);
					}
				}
				else if(ch[i]==')'&&p){
					for(int q=0;q<=k;q++){
						dp[i][j][p][0]+=dp[i-1][j][p-1][q];
//						printf("			q=%d\n				%d\n",0,dp[i][j][p][0]);
					}
				}
				else if(ch[i]=='*'){
					for(int q=1;q<=k;q++){
						dp[i][j][p][q]+=dp[i-1][j][p][q-1];
//						printf("			q=%d\n				%d %d %d %d %d %d\n",q,,,,,,);
//						cout<<"			q="<<q<<"\n				"<<' '<<dp[i][j][p][q]<<' '<<i-1<<' '<<j<<' '<<p<<' '<<q-1<<'\n';
					}
				}
				else if(ch[i]=='?'){
					for(int q=0;q<=k;q++){
						if(j)dp[i][j][p][0]+=dp[i-1][j-1][p][q];
						if(p)dp[i][j][p][0]+=dp[i-1][j][p-1][q];
						if(q)dp[i][j][p][q]+=dp[i-1][j][p][q-1];
//						printf("haha			q=%d\n				%d\n",q,dp[i][j][p][q]);
					}
				}
				if(i==n&&j==p){
					ans+=dp[i][j][p][0];
				}
//				printf("\n");
			}
//			printf("\n");
		}
//		printf("\n");
	}
//	cout<<dp[7][0][0][0]<<' '<<dp[7][1][1][0]<<' '<<dp[7][2][2][0]<<' '<<dp[7][3][3][0]<<' '<<dp[7][4][4][0]<<' '<<dp[7][5][5][0]<<' '<<dp[7][6][6][0]<<' '<<dp[7][7][7][0]<<'\n';
	printf("%lld",ans-1);
	return 0;
}
