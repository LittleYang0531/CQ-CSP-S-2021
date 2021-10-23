#include<bits/stdc++.h>
#define N 400012
using namespace std;
int n,m1,m2;
struct A{
	int l,r;
}a[N];
int t[N],f1[N],f2[N];

int cmp(A x,A y){
	return x.l<y.l;
}

void js(int m,int fl){
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++) t[j]=0;
		for(int j=1;j<=m;j++){
			for(int k=1;k<=i;k++){
				if(a[j].l>t[k]){
					t[k]=a[j].r;
					if(fl) f1[i]++;
					else f2[i]++;
					break;
				}
			}
		}
	}
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	
	js(m1,1); js(m2,0);
	
	int ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,f1[i]+f2[n-i]);
		//printf("%d %d\n",f1[i],f2[i]);
	}
	printf("%d",ans);
	
	return 0;
}
