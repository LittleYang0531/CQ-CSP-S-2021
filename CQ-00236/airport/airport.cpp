#include<bits/stdc++.h>
#define N ((int)1e5+2)
using namespace std;
int n,m1,m2;
struct Node{int st,ed;}node1[N],node2[N];
inline bool cmp(Node a,Node b){return a.st<b.st;}
inline void freo(){freopen("airport.in","r",stdin),freopen("airport.out","w",stdout);}
signed main(){
	freo();
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;++i) scanf("%d%d",&node1[i].st,&node1[i].ed);
	for(int i=1;i<=m2;++i) scanf("%d%d",&node2[i].st,&node2[i].ed);
	sort(node1+1,node1+m1+1,cmp),sort(node2+1,node2+m2+1,cmp);
	int ans=0,cnt1,cnt2;
	for(int i=0;i<=n;++i){
		priority_queue<int,vector<int>,greater<int> > q;
		cnt1=cnt2=0;
		for(int j=1;j<=m1;++j){
			while(!q.empty()&&q.top()<node1[j].st) q.pop();
			if(q.size()<i) ++cnt1,q.push(node1[j].ed);
		}
		while(!q.empty()) q.pop();
		for(int j=1;j<=m2;++j){
			while(!q.empty()&&q.top()<node2[j].st) q.pop();
			if(q.size()<n-i) ++cnt2,q.push(node2[j].ed);
		}
		ans=max(ans,cnt1+cnt2);
		//cout<<cnt1<<" "<<cnt2<<'\n';
	}
	cout<<ans<<'\n';
return 0;
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
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/ 
