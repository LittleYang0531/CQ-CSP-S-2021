#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n;
int a,b;
struct node{
	int start;
	int end;
	int id;
};
node gn[N],gw[N];
bool cmp(node x,node y){
	return x.start<y.start;
}
int d[N];
struct team{
	int f;
	int sx;
};
int ans;
int qa[N];
int qb[N];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=a;i++){
		cin>>gn[i].start>>gn[i].end;
		gn[i].id=i;
	}
	sort(gn+1,gn+a+1,cmp);
	for(int i=1;i<=b;i++){
		cin>>gw[i].start>>gw[i].end;
		gw[i].id=i;
	}
	sort(gw+1,gw+b+1,cmp);
	for(int i=0;i<=n;i++){
		int cnt1=i,cnt2=n-i,sum=0;
		for(int i=1;i<=N;i++) qa[i]=0,qb[i]=0;
		for(int j=1;j<=a;j++){
			bool flag=false;
			for(int k=1;k<=cnt1;k++){
				if(gn[j].start>=qa[k]){
					qa[k]=gn[j].end;
					sum++;
					flag=true;
					break;
				}
			}
		}
		for(int j=1;j<=b;j++){
			bool flag=false;
			for(int k=1;k<=cnt2;k++){
				if(gw[j].start>=qb[i+k]){
					qb[i+k]=gw[j].end;
					sum++;
					flag=true;
					break;
				}
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
