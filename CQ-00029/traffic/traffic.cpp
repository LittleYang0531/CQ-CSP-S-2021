#include<bits/stdc++.h>
using namespace std;
long long n,m,t,a[501][501],b[501][501],mins=1e9,c[501],p[5501],cnt,k,s,j,ans;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]),p[++cnt]=a[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<m;j++)scanf("%d",&b[i][j]),p[++cnt]=b[i][j];
	while(t--){
		cin>>k;
		long long tmp=cnt;
		for(int i=1;i<=k;i++)cin>>c[i]>>s>>j,p[++tmp]=c[i];
		sort(p+1,p+tmp+1);
		for(int i=1;i<=m*n/2;i++)ans+=p[i];
		cout<<ans;
	}
	return 0;
}
