#include <cstdio>
using namespace std;
inline int read(){
	int x=0;char p=getchar();
	while(p<'0'||p>'9')p=getchar();
	while(p>='0'&&p<='9')x=(x<<3)+(x<<1)+(p^48),p=getchar();
	return x;
}
inline void pnum(int x){
	if (x>9) pnum(x/10);
	putchar(x%10+'0');
}
int a[1000002];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t=read();
	while (t--){
		int n=read(),f,j;
		for (int i=1;i<=n<<1;i++) a[i]=read();
		for (j=1;j<=n;j++){
			f=1;
			for (int i=1;i<=j&&f;i++) if (a[i]!=a[(j<<1)-i+1])f=0;
			for (int i=(j<<1)+1;i<=n<<1&&f;i++) if (a[i]!=a[(n<<1)-i+(j<<1)+1])f=0;
			if (f) break;
		}
		if (!f) {puts("-1");continue;}
		for (int i=1;i<=j;i++)putchar('L');
		for (int i=j<<1;i<n<<1;i++)putchar('R');
		for (int i=1;i<=j;i++)putchar('L');
		putchar('\n');
	}
	return 0;
}
