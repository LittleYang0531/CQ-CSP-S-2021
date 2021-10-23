#include<bits/stdc++.h>
using namespace std;
int n,t;
int ans[1000005],a[1000005],b[1000005],alas,bnum,afir; 
bool ok;
void found(int x){
	if(x>n+1){
		if(b[x-1]!=b[2*n+2-x])return;
	}
	if(x>2*n){
		for(int i=1;i<=2*n;i++){
		    if(ans[i]==1)printf("L");
		    else printf("R");
		}
		printf("\n");
		ok=1;
		return; 
	}
	ans[x]=1;//²Ù×÷1
	b[++bnum]=a[afir];
	afir++;
	found(x+1);
	if(ok)return;
	afir--;
	ans[x]=2;
	b[bnum]=a[alas];//²Ù×÷¶þ 
	alas--;
	found(x+1);
	if(ok)return;
	alas++;
	b[bnum]=0;
	bnum--;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int x=1;x<=t;x++){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		memset(b,0,sizeof(b));
		for(int i=1;i<=2*n;i++)
		    scanf("%d",&a[i]);
		ok=0;
		alas=2*n;
		bnum=0;
		afir=1;
		found(1);
		if(!ok)printf("-1\n");
	}
	return 0;
}
