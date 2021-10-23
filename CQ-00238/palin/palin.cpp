#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int T,n,p[N],a[N][2],V[N],p2[N],d[N];
inline int read() {
	int f=0,s=0;
	char ch=getchar();
	while(ch<48||ch>57)f|=(ch=='-'),ch=getchar();
	while(ch>47&&ch<58)s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return f?-s:s;
}
bool Solve(int bj) {
	int num=0;
	for(int i=1; i<=n; ++i)V[i]=0;
	for(int i=1; i<=2*n; ++i)d[i]=0;
	int s1,s2,e1,e2;
	if(bj==0) {
		s1=2,s2=2*n,e1=a[p[1]][1]-1,e2=a[p[1]][1]+1;
		d[++num]=0,V[1]=V[a[p[1]][1]]=1;
	} else {
		s1=1,s2=2*n-1,e1=a[p[2*n]][0]-1,e2=a[p[2*n]][0]+1;
		d[++num]=1,V[2*n]=V[a[p[2*n]][0]]=1;
	}
	for(int i=2; i<=n; ++i) {
		if(!V[s1]&&!V[e1]&&p[s1]==p[e1]){d[2*n-num]=0,d[++num]=0,V[s1]=V[e1]=1,++s1,--e1;continue;}
		if(!V[s1]&&!V[e2]&&p[s1]==p[e2]){d[2*n-num]=1,d[++num]=0,V[s1]=V[e2]=1,++s1,++e2;continue;}
		if(!V[s2]&&!V[e1]&&p[s2]==p[e1]){d[2*n-num]=0,d[++num]=1,V[s2]=V[e1]=1,--s2,--e1;continue;}
		if(!V[s2]&&!V[e2]&&p[s2]==p[e2]){d[2*n-num]=1,d[++num]=1,V[s2]=V[e2]=1,--s2,++e2;continue;}
		return false;
	}
	for(int i=1; i<=2*n; ++i)putchar(d[i]==0?'L':'R');
	puts("");
	return true;
}
void Work() {
	n=read();
	for(int i=1; i<=n; ++i)a[i][0]=a[i][1]=0;
	for(int i=1; i<=2*n; ++i) {
		p[i]=read();
		if(!a[p[i]][0])a[p[i]][0]=i;
		else a[p[i]][1]=i;
	}
	if(Solve(0))return;
	if(Solve(1))return;
	puts("-1");
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)Work();
	return 0;
}
