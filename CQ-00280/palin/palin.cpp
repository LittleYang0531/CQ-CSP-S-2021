#include<bits/stdc++.h>
using namespace std;
inline int Rd() {
	int s=0; char fl=0,c=getchar();
	while(c<'0'||c>'9') fl|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return fl?-s:s;
}

const int N=2e5+5;

int n,a[N<<1],pos[N<<1],bj[N<<1],vit[N];

int p1[2],p2[2],ans[N<<1];

inline int Try(int s) {
	int t=pos[s]; bj[s]=bj[t]=1;
	
	if(s==1) p1[0]=2,p1[1]=(n<<1),ans[1]=0;
	else p1[0]=1,p1[1]=(n<<1)-1,ans[1]=1;
	p2[0]=t-1,p2[1]=t+1,ans[n<<1]=0;
	
	for(t=2; t<=n; ++t) {
		int o1=2,o2=2;
//		cout<<"t="<<t<<'\n';
//		cout<<p1[0]<<' '<<p1[1]<<' '<<p2[0]<<' '<<p2[1]<<'\n';
//		cout<<a[p1[0]]<<' '<<a[p1[1]]<<' '<<a[p2[0]]<<' '<<a[p2[1]]<<'\n';
//		cout<<bj[p1[0]]<<' '<<bj[p1[1]]<<' '<<bj[p2[0]]<<' '<<bj[p2[1]]<<'\n';
		
		for(int i=0; i<2; ++i) 
		for(int j=0; j<2; ++j) 
			if(!bj[p1[i]]&&!bj[p2[j]]&&p1[i]!=p2[j]&&a[p1[i]]==a[p2[j]]&&i<o1) 
				o1=i,o2=j;
		
		if(o1==2) return 0;
		
//		cout<<p1[o1]<<' '<<p2[o2]<<'\n';
		
		bj[p1[o1]]=bj[p2[o2]]=1;
		
		if(!o1) p1[1]-=(p1[1]==p2[o2]); else p1[0]+=(p1[0]==p2[o2]);
		if(!o2) p2[1]+=(p2[1]==p1[o1]); else p2[0]-=(p2[0]==p1[o1]);
		
		if(!o1) ans[t]=0,++p1[0]; else ans[t]=1,--p1[1];
		if(!o2) ans[(n<<1)+1-t]=0,--p2[0];
		else ans[(n<<1)+1-t]=1,++p2[o2];
//		putchar(ans[t]?'R':'L'); puts("");
	}
	return 1;
}

int st[2];

inline void Solve() {
	n=Rd();
	for(int i=1; i<=n; ++i) vit[i]=0;
	for(int i=1; i<=(n<<1); ++i) {
		int v=a[i]=Rd();
		if(!vit[v]) vit[v]=i;
		else pos[i]=vit[v],pos[vit[v]]=i;
	}
	st[0]=1,st[1]=(n<<1);
	
	for(int j=0; j<2; ++j) {
		for(int i=1; i<=(n<<1); ++i) bj[i]=0;
		bj[0]=bj[(n<<1)+1]=1;
		
		int fl=Try(st[j]);
		if(fl) {
			for(int i=1; i<=(n<<1); ++i) putchar(ans[i]?'R':'L');
			putchar('\n'); return;
		}
	}
	puts("-1");
}


int main() {
//	system("fc palin.out palin2.ans");
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=Rd();
	while(T--) Solve();	
	return 0;
}

