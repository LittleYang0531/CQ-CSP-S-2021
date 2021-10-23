#include<bits/stdc++.h>
using namespace std;
struct node{
	int s1,s2;
};
int n,m1,m2;
node gn[100001];//国内：来，去 
node gj[100001];//国际：来，去 
int ans=0;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&gn[i].s1,&gn[i].s2);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&gj[i].s1,&gj[i].s2);
	}
	for(int i=0;i<=n;i++){
		int m=n-i;
		int qiao1[100001];
		int qiao2[100001];
		int ans1=0;
		int shi=0;
		for(int j=1;j<=m1;j++){
			shi=gn[j].s1;
			bool pan=true;
			int w=5;
			for(w=1;w<=i;w++){
				if(qiao1[w]<=shi){
					qiao1[w]=0;
					break;
				}
			}
			if(w==i) continue;
			qiao1[w]=gn[j].s2;
			ans1++;
		}
		shi=0;
		for(int j=1;j<=m2;j++){
			shi=gj[j].s1;
			bool pan=true;
			int w=5;
			for(w=1;w<=m;w++){
				if(qiao2[w]<=shi){
					qiao2[w]=0;
					break;
				}
			}
			if(w>=m) continue;qiao2[w]=gj[j].s2;
			ans1++;
		}
		ans=max(ans,ans1);
	}
	cout<<ans-1;
	return 0;
}

