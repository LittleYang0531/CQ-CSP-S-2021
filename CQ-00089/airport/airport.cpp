#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,ans=INT_MIN;
struct airport{
	int a,b,c;
	bool operator < (const airport &x) const{return a<x.a;}
}a[100005],b[100005];
int wlie[100005],cnt,w[100005],num;
int work(int i,int j){
	int sum=0;
	int sa=i,sb=j;
	for(int k=1;k<=m1;k++){
		if(sa>0){
			sa--;
			sum++;
			wlie[++cnt]=a[k].b;
		}
		for(int l=1;l<=cnt;l++){
			if(wlie[l]<=a[k].a){
				sa++;
				break;
			}
		}
	}
	for(int k=1;k<=m2;k++){
		if(sb>0){
			sb--;
			sum++;
			w[++num]=b[k].b;
		}
		for(int l=1;l<=num;l++){
			if(w[l]<b[k].b){
				sb++;
				break;
			}
		}
	}
	return sum;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d %d",&a[i].a,&a[i].b);
		a[i].c=a[i].b-a[i].a+1;
	}
	for(int i=1;i<=m2;i++){
		scanf("%d %d",&b[i].a,&b[i].b);
		b[i].c=b[i].b-b[i].a+1;
	}
	sort(a+1,a+1+m1);
	sort(b+1,b+1+m2);
	for(int i=0;i<=n;i++){
		int k=n-i;
		ans=max(ans,work(i,k));
	}
	printf("%d",ans);
	return 0;
}
