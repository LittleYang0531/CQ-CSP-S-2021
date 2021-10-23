#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &n){
	T w=1;n=0;
	char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<1)+(n<<3)+(ch&15);ch=getchar();}
	n*=w;
}
const int N=5e5+5;
int T,n,a[N<<1],ans[N<<1],vis[N];
void solve(int i,int l,int r){
	if(i==(n<<1)+1){
		for(int i=1,j=(n<<1);i<j;i++,j--)
		if(ans[i]!=ans[j])return;
		ans[0]=0;return;
	}
	ans[i]=a[l];solve(i+1,l+1,r);
	if(ans[0]!=-1)return;
	ans[i]=a[r];solve(i+1,l,r-1);
}
void solve_ans(){
	int l=1,r=(n<<1);
	for(int i=1;i<=(n<<1);++i)
	if(ans[i]==a[l]){putchar('L');l++;}
	else {putchar('R');r--;}
	putchar('\n');
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		for(int i=1;i<=(n<<1);i++)read(a[i]);
		if(n<=10){
			ans[0]=-1;
			solve(1,1,n<<1);
			if(ans[0]==-1)printf("-1\n");
			else solve_ans();
			continue;
		}
		bool ok=0;
		for(int i=1,j=(n<<1);i<j;i++,j--)
		if(a[i]!=a[j]){
			printf("-1");ok=1;
			break;
		}
		if(ok)continue;
		for(int i=1;i<=n;++i)
			putchar('L');
		for(int i=1;i<=n;++i)
			putchar('R');
		putchar('\n');
	}
	return 0;
}
