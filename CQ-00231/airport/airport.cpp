#include<bits/stdc++.h>
using namespace std;
struct node{
	int ru,chu;
	bool operator<(node x)const{
		return ru<x.ru;
	}
};
node arr[100005];
int xuyao[100005],ans[100005][2];
int find(int l,int r,int now){
	while(l<=r){
		if(l==r)return l;
		int mid=(l+r)/2;
		if(arr[mid].ru>=arr[now].chu){
			return find(l,mid,now);
		}
		else{
			return find(mid+1,r,now);
		}
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1+m2;i++){
		int a,b;
		cin>>a>>b;
		arr[i].ru=a;
		arr[i].chu=b;
	}
	sort(arr+1,arr+m1+1);
	sort(arr+m1+1,arr+m1+m2+1);
	int cnt=0;
	for(int i=1;i<=m1;i++){
		if(xuyao[i]==0){
			xuyao[i]=++cnt;
			int x=find(i,m1,i);
			if(arr[x].ru<arr[i].chu)continue;
			while(xuyao[x]!=0&&x<m1)x++;
			if(xuyao[x]!=0)continue;
			xuyao[x]=xuyao[i];
			while(x!=find(x,m1,x)){
				x=find(x,m1,x);
				if(arr[x].ru<arr[i].chu)break;
				while(xuyao[x]!=0&&x<m1)x++;
				if(xuyao[x]!=0)break;
				xuyao[x]=xuyao[i];
			}
		}
	}
	cnt=0;
	for(int i=m1+1;i<=m1+m2;i++){
		if(xuyao[i]==0){
			xuyao[i]=++cnt;
			int x=find(i,m1+m2,i);
			if(arr[x].ru<arr[i].chu)continue;
			while(xuyao[x]!=0&&x<m1+m2)x++;
			if(xuyao[x]!=0)continue;
			xuyao[x]=xuyao[i];
			while(x!=find(x,m1+m2,x)&&x<=m1+m2){
				x=find(x,m1+m2,x);
				if(arr[x].ru<arr[i].chu)continue;
				while(xuyao[x]!=0&&x<=m1+m2)x++;
				if(xuyao[x]!=0)break;
				xuyao[x]=xuyao[i];
			}
		}
	}
	for(int i=1;i<=m1;i++){
		ans[xuyao[i]][0]++;
	}
	for(int i=m1+1;i<=m1+m2;i++){
		ans[xuyao[i]][1]++;
	}
	for(int i=1;i<=n;i++){
		ans[i][0]+=ans[i-1][0];
		ans[i][1]+=ans[i-1][1];
	}
	int daan=0;
	for(int i=0;i<=n;i++){
		daan=max(daan,ans[i][0]+ans[n-i][1]);
	}
	cout<<daan;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
