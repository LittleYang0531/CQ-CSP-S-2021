#include<bits/stdc++.h>
using namespace std;
int N,M1,M2;
struct AB{
	long long int a,b;
	bool operator  < ( AB const &B)const{
		if(a<B.a){
			return 1;
		}
		return 0;
	}
};
AB m1[100005];
AB m2[100005];
struct D{
	long long  nr;
	int sum;
};
D d1[100005];
D d2[100005];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf("%d%d%d",&N,&M1,&M2);
	for(int i=1;i<=M1;i++){
		scanf("%lld%lld",&m1[i].a,&m1[i].b);
	}
	for(int i=1;i<=M2;i++){
		scanf("%lld%lld",&m2[i].a,&m2[i].b);
	}
	sort(m1+1,m1+M1+1);
	sort(m2+1,m2+1+M2);
	int cnt1=1,cnt2=1;
	d1[1].nr=m1[1].b;
	d1[1].sum=1;
	d2[1].nr=m2[1].b;
	d2[1].sum=1;
	for(int j=2;j<=M1;j++){
		int fff=1;
		long long jl=m1[j].a,jr=m1[j].b;
		for(int i=1;i<=cnt1;i++){
			long long nr=d1[i].nr;
			if(jl>nr){
				fff=0;
				d1[i].sum++;
				d1[i].nr=jr;
				break;
			}
		}
		if(fff){
			d1[++cnt1].sum=1;
			d1[cnt1].nr=jr;
		}
	}
	for(int j=2;j<=M2;j++){
		int fff=1;
		long long jl=m2[j].a,jr=m2[j].b;
		for(int i=1;i<=cnt2;i++){
			long long nr=d2[i].nr;
			if(jl>nr){
				fff=0;
				d2[i].sum++;
				d2[i].nr=jr;
				break;
			}
		}
		if(fff){
			d2[++cnt2].sum=1;
			d2[cnt2].nr=jr;
		}
	}
	for(int i=2;i<=N;i++){
		d1[i].sum=d1[i-1].sum+d1[i].sum;
	}
	for(int i=2;i<=N;i++){
		d2[i].sum=d2[i-1].sum+d2[i].sum;
	}
	int ans=0;
	for(int i=0;i<=N;i++){
		ans=max(ans,d1[i].sum+d2[N-i].sum);
	}
	printf("%d",ans);
	return 0;
}
/*
5 5 5
1 2
2 3
3 4
4 5
5 6
2 3
3 3
3 5
4 5
5 5

*/
