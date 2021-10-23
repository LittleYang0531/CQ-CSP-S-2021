#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){ll a=0;int b=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9'){a=(a<<1)+(a<<3)+(c^48);c=getchar();}return a*b;}
const int MAX_N = 100009;
int n,m1,m2;
pair<int,int> a[MAX_N],b[MAX_N];
int tmp[MAX_N]; // tmp[i] 表示第 i 个廊道上的飞机的离开时间 
inline int solve(int k,pair<int,int> *arr,int ed){
	if(k >= ed) return ed;
	memset(tmp,0,sizeof tmp);
	int res = 0;
	for(int i=1;i<=ed;++i){
		for(int j=1;j<=k;++j){
			if(tmp[j] < arr[i].first){
				++res;
				tmp[j] = arr[i].second;
				break;
			}
		}
	}
	return res;
}
int l,r,mid,ans;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n = read();
	m1 = read();
	m2 = read();
	for(int i=1;i<=m1;++i){
		a[i].first = read();
		a[i].second = read();
	}
	for(int i=1;i<=m2;++i){
		b[i].first = read();
		b[i].second = read();
	}
	sort(a+1,a+m1+1);
	sort(b+1,b+m2+1);
	if(n <= 32000){
		for(int i=1;i<=n;++i) ans = max(ans,solve(i,a,m1)+solve(n-i,b,m2));
		printf("%d\n",ans);
	}else{
		int l=1,r=m1,last,now=-0x3f3f3f3f;
		while(l<=r){
			int mid=(l+r)>>1;
			last = now;
			int res = solve(mid,a,m1);
			if(last < res) l = mid + 1,now = res;
			else r = mid-1,now=last;
		}
		ans = now + solve(n-r,b,m2);
		l=1,r=m2,now=-0x3f3f3f3f;
		while(l<=r){
			int mid=(l+r)>>1;
			last = now;
			int res = solve(mid,b,m2);
			if(last < res) l = mid + 1,now = res;
			else r = mid-1,now=last;
		}
		ans = max(ans,now + solve(n-r,a,m1));
		printf("%d\n",ans);
	}
//	cout << "time: " << clock() << "ms";
	return 0;
}
