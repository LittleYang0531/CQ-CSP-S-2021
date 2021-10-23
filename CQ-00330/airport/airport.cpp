#include<bits/stdc++.h>
#define M 100003
using namespace std;
struct T{
	int s,e,id;
}T1[M],T2[M];
int n,m1,m2,t1[M],t2[M],bg1[100002],sta1[100002],bg2[100002],sta2[100002];
bool cmp(T x,T y){
	return x.s<y.s;
}
int BS1(int x){
	int l=1,r=t1[0];
	while(l<=r){
		int mid=(l+r)/2;
		if(t1[mid]>=x)r=mid-1;
		else l=mid+1;
	}
	return l;
}
int BS2(int x){
	int l=1,r=t2[0];
	while(l<=r){
		int mid=(l+r)/2;
		if(t2[mid]>=x)r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		T1[i].s=u,T1[i].e=v;
		t1[++t1[0]]=u,t1[++t1[0]]=v;
	}
	for(int i=1;i<=m2;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		T2[i].s=u,T2[i].e=v;
		t2[++t2[0]]=u,t2[++t2[0]]=v;
	}
	t1[0]=t2[0]=0;
	sort(t1+1,t1+1+m1*2);
	sort(t2+1,t2+1+m2*2);
//	cout<<endl;
	for(int i=1;i<=m1*2;i++){
		if(t1[i]!=t1[t1[0]]||t1[0]==0)t1[++t1[0]]=t1[i];
	}
	for(int i=1;i<=m2*2;i++){
		if(t2[i]!=t2[t1[0]]||t2[0]==0)t2[++t2[0]]=t2[i];
	}
//	for(int i=1;i<=t1[0];i++){
//		cout<<t1[i]<<' ';
//	}
	for(int i=1;i<=m1;i++){
		T1[i].s=BS1(T1[i].s);
		T1[i].e=BS1(T1[i].e);
	}
	for(int i=1;i<=m2;i++){
		T2[i].s=BS2(T2[i].s);
		T2[i].e=BS2(T2[i].e);
	}
	sort(T1+1,T1+1+m1,cmp);
	sort(T2+1,T2+1+m2,cmp);
//	for(int i=1;i<=m1;i++){
//		cout<<T1[i].s<<' '<<T1[i].e<<endl;
//	}
//	for(int i=1;i<=m2;i++){
//		cout<<T2[i].s<<' '<<T2[i].e<<endl;
//	}
	for(int i=1;i<=m1;i++){
		int k=1,f=1;
		while(sta1[k]){
			if(sta1[k]<=T1[i].s){
				sta1[k]=T1[i].e,f=0,bg1[k]++;
				break;
			}
			k++;
		}
		if(f)sta1[k]=T1[i].e,bg1[k]++;
	}
	for(int i=1;i<=m2;i++){
		int k=1,f=1;
		while(sta2[k]){
			if(sta2[k]<=T2[i].s){
				sta2[k]=T2[i].e,f=0,bg2[k]++;
				break;
			}
			k++;
		}
		if(f)sta2[k]=T2[i].e,bg2[k]++;
	}
	for(int i=1;i<=n;i++){
		bg1[i]=bg1[i-1]+bg1[i];
	}
	for(int i=1;i<=n;i++){
		bg2[i]=bg2[i-1]+bg2[i];
	}
	int ans=0;
	for(int k=0;k<=n;k++){
		ans=max(ans,bg1[k]+bg2[n-k]);
	}
	cout<<ans;
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

