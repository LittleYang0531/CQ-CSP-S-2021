#include <bits/stdc++.h>
using namespace std;
int t,n;
int f[201000];
char ope[1000010];
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int yuu=1;yuu<=t;yuu++) {
		scanf("%d",&n);
	for(int i=1;i<=2*n;i++) scanf("%d",&f[i]);
	for(int i=1;i<=2*n;i++) ope[i]='0';
	int L,R,l,r,inde=0;
	for(int i=2;i<=2*n;i++) {
		if(f[i]==f[1]) {
			ope[++inde]='L';ope[2*n-inde+1]='L';
			L=2;R=2*n;l=i-1;r=i+1;break;
		}
	}
	bool tru1=1,tru2=1;
	while(true) {
		if(L>l) tru1=0;
		if(R<r) tru2=0;
		bool zuo=0;
		if(f[L]==f[l]&&tru1&&L!=l) {
			ope[++inde]='L';ope[2*n-inde+1]='L';
			L++;l--;zuo=1;
		} else if(f[L]==f[r]&&tru1&&tru2) {
			ope[++inde]='L';ope[2*n-inde+1]='R';
			L++;r++;zuo=1;
		} else if(f[R]==f[l]&&tru2&&tru1) {
			ope[++inde]='R';ope[2*n-inde+1]='L';
			R--;l--;zuo=1;
		} else if(f[R]==f[r]&&tru2&&R!=r) {
			ope[++inde]='R';ope[2*n-inde+1]='R';
			R--;r++;zuo=1;
		}
		if(!zuo) break;
	}
	if(inde==n) {
		for(int i=1;i<=2*n;i++) printf("%c",ope[i]);
		printf("\n");
		continue;
	}
	for(int i=1;i<=2*n;i++) ope[i]='0';
	inde=0;
	for(int i=2;i<=2*n;i++) {
		if(f[i]==f[2*n]) {
			ope[++inde]='R';ope[2*n-inde+1]='L';
			L=1;R=2*n-1;l=i-1;r=i+1;break;
		}
	}
	tru1=1;tru2=1;
	while(true) {
		if(L>l) tru1=0;
		if(R<r) tru2=0;
		bool zuo=0;
		if(f[L]==f[l]&&tru1&&L!=l) {
			ope[++inde]='L';ope[2*n-inde+1]='L';
			L++;l--;zuo=1;
		} else if(f[L]==f[r]&&tru1&&tru2) {
			ope[++inde]='L';ope[2*n-inde+1]='R';
			L++;r++;zuo=1;
		} else if(f[R]==f[l]&&tru2&&tru1) {
			ope[++inde]='R';ope[2*n-inde+1]='L';
			R--;l--;zuo=1;
		} else if(f[R]==f[r]&&tru2&&R!=r) {
			ope[++inde]='R';ope[2*n-inde+1]='R';
			R--;r++;zuo=1;
		}
		if(!zuo) break;
	}
	if(inde==n) {
		for(int i=1;i<=2*n;i++) printf("%c",ope[i]);
		printf("\n");
		continue;
	}
	cout << -1 << endl;
	}
	return 0;
}
