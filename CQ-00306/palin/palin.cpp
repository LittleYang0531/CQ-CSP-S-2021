#include<bits/stdc++.h>
using namespace std;
int a[2005],n;
int apr[2005],ans[2005],step[2005];
bool pd;

void START(){
	for(int i=1;i<=2*n;i++) apr[i]=ans[i]=step[i]=a[i]=0;
	pd=0;
}

bool check(){
	bool jd=1;
	for(int i=1;i<=n;i++){
		if(ans[i]!=ans[2*n-i+1]){
			jd=0;
			break;
		}
	}
	if(jd){
		pd=1;
		return true;
	}
	else false;
}

void print(){
	for(int i=1;i<=2*n;i++){
		if(!step[i]) printf("L");
		else printf("R");
	}
	printf("\n");
}

void Violent(int l,int r,int tot){
//	for(int i=1;i<=tot;i++) printf("%d ",ans[i]);
//	cout<<endl;
	if(pd) return ;
	if(tot==2*n){
//	cout<<"ecninihvc";
		if(check()) print();
		return ;
	}
	
	if(tot<n){
		if(apr[a[l+1]]){
			apr[a[l+1]]--;
			ans[tot+1]=a[l+1];
			step[tot+1]=0;
			Violent(l+1,r,tot+1);
			apr[a[l+1]]++;
		}
		if(apr[a[r-1]]){
			apr[a[r-1]]--;
			ans[tot+1]=a[r-1];
			step[tot+1]=1;
			Violent(l,r-1,tot+1);
			apr[a[r-1]]++;
		}
	}
	
	if(tot>=n){
		if(a[l+1]==ans[2*n-tot]){
			ans[tot+1]=a[l+1];
			step[tot+1]=0;
			Violent(l+1,r,tot+1);
		}
		else if(a[r-1]==ans[2*n-tot]){
			ans[tot+1]=a[r-1];
			step[tot+1]=1;
			Violent(l,r-1,tot+1);
		}
		else return ;
	}
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		START();
		if(n>1000){
			for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
			for(int i=1;i<=2*n;i++) printf("L ");
			printf("\n"); continue;
		}
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
			apr[a[i]]=1;
		}
		Violent(0,2*n+1,0);
		if(!pd) printf("-1\n");
	}
}
