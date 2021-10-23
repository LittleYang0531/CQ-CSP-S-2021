#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e6+10;

int t;
int n;
int len;
int a[N],b[N];

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}

bool check(){
	for(int i=1;i<=n;++i){
		if(b[i]!=b[len-i+1])return 0;
	}
	return 1;
}

void Print(int i){
	for(int j=len-1;j>=0;--j){
		if((i>>j)&1)printf("R");
		else printf("L");
	}
	printf("\n");
//	for(int i=1;i<=len;++i){
//		printf("%d",b[i]);
//	}
//	printf("\n-------\n");
}

signed main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	t=read();
	while(t--){
		n=read();len=n*2;
		for(int i=1;i<=len;++i){
			a[i]=read();
		}
		bool flag=0;
		for(int i=0;i<(1ll<<len);++i){
//			printf("%d\n",i);
			int cnt=0,l=1,r=len;
			for(int j=len-1;j>=0;--j){
				if((i>>j)&1)b[++cnt]=a[r],--r;
				else b[++cnt]=a[l],++l;
			}
//			Print(i);
			if(check()){
				Print(i);
				flag=1;
				break;
			}
		}
		if(!flag)printf("-1\n");
	}
	return 0;
}
