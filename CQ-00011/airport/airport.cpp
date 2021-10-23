#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define inf 0x7fffffff
#define mem(a) memset(a,0,sizeof a)
using namespace std;
int n,m1,m2;
int n1,n2;
int s1,s2;
int ans;
int a1[100005],a2[100005];
int b1[100005],b2[100005];
int c1[100005],c2[100005];
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i)
		scanf("%d %d",&a1[i],&b1[i]);
	for(int i=1;i<=m2;++i)
		scanf("%d %d",&a2[i],&b2[i]);
	for(int o=0;o<=n;++o) {
		n1=o,n2=n-o;
		s1=0,s2=0;
		mem(c1),mem(c2);
		for(int i=1;i<=m1;++i) {
			for(int j=1;j<=n1;++j) {
				if(c1[j]<=a1[i]) {
					++s1,c1[j]=b1[i];
					break;
				}
			}
		}
		for(int i=1;i<=m2;++i) {
			for(int j=1;j<=n2;++j) {
				if(c2[j]<=a2[i]) {
					++s1,c2[j]=b2[i];
					break;
				}
			}
		}
		ans=max(ans,s1+s2);
	}
	printf("%d",ans);
	return 0;
}
//sto CRN GYH orz

