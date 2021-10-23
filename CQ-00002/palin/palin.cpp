#include<bits/stdc++.h>
using namespace std;
const int N=5e5+101;

inline int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') { s=s*10+ch-'0';ch=getchar();}
	return s*w;
}

deque<int> a;

char ch[N],s[N];
int b[N],mi[N],n;
void dfs(int pos) {
	if(pos==n*2+1) {
		for(int i=1;i<=n*2;++i) s[i]=ch[i],mi[i]=b[i];
		return ;
	}
	b[pos]=a.front();
	a.pop_front();
	if(((pos>n&&b[pos]==b[2*n-pos+1])||pos<=n)&&b[pos]<=mi[pos]&&'L'<=s[pos]) {
		ch[pos]='L';
		dfs(pos+1);
	}
	a.push_front(b[pos]);
	b[pos]=a.back();
	a.pop_back();
	if(((pos>n&&b[pos]==b[2*n-pos+1])||pos<=n)&&b[pos]<=mi[pos]&&'R'<=s[pos]) {
		ch[pos]='R';
		dfs(pos+1);
	}
	a.push_back(b[pos]);
}


signed main() {
	
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
//	freopen("palin2.in","r",stdin);
//	freopen("3.out","w",stdout);
	
	
	int T=read();
	while(T--) {
		n=read();
		a.clear();
		for(int i=1;i<=n*2;++i) {
			a.push_back(read());
			mi[i]=0x3f3f3f3f;
			s[i]='Z';
		}
		dfs(1);
		if(mi[1]==0x3f3f3f3f) printf("-1");
		else for(int i=1;i<=n*2;++i) printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
