#include<stdio.h>
#include<set>
#include<map>
using namespace std;
#define R register int
#define N 100000
struct PlaneSet{
	int A[N],B[N],C[N],Tot;
	inline void Init(const int n){
		Tot=n;
		for(R i=0;i!=n;i++){
			scanf("%d%d",A+i,B+i);
		}
	}
	inline void Calc(const int n){
		set<int>S;
		for(int i=1;i<=n;i++){
			S.insert(i);
		}
		map<int,pair<int,int> >Q;
		for(R i=0;i!=Tot;i++){
			Q[A[i]]=make_pair(B[i],1);
		}
		while(Q.empty()==false){
			pair<int,int>T=Q.begin()->second;
			Q.erase(Q.begin());
			if(T.second==1){
				if(S.empty()==false){
					int x=*S.begin();
					C[x]++;
					S.erase(x);
					Q[T.first]=make_pair(x,-1);
				}
			}else{
				S.insert(T.first);
			}
		}
		for(R i=2;i<=n;i++){
			C[i]+=C[i-1];
		}
	}
}D,E;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,ans=0;
	scanf("%d%d%d",&n,&m1,&m2);
	D.Init(m1);
	E.Init(m2);
	D.Calc(n);
	E.Calc(n);
	for(R i=0;i<=n;i++){
		int x=D.C[i]+E.C[n-i];
		if(x>ans){
			ans=x;
		}
	}
	printf("%d",ans);
	return 0;
}
