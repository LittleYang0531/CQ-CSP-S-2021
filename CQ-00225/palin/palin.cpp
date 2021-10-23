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
	File("palin");
	for(int T=g90;T--;){
		int n=g90;
		for(int i=1;i<=n*2;i++)a[i]=g90;
		
		std::string ans;
		int ok=1;
		for(int i=1;i<=n;++i)if(a[i]!=a[2*n+1-i])ok=0;
		for(int i=1;i<=2*n;i++)ans+='R';
		if(ok){
			for(int i=0;i<2*n;i++)ans[i]='L';
		}else{
			int ok2=0;
			std::string tmp;
			for(int i=1;i<=2*n;i++)tmp+='R';
			for(int mid=1;mid<2*n;++mid){
				int pos00=1,pos01=mid,pos10=2*n,pos11=mid+1;
				for(int i=1;i<=n;++i){
					if(pos00<=pos01&&pos11<=pos10&&a[pos00]==a[pos11])tmp[i-1]='L',tmp[2*n-i]='R',pos00++,pos11++;
					else if(pos00<pos01&&a[pos00]==a[pos01])tmp[i-1]='L',tmp[2*n-i]='L',pos00++,pos01--;
					else if(pos00<=pos01&&pos11<=pos10&&a[pos10]==a[pos01])tmp[i-1]='R',tmp[2*n-i]='L',pos10--,pos01--;
					else if(pos11<pos10&&a[pos10]==a[pos11])tmp[i-1]='R',tmp[2*n-i]='R',pos10--,pos11++;
					else goto nxt_loop;
				}
				ok2=1;
				if(tmp<ans)ans=tmp;
				nxt_loop:;
			}
			if(!ok2){
				puts("-1");
				continue;
			}
		}
//		std::cerr<<ans<<'\n';
		std::cout<<ans<<'\n';
	}
}
