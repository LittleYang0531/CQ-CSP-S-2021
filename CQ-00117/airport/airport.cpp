#include<bits/stdc++.h>
using namespace std;
int n,a,b,cntc,cntd;
int f[100010];
int lqc[100010],lqd[100010];
struct pl{
	int x,y;
	bool operator < (const pl &h)const{
		return y>h.y;
	}
}c[100010],d[100010];
priority_queue<pl> qc;
priority_queue<pl> qd;
void clean_que(){
	while(!qc.empty())qc.pop();
	while(!qd.empty())qd.pop();
}
inline bool cmp(pl &a,pl &b){
	return a.x<b.x;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=a;i++)
		scanf("%d%d",&c[i].x,&c[i].y);
	for(int i=1;i<=b;i++)
		scanf("%d%d",&d[i].x,&d[i].y);
	sort(c+1,c+1+a,cmp),sort(d+1,d+1+b,cmp);
	int sum=0,td,ans=0;
	pl now;
	for(int t=0;t<=n;t++){
		clean_que(),sum=0;
		if(t){
			qc.push(c[1]),sum++;
			for(int i=2;i<=a;i++){
				while(c[i].x>qc.top().y&&qc.size())qc.pop();
				if(qc.size()<t)qc.push(c[i]),sum++;
			}
		}
		if(t!=n){
			qd.push(d[1]),sum++;
			td=n-t;
			for(int i=2;i<=b&&t!=n;i++){
				while(d[i].x>qd.top().y&&qd.size())qd.pop();
				if(qd.size()<td)qd.push(d[i]),sum++;
			}
		}
		if(sum>ans)ans=sum;
	}
	printf("%d",ans);
	return 0;
}
