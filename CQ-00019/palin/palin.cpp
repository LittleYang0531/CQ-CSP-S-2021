#include<bits/stdc++.h>
#define _I inline
#define _R register
#define mod 998244353
#define INF 0x3f3f3f3f
#define eps 1e-4
#define memset(x,y) memset(x,y,sizeof(x))
#define memcpy(x,y) memcpy(x,y,sizeof(x))
#define ll long long
#define ull unsigned long long
using namespace std;
//char buf[1<<19],*p1=buf,*p2=buf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<19,stdin)),p1==p2)?EOF:*p1++;
int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	if(f)x=-x;return x;
}
const int N=1000005;
int t,n,st[N],top,a[N],ans,mx[N],last[N];
signed main(){
//	system("fc palin2.out palin2.ans");
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		n=read();for(_R int i=1;i<=n+n;++i)a[i]=read();ans=-1;
		if(n<=20){
			for(_R int s=0;s<(1<<n);++s){
				int l=1,r=n+n;top=0;
				for(_R int i=n-1;i>=0;--i)if(!((1<<i)&s))st[++top]=a[l],++l;else st[++top]=a[r],--r;
				int bj=1;
				for(_R int i=n;i>=1;--i){
					if(a[l]!=st[i]&&a[r]!=st[i]){bj=0;break;}
					if(a[l]==st[i])++l;else --r;
				}
				if(bj){ans=s;break;}
			}
			if(ans==-1)puts("-1");
			else{
				top=0;int l=1,r=n+n;
				for(_R int i=n-1;i>=0;--i)if(!((1<<i)&ans))st[++top]=a[l],++l,putchar('L');else st[++top]=a[r],--r,putchar('R');
				for(_R int i=n;i>=1;--i)if(a[l]==st[i])putchar('L'),++l;else putchar('R'),--r;
				puts("");
			}
		}
		else{
			for(_R int i=1;i<=n+n;++i)mx[i]=0,last[i]=0;
			for(_R int i=1;i<=n+n;++i){
				if(!last[a[i]])last[a[i]]=i;else mx[last[a[i]]]=i;
			}int num=0;
			for(_R int i=1,mxx=0;i<=n+n;++i){
				if(mx[i]>mxx)mxx=mx[i],++num;
			}if(num>2)puts("-1");
			else if(num==1){
				for(_R int i=1;i<=n+n;++i)putchar('L');puts("");
			}
			else if(num==2){
				int p=0;
				for(_R int i=1;i<=n+n;++i)if(mx[i])++p;else break;
				for(_R int i=1;i<=p;++i)putchar('L');for(_R int i=1;i<=n+n-p-p;++i)putchar('R');
				for(_R int i=1;i<=p;++i)putchar('L');puts("");
			}
		}
	}
	return 0;
}
/*
4
2 1 2 2 1
3 1 1 2 2 3 3
4 1 2 2 1 3 4 4 3
5 3 3 1 2 4 5 5 4 2 1
*/
