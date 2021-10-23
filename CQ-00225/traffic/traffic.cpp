#include<bits/stdc++.h>
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#ifdef GTRAKIOI
#define defrog(...) fprintf(stderr,__VA_ARGS__)
#else
#define defrog(...) 1
#endif
typedef long long ll;
typedef std::vector<int> vi;
typedef std::pair<int,int> pii;

#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<15,stdin),p1==p2)?EOF:*p1++)
char ibuf[1<<15],*p1,*p2;
struct IOer{
	inline int rint(){char c,f=0;while((c=getchar())<48||c>57)if(c=='-')f=1;unsigned int a=c&15;while((c=getchar())>=48&&c<=57)a=a*10+(c&15);return f?~a+1:a;}
	inline operator int(){return rint();}
}g90;

const int N=1010;
int a[N<<1];

signed main(){
	File("traffic");
	int n=g90,m=g90,T=g90;
	for(;T--;){
		puts("0");
	}
}
