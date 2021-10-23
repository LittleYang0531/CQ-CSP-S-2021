#include<bits/stdc++.h>
using namespace std;
const int M=1e6+1,MAX=0x7fffffff/2;
//priority_queue<int, vector<int>, greater<int> > q;
int tt,n;
int a[M];
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&tt);
	for(int a1=1; a1<=tt; a1++) {
		scanf("%d",&n);
		for(int i=1; i<=n; i++) scanf("%d",&a[i]);
		int flag=0,bj=0;
		for(int num=1; num<=n; num++) if(flag==0) for(int i=1; i<=2*n; i++) if(flag==0) for(int j=1; j<=2*n; j++)
		if(a[i]==num&&a[j]==num) {
			if(abs(i-j)&1) {
				if(bj==2) {
					flag=1;
					break;
				}
				bj=1;
			}
			if(abs(i-j)&1==0) {
				if(bj==1) {
					flag=1;
					break;
				}
				bj=2;
			}
		}
		if(flag==1) printf("-1\n");
	}
	return 0;
}

