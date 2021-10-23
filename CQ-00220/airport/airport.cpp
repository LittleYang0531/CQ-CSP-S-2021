#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct aircraft{
	int x,y;
	bool operator<(const aircraft &temp)const{
		temp.y<y;
	}
}a[N],b[N],ff;
bool cmp(aircraft a,aircraft b){
	return a.x<b.x;
}
int p=0;
int k,n,m;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&b[i].x,&b[i].y);
	}
	sort(b+1,b+1+n,cmp);
	int ans=-1;
	for(int s=0;s<=k;s++){
		int sum=0;
		queue<aircraft>u;
		queue<aircraft>q;
		for(int i=1;i<=n;i++){
			for(int p=u.size();p--;){
				ff=u.front(),u.pop();
				if(ff.y>a[i].x){
					u.push(ff);
				}
			}
			if(u.size()<s){
				u.push(a[i]);
				sum++;
			}
		}
		for(int i=1;i<=m;i++){
			for(int p=q.size();p--;){
				ff=q.front(),q.pop();
				if(ff.y>b[i].x){
					q.push(ff);
				}
			}
			if(q.size()<k-s){
				q.push(b[i]);
				sum++;
			}
		}
		ans=max(ans,sum);
	}printf("%d\n",ans);
	return 0;
}
