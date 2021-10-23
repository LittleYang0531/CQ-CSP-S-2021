#include<bits/stdc++.h>
using namespace std;
map<int,int> p1,p2;
int n,m1,m2,ans,sum;
struct df{
	int l,r;
	//bool operator <()(const df &x, const df &y) const{return x.r>y.r; }
}an[100005],aw[100005];
bool cmp(df x,df y){
	return x.l<y.l;
}
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","r",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	if(n>=m1+m2){
		printf("%d",m1+m2);
		return 0;
	}
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&an[i].l,&an[i].r);
		p1[an[i].r]=i;
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&aw[i].l,&aw[i].r);
		p2[aw[i].r]=i;
	}
	sort(an+1,an+m1+1,cmp);sort(aw+1,aw+m2+1,cmp);
	int l=0,r,sj=-99;
	while(l<=r){
		int z=0;sum=0;
		for(int i=1;i<=m1;i++){
			while(!q.empty()&&q.top()<an[i].l){
				q.pop();sum++;
			}
			if(l>=sj){
				q.push(an[i].r);
				sj=an[i].l;
			}else{
				z++;
			}
		}
		while(!q.empty()){
			q.pop();sum++;
		}
		for(int i=1;i<=m2;i++){
			while(!q.empty()&&q.top()<an[i].l){
				q.pop();
			}
			if(l>=sj&&z<n-l){
				q.push(an[i].r);
				sum++;
			}
		}
		ans=max(sum,ans);
		l++;
	}
	cout<<ans;
	return 0;
}
