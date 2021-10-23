#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N],p[N][2];
int a1[N];
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) {
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) p[i][0]=p[i][1]=0;
		for(int i=1;i<=n*2;i++) {
			scanf("%d",&a[i]);
			if(p[a[i]][0]) p[a[i]][1]=i;
			else p[a[i]][0]=i;
		}
		int l=1,r=n*2,x=p[a[l]][0],y=p[a[l]][0];
		if(p[a[l]][1]!=1) x=y=p[a[l]][1];
		l++;
		bool flag=1;
		for(int t=2;t<=n;t++) {
			int k=p[a[l]][p[a[l]][0]==l];
			if(k+1==x) {
				a1[t]=1,a1[n*2-t+1]=1;
				l++;x--;
			}
			else if(y+1==k) {
				a1[t]=1,a1[n*2-t+1]=0;
				l++;y++;
			}
			else {
				k=p[a[r]][p[a[r]][0]==r];
//				printf("%d %d(%d %d)\n",k,r,x,y);
				if(k+1==x) {
					a1[t]=0,a1[n*2-t+1]=1;
					r--;x--;
				}
				else if(y+1==k) {
					a1[t]=0,a1[n*2-t+1]=0;
					r--;y++;
				}
				else {flag=0;break;}
			}
//			printf("%d %d %d %d\n",l,r,x,y);
		}
		if(flag) {
			a1[1]=a1[n*2]=1;
			for(int i=1;i<=n*2;i++) {
				if(a1[i]==1) printf("L");
				else printf("R");
			}
			puts("");
			continue;
		}
		
		
		l=1,r=n*2;
		x=y=p[a[r]][p[a[r]][0]==r]; r--;
		flag=1;
		for(int t=2;t<=n;t++) {
			int k=p[a[l]][p[a[l]][0]==l];
			if(k+1==x) {
				a1[t]=1,a1[n*2-t+1]=1;
				l++;x--;
			}
			else if(y+1==k) {
				a1[t]=1,a1[n*2-t+1]=0;
				l++;y++;
			}
			else {
				k=p[a[r]][p[a[r]][0]==r];
//				printf("%d %d(%d %d)\n",k,r,x,y);
				if(k+1==x) {
					a1[t]=0,a1[n*2-t+1]=1;
					r--;x--;
				}
				else if(y+1==k) {
					a1[t]=0,a1[n*2-t+1]=0;
					r--;y++;
				}
				else {flag=0;break;}
			}
//			printf("%d %d %d %d\n",l,r,x,y);
		}
		if(!flag) printf("-1\n");
		else {
			a1[1]=0;a1[n*2]=1;
			for(int i=1;i<=n*2;i++) {
				if(a1[i]==1) printf("L");
				else printf("R");
			}
			puts("");
		}
	}
	return 0;
}
