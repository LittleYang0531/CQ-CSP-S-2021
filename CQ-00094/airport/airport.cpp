#include<bits/stdc++.h>
#define int long long
#define INF 1e18
#define cin lin
#define cout lout
using namespace std;
int N,M[2];
int dis[2][5010],del[5010];
pair<int,int> a[2][5010];
void deal(int op) {
	for (int i=1;i<=M[op];i++) {
		int x=a[op][i].first,y=a[op][i].second;
		a[op][i].first=lower_bound(dis[op]+1,dis[op]+M[op]+2,x)-dis[op];
		a[op][i].second=lower_bound(dis[op]+1,dis[op]+M[op]+2,y)-dis[op];
	}
	sort(a[op]+1,a[op]+M[op]+1);
	return;
}
int calc(int op,int num) {
	memset(del,0,sizeof(del));
	int now=0,res=0;
	for (int i=1;i<=M[op];i++) {
		int st=a[op][i].first,ed=a[op][i].second;
		now-=del[st];
		if (now>=num) continue;
		now++,res++;
		del[ed]++;
	}
	return res;
}
signed main() {
	ifstream cin("airport.in");
	ofstream cout("airport.out");
	cin>>N>>M[0]>>M[1];
	for (int i=1;i<=M[0];i++) {
		cin>>a[0][i].first>>a[0][i].second;
		dis[0][i]=a[0][i].first;
	}
	for (int i=1;i<=M[1];i++) {
		cin>>a[1][i].first>>a[1][i].second;
		dis[1][i]=a[1][i].first;
	}
	sort(dis[0]+1,dis[0]+M[0]+1);
	sort(dis[1]+1,dis[1]+M[1]+1);
	dis[0][M[0]+1]=dis[1][M[1]+1]=INF;
	deal(0);deal(1);
	int ans=0;
	for (int i=0;i<=N;i++) {
		int num1=i,num2=N-i;
		ans=max(ans,calc(0,num1)+calc(1,num2));
	}
	cout<<ans<<endl;
	return 0;
}
/*

*/
