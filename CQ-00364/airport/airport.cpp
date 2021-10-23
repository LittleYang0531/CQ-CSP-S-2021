#include<bits/stdc++.h>
using namespace std;
struct ap{
	int arrive,left;
}c[100010],oc[100010];
bool cmp(ap a,ap b){
	return a.arrive<b.arrive;
}
bool cmp1(ap x,ap y){
	return x.left<y.left;
}
int n,cnt,sum,ans,m1,m2,kc,koc,flyc[100010],flyoc[100010];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d%d",&c[i].arrive,&c[i].left);
	for(int i=1;i<=m2;i++)scanf("%d%d",&oc[i].arrive,&oc[i].left);
	for(int i=0;i<=n;i++){
		sort(c+1,c+1+m1,cmp);
		sort(oc+1,oc+1+m2,cmp);
		sum=0;
		kc=i;
		sum+=i;
		koc=n-i;
		sum+=(n-i);
		if(kc>0)	
			for(int j=i+1;j<=m1;j++){
				sort(c+1,c+1+kc,cmp1);			
				if(c[j].arrive>c[1].left){
					swap(c[1].left,c[j].left);
					swap(c[1].arrive,c[j].arrive);
					sum++;
				}
			}		
		if(koc>0)	
			for(int j=n-i+1;j<=m2;j++){
				sort(oc+1,oc+1+koc,cmp1);
				if(oc[j].arrive>oc[1].left){
					swap(oc[1].left,oc[j].left);
					swap(oc[1].arrive,oc[j].arrive);
					sum++;
				}
			}

		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
}
