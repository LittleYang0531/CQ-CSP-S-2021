#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	int val;
};
node xx[500005];
int n,a[1000005],L[500005],R[500005];
int p[500005],tong[500005];
bool use[500005],can=false;
char ans[500005],ans1[500005];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		can=false;
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
			if(!L[a[i]])L[a[i]]=i;
			else R[a[i]]=i;
		}
		for(int i=1;i<=n;i++)xx[i].id=i,xx[i].val=L[i];
		sort(xx+1,xx+n+1,cmp);
		if(!can){
			printf("-1\n");
		}
	}
	return 0;
}
