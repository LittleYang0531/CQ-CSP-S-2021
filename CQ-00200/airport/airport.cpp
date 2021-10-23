#include<bits/stdc++.h>
#define N 100005 
using namespace std;
int n,m1,m2;
int s1,s2,ans,ans1,ans2,tp;
struct node{
	int begin,end;
}a[N],b[N];
int vis[N];
bool cmp(node x,node y){
	return x.begin<y.begin;
}
int check(int x,node a[]){
	for(int i=1;i<=m1;i++){
		if(x==a[i].begin)
			return i;
	}
	return 0;
}
void run(int t,node a[]){
	for(int i=a[t].begin;i<=a[t].end;i++){
		vis[i]++;
	}
}
int chend(int x,node a[]){
	for(int i=1;i<=m1;i++){
		if(x==a[i].end)
			return i;
	}
	return 0;
}
void ruend(int t,node a[]){
	for(int i=a[t].begin;i<=a[t].end;i++){
		vis[i]--;
	}
}
bool want(int x,node a[],int p){
	for(int i=a[x].begin;i<=a[x].end;i++){
		if(vis[i]+1>p){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i].begin,&a[i].end);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].begin,&b[i].end);
	}
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	for(int i=1;i<=m1;i++)ans1=max(ans1,a[i].end);
	for(int i=1;i<=m2;i++)ans2=max(ans2,b[i].end);
	for(int i=0;i<=n;i++){
		s1=0;s2=0;
		memset(vis,0,sizeof(vis));
		if(i==0){
			goto f1;
		}
		for(int j=a[1].begin;j<=ans1;j++){
			int tp=check(j,a);
			if(tp==0||want(tp,a,i)==0)continue;
			run(tp,a);
			s1++;
			tp=chend(j,a);
			if(tp!=0){
				ruend(tp,a);
			}
		}
		f1:
		memset(vis,0,sizeof(vis));
		if(i==n)goto f2;
		for(int j=b[1].begin;j<=ans2;j++){
			int tp=check(j,b);
			if(tp==0||want(tp,b,n-i)==0)continue;
			run(tp,b);
			s2++;
			tp=chend(j,b);
			if(tp!=0){
				ruend(tp,b);
			}
		}
		f2:
		ans=max(s1+s2,ans);
	}
	cout<<ans;
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
