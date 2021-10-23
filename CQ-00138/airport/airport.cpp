#include<bits/stdc++.h>
#define RI register int
using namespace std;
const int N=100005;
int n,m1,m2,fians=0,vis[N],viss[N],ans1[N],ans2[N],pre1[N],pre2[N];
int tot1,tot2;
template<typename T>
void Read(T &t){
	t=0;
	char c;
	int f=1;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-1;
	while(c>='0'&&c<='9')(t*=10)+=c-'0',c=getchar();
	t*=f;
}
struct node{
	int x,y;
}a1[N],a2[N];
bool cmp(node xx,node yy){
	return xx.x<yy.x;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	Read(n);
	Read(m1);
	Read(m2);
	for(RI i=1;i<=m1;i++){
		Read(a1[i].x);
		Read(a1[i].y);
	}
	for(RI i=1;i<=m2;i++){
		Read(a2[i].x);
		Read(a2[i].y);
	}
	sort(a1+1,a1+1+m1,cmp);
	sort(a2+1,a2+1+m2,cmp);
	
	for(RI i=1;i<=m1;i++){
		if(vis[i]!=0)continue;
		++tot1;
		ans1[tot1]++;
		int now=a1[i].y;
		for(RI j=i+1;j<=m1;j++){
			if(a1[j].x<now||vis[j]!=0)continue;
			ans1[tot1]++;
			vis[j]=1;
			now=a1[j].y;
		}
	}
	for(RI i=1;i<=m2;i++){
		if(viss[i]!=0)continue;
		++tot2;
		ans2[tot2]++;
		int now=a2[i].y;
		for(RI j=i+1;j<=m2;j++){
			if(a2[j].x<now||viss[j]!=0)continue;
			ans2[tot2]++;
			viss[j]=1;
			now=a2[j].y;
		}
	}
	int l=1,r=1;
	for(RI i=1;i<=n;i++)pre1[i]=pre1[i-1]+ans1[i];
	for(RI i=1;i<=n;i++)pre2[i]=pre2[i-1]+ans2[i];
	for(RI i=1;i<=n;i++){
		fians=max(fians,pre1[i]+pre2[n-i]);
	}
	printf("%d\n",fians);
	return 0;
}

