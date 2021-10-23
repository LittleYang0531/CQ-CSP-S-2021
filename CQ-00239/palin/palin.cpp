#include<bits/stdc++.h>
using namespace std;
int t,n,h,r,y[100005],a[100005];
bool v[100005],flag;
char ans[100005];
vector<int> p[100005];
bool check(int x,int k,int w) {
	v[x]=1;
	int i=h+1,sum=0;
	if(k==1) i=h;
	while(!v[i]) i++,sum++;
	if(k==0) i=r;
	else i=r-1;
	while(!v[i]) i--,sum++;
	if(sum==(n-w)*2) return 1;
	else v[x]=0;
	return 0;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.txt","w",stdout);
	scanf("%d",&t);
	while(t--) {
		memset(p,0,sizeof p);
		memset(v,0,sizeof v);
		scanf("%d",&n);
		for(int i=1; i<=n*2; i++) {
			scanf("%d",&a[i]);
			p[a[i]].push_back(i);
		}
		h=1,r=n*2,flag=0;
		int wh;
		for(int i=1; i<=n; i++) {
			if(check(p[a[h]][1],0,i)) {
				ans[i]='L';
				y[a[h]]=n-i+1,h++;
			} else if(check(p[a[r]][0],1,i)) {
				ans[i]='R';
				y[a[r]]=n-i+1,r--;
			} else {
				flag=1;
				wh=i;
				break;
			}
		}
		if(flag==1) printf("-1\n");
		else {
			int k=1;
			while(k<=n) {
				if(y[a[h]]==k) ans[k+n]='L',h++;
				else if(y[a[r]]==k) ans[k+n]='R',r--;
				else flag=1;
				k++;
			}
			if(flag==1) printf("-1\n");
			else {
				for(int i=1; i<=2*n; i++) cout<<ans[i];
				printf("\n");
			}
		}
	}
	return 0;
}
