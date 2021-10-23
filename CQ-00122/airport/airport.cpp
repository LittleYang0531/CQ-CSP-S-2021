#include<bits/stdc++.h>
using namespace std;
struct Plane{
	int arrival,departure;
	bool domestic;
	bool operator < (Plane &a) const {
		return arrival<a.arrival;
	}
}ps[100005];
int n,m1,m2,maxDeparture,a,b,l,dm,it,ol;
priority_queue<int,vector<int>,greater<int> > dome1,dome2,inte1,inte2;
int max(int &a,int &b){
	return a>b?a:b; 
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i = 1;i <= m1;i++){
		scanf("%d%d",&ps[i].arrival,&ps[i].departure);
		maxDeparture = max(maxDeparture,ps[i].departure);
		ps[i].domestic = 1;
	}
	for(int i = m1+1;i <= m1+m2;i++){
		scanf("%d%d",&ps[i].arrival,&ps[i].departure);
		maxDeparture = max(maxDeparture,ps[i].departure);
		ps[i].domestic = 0;
	}
	sort(ps+1,ps+1+m1+m2);
	for(int i = 0;i <= n;i++){
		l = 1;
		a = b = dm = it = 0;
		for(int j = ps[l].arrival;j <= maxDeparture;j++){ 
			if(!dome1.empty() && j==dome1.top()){
				dm--;
				dome1.pop();
			}
			if(!dome2.empty() && j==dome2.top())
				dome2.pop();
			if(!inte1.empty() && j==inte1.top()){
				it--;
				inte1.pop();
			}
			if(!inte2.empty() && j==inte2.top())
				inte2.pop();
			if(j == ps[l].arrival){
				if(ps[l].domestic){
					if(dm < i){
						dome1.push(ps[l].departure);
						dm++;
						a++;
					}else
						dome2.push(ps[l].departure);	
				}
				else{
					if(it < n-i){
						inte1.push(ps[l].departure);
						it++;
						b++;
					}else
						inte2.push(ps[l].departure);	
				}
				l++;
				if(l > m1+m2)
					break;
			}
		}
		ol = max(ol,a+b);
	} 
	printf("%d",ol);
	return 0;
} 


