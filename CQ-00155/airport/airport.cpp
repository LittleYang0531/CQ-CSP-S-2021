#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
struct Seg{int l,r,id;}a[100005],b[100005];
bool operator <(const Seg x,const Seg y){
	return x.l!=y.l?x.l<y.l:x.id<y.id;
}
int n,m1,m2,ans1[100005],ans2[100005],ans=0;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	set<Seg> s;
	for(int i=1;i<=m1;i++)scanf("%d%d",&a[i].l,&a[i].r),a[i].id=i,s.insert(a[i]);
	for(int i=1;i<=m2;i++)scanf("%d%d",&b[i].l,&b[i].r),b[i].id=i;
	for(int i=1;i<=n;i++){
		ans1[i]=ans1[i-1];
		int cur=0;
		while(1){
			auto it=s.lower_bound((Seg){cur,0,0});
			if(it==s.end())break;
			ans1[i]++,cur=it->r+1,s.erase(it);
		}
	}
	s.clear();
	for(int i=1;i<=m2;i++)s.insert(b[i]);
	for(int i=1;i<=n;i++){
		ans2[i]=ans2[i-1];
		int cur=0;
		while(1){
			auto it=s.lower_bound((Seg){cur,0,0});
			if(it==s.end())break;
			ans2[i]++,cur=it->r+1,s.erase(it);
		}
	}
	for(int i=0;i<=n;i++)ans=max(ans,ans1[i]+ans2[n-i]);
	cout<<ans;
	return 0;
}
