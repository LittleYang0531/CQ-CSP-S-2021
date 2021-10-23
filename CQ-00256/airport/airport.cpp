#include<bits/stdc++.h>
using namespace std;

struct zz{
	int l,r;
}a[3][100005],b[100005];
int N,m1,m2;

int s[3][200005],sum[200005];
int flag[200005],tot1=0;
int Max[3][200005];
int f[3][200000];

int tot[3]={};
int lsh[3][2000005];

void Fuck(int n,int op){
	tot[op]=tot1=0;
	for(int i=1;i<=n;i++) scanf("%d%d",&a[op][i].l,&a[op][i].r),lsh[op][++tot[op]]=a[op][i].l,lsh[op][++tot[op]]=a[op][i].r+1;
//	printf("QwQ\n");
	sort(lsh[op]+1,lsh[op]+tot[op]+1);
	tot[op]=unique(lsh[op]+1,lsh[op]+tot[op]+1)-(lsh[op]+1);
	for(int i=1;i<=n;i++){
		int len=lower_bound(lsh[op]+1,lsh[op]+tot[op]+1,a[op][i].l)-lsh[op];s[op][len]++;
		f[op][len]=i;
		len=lower_bound(lsh[op]+1,lsh[op]+tot[op]+1,a[op][i].r+1)-lsh[op],s[op][len]--;
	}
}

void File(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
}

int main(){
	File();
//	freopen("airport3.in","r",stdin);
	int ans=0;
	cin>>N>>m1>>m2;
	Fuck(m1,1);
//	for(int i=1;i<=2*m1;i++) printf("fffffuck:%d %d\n",i,s[1][i]);
	Fuck(m2,2);
//	for(int i=1;i<=2*m1;i++) printf("qqqqq:%d %d\n",i,s[1][i]);
	for(int i=0;i<=min(m1,N);i++){
		int j=N-i;
		int now1=m1,now2=m2;
		for(int k=1;k<=2*m1;k++) sum[k]=s[1][k];//,printf("fffffuck:%d %d\n",k,s[1][k]);
		for(int k=1;k<=2*m1;k++){
			if(sum[k]+sum[k-1]>i){
				sum[k]=0,now1--;
				int now=f[1][k];
				int len=lower_bound(lsh[1]+1,lsh[1]+tot[1]+1,a[1][now].r+1)-lsh[1];sum[len]++;
			} 
			sum[k]+=sum[k-1];
//			printf("QWQ:%d %d\n",k,sum[k]);
		}
		
		for(int k=1;k<=2*m2;k++) sum[k]=s[2][k];
		for(int k=1;k<=2*m2;k++){
			if(sum[k]+sum[k-1]>j){
				sum[k]=0,now2--;
				int now=f[2][k];
				int len=lower_bound(lsh[2]+1,lsh[2]+tot[2]+1,a[2][now].r+1)-lsh[2];sum[len]++;
			} 
			sum[k]+=sum[k-1];
		}
		ans=max(ans,now1+now2);
//		printf("%d %d: %d %d\n",i,j,now1,now2);
	}
	printf("%d\n",ans);
	return 0;
}
