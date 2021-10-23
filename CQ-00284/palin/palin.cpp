#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int t,n,a[N],p;
int l1,l2,q1[N],q2[N],h1,h2,t1,t2;
int s,ans[N];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		bool vis=0;
		memset(ans,0,sizeof(ans));
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
			if(a[i]==a[1]){
				p=i;
			}
		}
		s=1;
		l1=l2=0;
		ans[s]=ans[2*n]=0;
		for(int i=2;i<p;i++){
			q1[++l1]=a[i];
		}
		for(int i=2*n;i>p;i--){
			q2[++l2]=a[i];
		}
		h1=1,t1=l1,h2=1,t2=l2;
		while(h1<=t1||h2<=t2){
			if(h1<t1&&q1[h1]==q1[t1]){
				h1++;
				t1--;
				ans[++s]=0;
				ans[2*n-s+1]=0;
			}else if(h1<=t1&&q1[h1]==q2[t2]){
				h1++;
				t2--;
				ans[++s]=0;
				ans[2*n-s+1]=1;
			}else if(h2<=t2&&q2[h2]==q1[t1]){
				h2++;
				t1--;
				ans[++s]=1;
				ans[2*n-s+1]=0;
			}else if(h2<t2&&q2[h2]==q2[t2]){
				h2++;
				t2--;
				ans[++s]=1;
				ans[2*n-s+1]=1;
			}else{
				vis=1;
				break;
			}
		}
		if(vis){
			vis=0;
			memset(ans,0,sizeof(ans));
			for(int i=1;i<2*n;i++){
				if(a[i]==a[1]){
					p=i;
				}
			}
			s=1;
			l1=l2=0;
			ans[s]=1;
			ans[2*n]=0;
			for(int i=1;i<p;i++){
				q1[++l1]=a[i];
			}
			for(int i=2*n-1;i>p;i--){
				q2[++l2]=a[i];
			}
			h1=1,t1=l1,h2=1,t2=l2;
			while(h1<=t1||h2<=t2){
				if(h1<t1&&q1[h1]==q1[t1]){
					h1++;
					t1--;
					ans[++s]=0;
					ans[2*n-s+1]=0;
				}else if(h1<=t1&&q1[h1]==q2[t2]){
					h1++;
					t2--;
					ans[++s]=0;
					ans[2*n-s+1]=1;
				}else if(h2<=t2&&q2[h2]==q1[t1]){
					h2++;
					t1--;
					ans[++s]=1;
					ans[2*n-s+1]=0;
				}else if(h2<t2&&q2[h2]==q2[t2]){
					h2++;
					t2--;
					ans[++s]=1;
					ans[2*n-s+1]=1;
				}else{
					vis=1;
					break;
				}
			}
			if(vis){
				printf("-1\n");
				continue;
			}
		}
		for(int i=1;i<=2*n;i++){
			if(ans[i]==0){
				printf("L");
			}else{
				printf("R");
			}
		}
		printf("\n");
	}
	return 0;
}
