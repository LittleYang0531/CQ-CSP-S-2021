#include <cstdio>
#define print(x,y) write(x),putchar(y)

template <class T>
inline T read(const T sample) {
	T x=0; char s; bool f=0;
	while((s=getchar())>'9' or s<'0')
		f |= (s=='-');
	while(s>='0' and s<='9')
		x = (x<<1)+(x<<3)+(s^48),
		s = getchar();
	return f?-x:x;
}

template <class T>
inline void write(const T x) {
	if(x<0) {
		putchar('-');
		write(-x);
		return;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}

const int maxn = 5e5+5;

bool ahh;
int n,s[maxn<<1];
char ans[maxn<<1],tmp[maxn<<1];
int fk[maxn<<1];

void update() {
	bool flag=0;
	for(int i=1;i<=n;++i)
		if(tmp[i]=='L' and ans[i]=='R') {
			flag=1;break;
		}
		else if(tmp[i]=='R' and ans[i]=='L')
			break;
	if(flag) {
		for(int i=1;i<=n;++i)
			ans[i]=tmp[i];
	}
}

bool all() {
	for(int i=1;i<=n;++i)
		if(ans[i]=='L')
			return 0;
	return 1;
}

void dfs(int x,int a,int b,int c,int d) {
	if(x==(n>>1)+1) {
		for(int i=(n>>1);i;--i) {
			if(fk[i]==s[b+1]) {
				tmp[x++]='L'; ++b;
			}
			else {
				tmp[x++]='R'; --c;
			}
		}
		update();
		ahh=1;
		return;
	}
	if(a<=b) {
		fk[x]=s[a];
		if(a<b and s[b]==s[a]) {
			tmp[x]='L';
			dfs(x+1,a+1,b-1,c,d);
			if(ahh) return;
		}
		else if(s[a]==s[c]) {
			tmp[x]='L';
			dfs(x+1,a+1,b,c+1,d);
			if(ahh) return;
		}
	}
	if(c<=d) {
		fk[x]=s[d];
		tmp[x]='R';
		if(c<d and s[c]==s[d]) {
			dfs(x+1,a,b,c+1,d-1);
			if(ahh) return;
		}
		else if(s[d]==s[b]) {
			dfs(x+1,a,b-1,c,d-1);
			if(ahh) return;
		}
	}
}

int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	bool aaaa;
	for(int T=read(9);T;--T) {
		n=read(9); n<<=1; ahh=0;
		aaaa=0;
		for(int i=1;i<=n;++i)
			s[i]=read(9);
		for(int i=1;i<=n;++i)
			ans[i]='R';
		tmp[1]='L'; fk[1]=s[1];
		int p;
		for(int i=2;i<=n;++i)
			if(s[1]==s[i]) {
				p=i; break;
			}
		dfs(2,2,p-1,p+1,n);
		aaaa|=ahh;
		ahh=0;
		tmp[1]='R'; fk[1]=s[n];
		for(int i=1;i<n;++i)
			if(s[n]==s[i]) {
				p=i; break;
			}
		dfs(2,1,p-1,p+1,n-1);
		aaaa|=ahh;
		if(!aaaa) puts("-1");
		else {
			for(int i=1;i<=n;++i)
				putchar(ans[i]);
			puts("");
		}
	}
	return 0;
}
/*

*/
