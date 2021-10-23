#include<bits/stdc++.h>
using namespace std;
int a2[100010],b2[100010],c1[100010],c2[100010],d2[100010],d1[100010],r1=100000,r2=1000000,l1,l2;
int find(int x,int y){
	int sum1=0,sum2=0;
	for(int i=r1;i<=l1;i++){
		if(a2[i]==1&&x>0){
			sum1++;
			x--;
			d1[c1[i]]++;
		}
		if(d1[i]){
			x++;
		}
	}
	for(int i=r2;i<=l2;i++){
		if(b2[i]==1&&y>0){
			sum2++;
			y--;
			d2[c2[i]]++;
		}
		if(d2[i]){
			y++;
		}
	}
	return sum1+sum2;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int ans,b1,a1,n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=0;i<m1;i++){
		scanf("%d%d",&a1,&b1);
		a2[a1]++;
		c1[a1]=b1;
		r1=min(r1,a1);
		l1=max(l1,b1);
	}
	for(int i=0;i<m2;i++){
		scanf("%d%d",&a1,&b1);
		b2[a1]++;
		c2[a1]=b1;
		r2=min(r2,a1);
		l2=max(l2,b1);
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,find(i,n-i));
	}
	printf("%d",ans);
	return 0;
}
