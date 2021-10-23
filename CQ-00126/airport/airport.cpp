#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int n,m1,m2,cnt1=0,cnt2=0,ans,he,ta;
struct node{
	int s,t;
}a[maxn],b[maxn],pl1[maxn],pl2[maxn];
struct node2{
	int si,sum,ti;
	bool operator <(const node2 &A)const {
		if(ti==A.ti)return si>A.si;
		return ti>A.ti;
	}
}q[maxn];
bool cmp(node x,node y){
	return x.s<y.s;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i].s,&a[i].t);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].s,&b[i].t);
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m1+1,cmp);
	he=1,ta=0;
	for(int i=1,mi,id;i<=m1;i++){
		mi=1e9,id=0;
		for(int j=1;j<=ta;j++){
			if(q[j].ti<=a[i].s){
				if(q[j].si<mi){
					mi=q[j].si;
					id=j;
				}
			}
		}
		if(id==0){
			q[++ta]=(node2){a[i].s,1,a[i].t};
		}
		else{
			q[id]=(node2){q[id].si,q[id].sum+1,a[i].t};
		}
	}
	while(he<=ta){
//	cout<<q.top().si<<' '<<q.top().ti<<' '<<q.top().sum<<'\n';
		pl1[++cnt1]=(node){q[he].si,q[he].sum};
		he++;
	}
	he=1,ta=0;
	for(int i=1,mi,id;i<=m2;i++){
		mi=1e9,id=0;
		for(int j=1;j<=ta;j++){
			if(q[j].ti<=b[i].s){
				if(q[j].si<mi){
					mi=q[j].si;
					id=j;break;
				}
			}
		}
		if(id==0){
			q[++ta]=(node2){b[i].s,1,b[i].t};
		}
		else{
			q[id]=(node2){q[id].si,q[id].sum+1,b[i].t};
		}
	}
	while(he<=ta){
//	cout<<q.top().si<<' '<<q.top().ti<<' '<<q.top().sum<<'\n';
		pl2[++cnt2]=(node){q[he].si,q[he].sum};
		he++;
	}
	sort(pl1+1,pl1+cnt1+1,cmp);
	sort(pl2+1,pl2+cnt2+1,cmp);
	int l=1,r=1;
//	printf("boom\n");
//	for(int i=1;i<=cnt1;i++)printf("%d %d \\ ",pl1[i]);
//	printf("\n");
//	for(int i=1;i<=cnt2;i++)printf("%d %d \\ ",pl2[i]);
//	printf("\n");
	for(int i=1;i<=n;i++){
		if(pl1[l].t>=pl2[r].t&&l<=cnt1)ans+=pl1[l++].t;
		else if(pl2[r].t>pl1[l].t&&r<=cnt2) ans+=pl2[r++].t;
	}
	printf("%d",ans);
	return 0;
}
