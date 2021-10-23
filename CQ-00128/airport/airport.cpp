#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,s1[100005],s2[100005],fl1,fl2,ans;
struct node{int x,y;}a[100005],b[100005];
bool cmp(node a,node b){return a.x<b.x;}
priority_queue<int>p;
int f1(int x){
	int sum=x;
	while(!p.empty())p.pop();
	for(int i=1;i<=x;i++)p.push(-a[i].y);
	for(int i=x+1;i<=m1;i++)if(!p.empty()&&-p.top()<=a[i].x)p.pop(),p.push(-a[i].y),sum++;
	return sum;
}
int f2(int x){
	int sum=x;
	while(!p.empty())p.pop();
	for(int i=1;i<=x;i++)p.push(-b[i].y);
	for(int i=x+1;i<=m2;i++)if(!p.empty()&&-p.top()<=b[i].x)p.pop(),p.push(-b[i].y),sum++;
	return sum;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=m2;i++)scanf("%d%d",&b[i].x,&b[i].y);
	if(n>=m1+m2){printf("%d",m1+m2);return 0;}
	sort(a+1,a+m1+1,cmp),sort(b+1,b+m2+1,cmp);
	for(int i=max(0,n-m2);!fl1&&i<=min(n,m1);i++){
		s1[i]=f1(i);
		if(s1[i]==m1){
			for(int j=i+1;j<=min(n,m1);j++)s1[i]=m1;
			fl1=1;
		}
	}
	for(int i=min(n,m1);!fl2&&i>=max(0,n-m2);i--){
		s2[i]=f2(i);
		if(s2[i]==m2){
			for(int j=i-1;j>=max(0,n-m2);j--)s2[i]=m2;
			fl2=1;
		}
	}
	for(int x=max(0,n-m2);x<=min(n,m1);x++)ans=max(ans,s1[x]+s2[n-x]);
	printf("%d",ans);
	return 0;
}
