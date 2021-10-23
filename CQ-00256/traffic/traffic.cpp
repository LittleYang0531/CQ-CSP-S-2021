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
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
}

int main(){
	File();
	srand(time(0));
	printf("%d",rand());
	return 0;
}
