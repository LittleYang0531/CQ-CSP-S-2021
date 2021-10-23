//21!9-324@emb
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

const int N=100100;
int m[3];
int&m1=m[1];
int&m2=m[2];
int f[3][N],res[3][N];
struct Item{
	int val,id,type;
	inline int operator<(const Item&_)const{return val<_.val;}
}q[3][N];

signed main(){
	File("airport");
	int n=g90;
	m1=g90,m2=g90;
	for(int i=1;i<=m1;++i){
		int a=g90,b=g90;
		q[1][2*i-1].val=a,q[1][2*i-1].id=i,q[1][2*i-1].type=0,
		q[1][2*i].val=b,q[1][2*i].id=i,q[1][2*i].type=1;
	}
	for(int i=1;i<=m2;++i){
		int a=g90,b=g90;
		q[2][2*i-1].val=a,q[2][2*i-1].id=i,q[2][2*i-1].type=0,
		q[2][2*i].val=b,q[2][2*i].id=i,q[2][2*i].type=1;
	}
	
	auto solve=[&](int k){
		std::sort(q[k]+1,q[k]+2*m[k]+1);
		
		std::set<int>st;
//		std::priority_queue<int,vi,std::greater<int> >hp;
		for(int i=1;i<=m[k];i++)st.insert(i);
		for(int i=1;i<=2*m[k];++i){
			if(q[k][i].type){//pop
				st.insert(f[k][q[k][i].id]);
			}else{//push
				auto it=st.begin();
				f[k][q[k][i].id]=*it;
				st.erase(it);
			}
		}
		
		for(int i=1;i<=m[k];++i){
			++res[k][f[k][i]];
		}
		for(int i=1;i<=m[k];++i){
			res[k][i]+=res[k][i-1];
		}
		for(int i=m[k]+1;i<=n;++i)res[k][i]=res[k][m[k]];
	};
	solve(1);
	solve(2);
	
	int ans=0;
	for(int i=0;i<=n;i++)if(i<=m1&&n-i<=m2){
		ans=std::max(ans,res[1][i]+res[2][n-i]);
	}
	printf("%d\n",ans);
	return 0;
}
