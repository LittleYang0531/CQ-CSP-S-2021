#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,box[100005],aox[100005],ans;
struct star{
	int st,ed;bool vis;
	friend bool operator <(star a,star b){
		return a.st<b.st;
	}
}plane[100005];
int find(int id,int cnt,int limit){
	cnt++,plane[id].vis=1;int pos=id;
	while(pos<=limit&&plane[pos].vis)pos=upper_bound(plane+pos+1,plane+limit+1,(star){plane[id].ed,0})-plane;
	if(pos>limit)return cnt;else return find(pos,cnt,limit);
}
int main(){
	freopen("airport.in","r",stdin);freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&plane[i].st,&plane[i].ed);
	}sort(plane+1,plane+m1+1);
	for(int i=1;i<=n;i++){
		box[i]+=box[i-1];if(!plane[i].vis)box[i]+=find(i,0,m1);
	}
	for(int i=m1+1;i<=m1+m2;i++){
		scanf("%d%d",&plane[i].st,&plane[i].ed);
	}sort(plane+m1+1,plane+m1+m2+1);
	for(int i=1;i<=n;i++){
		aox[n-i]+=aox[n-i+1];if(!plane[i+m1].vis)aox[n-i]+=find(i+m1,0,m1+m2);
	}//for(int i=0;i<=n;i++)printf("%d %d\n",box[i],aox[i]);
	for(int i=0;i<=n;i++)ans=max(ans,box[i]+aox[i]);printf("%d",ans);return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
