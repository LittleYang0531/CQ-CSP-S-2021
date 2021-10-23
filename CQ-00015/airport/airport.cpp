#include<bits/stdc++.h>
#define maxn 100005
#define INF 0x7fffffff
using namespace std;
inline int read(){
	register int x=0,f=1;
	register char c=getchar();
	while(c<'0' or c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' and c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
int n,m1,m2,ans=-INF;
struct node{int arr,lea;};
node a[maxn],b[maxn];
bool cmp(node a,node b){return a.arr<b.arr;}
int x[maxn],y[maxn];
//int A[maxn],B[maxn];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(); m1=read(); m2=read();
	for(int i=1;i<=m1;i++) a[i].arr=read(),a[i].lea=read();
	for(int i=1;i<=m2;i++) b[i].arr=read(),b[i].lea=read();
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int k=0;k<=n;k++){
		int c1=k,c2=n-k,cnt=0;
//		memset(A,0,sizeof(A));
//		memset(B,0,sizeof(B));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		for(int i=1;i<=m1;i++){
			int now=a[i].arr;
			for(int j=1;j<=c1;j++){
				if(x[j]==0){
					cnt++;
					x[j]=i;
//					A[i]=1;
					break;
				}else if(a[x[j]].lea<now){
					cnt++;
					x[j]=i;
//					A[i]=1;
					break;
				}
			}
		}
		for(int i=1;i<=m2;i++){
			int now=b[i].arr;
			for(int j=1;j<=c2;j++){
				if(y[j]==0){
					cnt++;
					y[j]=i;
//					B[i]=1;
					break;
				}else if(b[y[j]].lea<now){
					cnt++;
					y[j]=i;
//					B[i]=1;
					break;
				}
			}
		}
		ans=max(ans,cnt);
//		cout<<cnt<<endl;
//		for(int i=1;i<=m1;i++) printf("%d ",A[i]);
//		printf("     ");
//		for(int i=1;i<=m2;i++) printf("%d ",B[i]);
//		printf("\n");
	}
	printf("%d",ans);
	return 0;
}
