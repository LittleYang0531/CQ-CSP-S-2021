#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=505;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int n,k;
string s;
int f[maxn][maxn];
int g[maxn][maxn];
int w[maxn][maxn];

bool check(int x,char ch) {
	return s[x]==ch||s[x]=='?';
}

signed main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k>>s;
	s=" "+s;
	for(int i=1; i<=n-1; i++) {
		if(check(i,'(')&&check(i+1,')')) {
			f[i][i+1]=1;
			g[i][i+1]=1;
		}
	}
	for(int i=3; i<=n; i++) {
		for(int l=1; l+i-1<=n; l++) {
			int r=l+i-1;
			if(check(l,'(')&&check(r,')')) {
				f[l][r]=(f[l+1][r-1]+w[l+1][r-1])%mod;
				bool flag=true;
				for(int j=l+1; j<=r-1; j++) {
					if(!check(j,'*')) {
						flag=false;
					}
				}
				if(flag==true&&(r-l-1)<=k) {
					f[l][r]=(f[l][r]+1)%mod;
				}
				for(int j=l+1; j<=min(r-1,l+k); j++) {
					if(!check(j,'*')) {
						break;
					}
					f[l][r]=(f[l][r]+f[j+1][r-1])%mod;
					f[l][r]=(f[l][r]+w[j+1][r-1])%mod;
				}
				for(int j=r-1; j>=max(l+1,r-k); j--) {
					if(!check(j,'*')) {
						break;
					}
					f[l][r]=(f[l][r]+f[l+1][j-1])%mod;
					f[l][r]=(f[l][r]+w[l+1][j-1])%mod;
				}
//				for(int j=l+1; j<=r-2; j++) {
//					f[l][r]=(f[l][r]+1ll*f[l+1][j]*g[j+1][r-1])%mod;
//				}
//				for(int j=l+1; j<=r-2; j++) {
//					w[l][r]=(w[l][r]+1ll*f[l][j]*f[r][])
//					for(int k=j+2; k<=r-1; k++) {
//						w[l][r]=(w[l][r]+1ll*f[l][j]*g[j+1][k-1]%mod*f[k][r])%mod;
//					}
//				}
				for(int j=l+1;j<=r-2;j++) {
					w[l][r]=(w[l][r]+1ll*f[l][j]*g[j+1][r])%mod;
				}
			}
			g[l][r]=(w[l][r]+f[l][r])%mod;
			if(check(l,'*')&&check(r,')')) {
				for(int j=l;j<=min(r-2,l+k-1);j++) {
					if(!check(j,'*')) {
						break;
					}
					g[l][r]=(g[l][r]+f[j+1][r])%mod;
					g[l][r]=(g[l][r]+w[j+1][r])%mod;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++) {
//		for(int j=i+1;j<=n;j++) {
//			cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
//		}
//	}
//	cout<<"___________\n";
//	for(int i=1;i<=n;i++) {
//		for(int j=i+1;j<=n;j++) {
//			cout<<i<<" "<<j<<" "<<w[i][j]<<"\n";
//		}
//	}
//	cout<<"___________\n";
//	for(int i=1;i<=n;i++) {
//		for(int j=i+1;j<=n;j++) {
//			cout<<i<<" "<<j<<" "<<g[i][j]<<"\n";
//		}
//	}
	cout<<(f[1][n]+w[1][n])%mod;
}
