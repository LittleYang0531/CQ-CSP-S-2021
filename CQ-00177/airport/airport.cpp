#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m1,m2,f1[5001][5001],f2[5001][5001],t[5001],ans;
struct plane {
	int st,en;
} a[5001],b[5001];
bool cmp(plane x,plane y) {
	if(x.st!=y.st)return x.st<y.st;
	return x.en<y.en;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1; i<=m1; i++)
		scanf("%d%d",&a[i].st,&a[i].en);
	for(int i=1; i<=m2; i++)
		scanf("%d%d",&b[i].st,&b[i].en);
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int i=0; i<=n; i++) {
		memset(t,-1,sizeof(t));
		for(int j=1; j<=m1; j++) {
			bool fl=false;
			for(int k=1; k<=i; k++) {
				if(t[k]<a[j].st) {
					t[k]=a[j].en;
					f1[i][j]=f1[i][j-1]+1;
					fl=true;
					break;
				}
			}
			if(!fl) f1[i][j]=f1[i][j-1];
		}
		memset(t,-1,sizeof(t));
		for(int j=1; j<=m2; j++) {
			bool fl=false;
			for(int k=1; k<=n-i; k++) {
				if(t[k]<b[j].st) {
					t[k]=b[j].en;
					f2[n-i][j]=f2[n-i][j-1]+1;
					fl=true;
					break;
				}
			}
			if(!fl) f2[n-i][j]=f2[n-i][j-1];
		}
		ans=max(ans,f1[i][m1]+f2[n-i][m2]);
	}
	printf("%d",ans);
	return 0;
}
