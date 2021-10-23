#include<bits/stdc++.h>
using namespace std;
const int N=1e6+101,inf=0x3f3f3f3f;

inline int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') { s=s*10+ch-'0';ch=getchar();}
	return s*w;
}

struct node {
	int x,y;
}d1[N],d2[N];
bool cmp(node a,node b) {
	return a.x<b.x;
}

vector<int> a1,b1,a2,b2;

//int a1[N],b1[N],a2[N],b2[N];
int sum1[N],sum2[N],c[N];
signed main() {
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	int n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;++i) d1[i].x=read(),d1[i].y=read();
	for(int i=1;i<=m2;++i) d2[i].x=read(),d2[i].y=read();
	sort(d1+1,d1+m1+1,cmp);
	sort(d2+1,d2+m2+1,cmp);
	for(int i=1;i<=m1;++i) a1.push_back(d1[i].x),b1.push_back(d1[i].y);
	for(int i=1;i<=m2;++i) a2.push_back(d2[i].x),b2.push_back(d2[i].y);
	
	for(int i=1;i<=n;++i) {
		int t=0;
		int siz=a1.size();
 		if(siz) {
 			c[++t]=0;
 			int k=b1[0];
 			for(int j=1;j<siz;++j) {
	 			if(a1[j]>=k) {
	 				k=b1[j];
	 				c[++t]=j;
 				}
			}
			for(int j=t;j>=1;--j) {
				a1.erase(a1.begin()+c[j]);
				b1.erase(b1.begin()+c[j]);
			}
		}
		else break;
		sum1[i]=sum1[i-1]+t;
	}
	for(int i=1;i<=n;++i) {
		int t=0;
		int siz=a2.size();
 		if(siz) {
 			c[++t]=0;
 			int k=b2[0];
 			for(int j=1;j<siz;++j) {
	 			if(a2[j]>=k) {
	 				k=b2[j];
	 				c[++t]=j;
 				}
			}
			for(int j=t;j>=1;--j) {
				a2.erase(a2.begin()+c[j]);
				b2.erase(b2.begin()+c[j]);
			}
		}
		else break;
		sum2[i]=sum2[i-1]+t;
	}
	int ans=0;
	for(int i=0;i<=n;++i) {
		int w1=i,w2=n-i;
		ans=max(ans,sum1[w1]+sum2[w2]);
	}
	printf("%d",ans);
	return 0;
}
