//Last farewell...
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define aln(x,l,r) (x)+(l),(x)+(r)+1
#define Sz(x) ((int)(x).size())
#define fir(x) (x).first
#define sec(x) (x).second
typedef std::pair<int,int> deux;
#define Mp std::make_pair
template<class T> inline void Cmin(T& x,const T y){x = x < y ? x : y;}
template<class T> inline void Cmax(T& x,const T y){x = x < y ? y : x;}
template<class T> inline std::vector<T> ils(T* s,T* t){std::vector<T> res; for(; s!=t; s++) res.emplace_back(*s); return res;}
template<class T> inline void rd(T& x)
{
	x=0; char ch=getchar(); bool f=0;
	while(ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+(ch&15),ch=getchar();
	f && (x=-x);
}
struct pal{
	int l,r;
}a[100100],b[100100];
int n,ma,mb;
struct pnt{
	int x,f,i;
}pa[200100],pb[200100];
int sa[400100],sb[400100],res;
int tag[400100];
inline void Prog(int A,int B)
{
	int rs=0;
	for(int i=1,rE=ma*2; i<=rE; ++i)
	{
		if(pa[i].f==1)
			{if(A) A--,rs++,tag[pa[i].x]=1;}
		else {if(tag[a[pa[i].i].l]) A++,tag[a[pa[i].i].l]=0;}
	}
	for(int i=1,rE=mb*2; i<=rE; ++i)
	{
		if(pb[i].f==1)
			{if(B) B--,rs++,tag[pb[i].x]=1;}
		else {if(tag[b[pb[i].i].l]) B++,tag[b[pb[i].i].l]=0;}
	} Cmax(res,rs);
}
inline void AllLast()
{
	std::vector<int> fs(n+1);
	for(int i=0; i<=n; ++i) fs[i]=i;
	int sz=std::sqrt(fs.size())+1;
	std::mt19937 ra(std::chrono::steady_clock::now().time_since_epoch().count());
	std::shuffle(all(fs),ra);
	for(int i=0; i<sz; ++i) Prog(fs[i],n-fs[i]);
	printf("%d\n",res);
}
signed main()
{
	std::freopen("airport.in","r",stdin);
	std::freopen("airport.out","w",stdout);
	rd(n); rd(ma); rd(mb);
	std::vector<int> dsc;
	for(int i=1; i<=ma; ++i) rd(a[i].l),rd(a[i].r);
	for(int i=1; i<=mb; ++i) rd(b[i].l),rd(b[i].r);
	for(int i=1; i<=ma; ++i) dsc.emplace_back(a[i].l),dsc.emplace_back(a[i].r);
	for(int i=1; i<=mb; ++i) dsc.emplace_back(b[i].l),dsc.emplace_back(b[i].r);
	auto Gid=[&](const int x){return std::lower_bound(dsc.begin(),dsc.end(),x)-dsc.begin()+1;};
	std::sort(all(dsc)),dsc.erase(std::unique(all(dsc)),dsc.end());
	for(int i=1; i<=ma; ++i) a[i].l=Gid(a[i].l),a[i].r=Gid(a[i].r);
	for(int i=1; i<=mb; ++i) b[i].l=Gid(b[i].l),b[i].r=Gid(b[i].r);
	int rn=static_cast<int>(dsc.size());
	for(int i=1; i<=ma; ++i) pa[i]=(pnt){a[i].l,1,i},pa[ma+i]=(pnt){a[i].r,-1,i};
	for(int i=1; i<=mb; ++i) pb[i]=(pnt){b[i].l,1,i},pb[mb+i]=(pnt){b[i].r,-1,i};
//	for(int i=1; i<=ma; ++i) printf(" (%d %d)\n",a[i].l,a[i].r); puts("");
//	for(int i=1; i<=mb; ++i) printf(" (%d %d)\n",b[i].l,b[i].r);
	std::sort(aln(pa,1,ma*2),[](const pnt&a,const pnt&b){return a.x<b.x||(a.x==b.x&&a.f<b.f);});
	std::sort(aln(pb,1,mb*2),[](const pnt&a,const pnt&b){return a.x<b.x||(a.x==b.x&&a.f<b.f);});
//#ifndef DEBUG
	if(n<=5000)
	{
		for(int i=0; i<=n; ++i) Prog(i,n-i);
		return printf("%d\n",res),0;
	}
//#endif
//#ifndef DEBUG
	else
//#endif // DEBUG
	{
		return AllLast(),0;
		for(int i=1; i<=ma; ++i) sa[a[i].l]++,sa[a[i].r+1]--;
		for(int i=1; i<=mb; ++i) sb[b[i].l]++,sb[b[i].r+1]--;
		for(int i=1; i<=rn+1; ++i) sa[i]+=sa[i-1],sb[i]+=sb[i-1];
//		for(int i=1; i<=rn+1; ++i) printf(" %d",sa[i]); puts("");
//		for(int i=1; i<=rn+1; ++i) printf(" %d",sb[i]); puts("");
		std::vector<int> va,vb;
		for(int i=1; i<=ma*2; ++i) if(pa[i].f==1) va.emplace_back(sa[pa[i].x]);
		for(int i=1; i<=mb*2; ++i) if(pb[i].f==1) vb.emplace_back(sb[pb[i].x]);
		std::vector<deux> da,db;
		std::sort(all(va)),std::sort(all(vb));
		for(int i=0; i<Sz(va); ++i)
		{
			if(i==0) da.emplace_back(va[i],1);
			else
			{
				if(va[i]==va[i-1]) sec(da.back())++;
				else da.emplace_back(va[i],1);
			}
		}
		for(int i=0; i<Sz(vb); ++i)
		{
			if(i==0) db.emplace_back(vb[i],1);
			else
			{
				if(vb[i]==vb[i-1]) sec(db.back())++;
				else db.emplace_back(vb[i],1);
			}
		}
//		for(int i:va) printf(" (%d)",i); puts("");
//		for(int i:vb) printf(" (%d)",i); puts("");
//		sega.init(va),segb.init(vb);
//		sega.de(),segb.de();
		da.insert(da.begin(),(deux){0,0}),da.insert(da.end(),(deux){(int)1e9,0});
		db.insert(db.begin(),(deux){0,0}),db.insert(db.end(),(deux){(int)1e9,0});
		std::vector<int> pda(da.size()),pdb(db.size()),tmpa,tmpb;
		for(deux i:da) tmpa.emplace_back(sec(i));
		for(deux i:db) tmpb.emplace_back(sec(i));
		std::partial_sum(all(tmpa),pda.begin());
		std::partial_sum(all(tmpb),pdb.begin());
//		for(auto i:da) printf("{%d %d} ",fir(i),sec(i)); puts("");
//		for(auto i:db) printf("{%d %d} ",fir(i),sec(i)); puts("");
//		for(int i:pda) printf(" (%d)",i); puts("");
//		for(int i:pdb) printf(" (%d)",i); puts("");
		auto Yidhra=[&](int A,int B)
		{
			int poa=std::lower_bound(all(da),(deux){A+1,0})-da.begin()+1;
			int pob=std::lower_bound(all(db),(deux){B+1,0})-db.begin()+1;
			poa-=2,pob-=2; int tp=0;
			tp+=pda[poa]+pdb[pob];
			Cmax(res,tp);
//			printf("pos: [%d %d] A: %d B: %d res: %d\n",poa,pob,A,B,res);
		};
		for(int i=0; i<=n; ++i) Yidhra(i,n-i);
		return printf("%d\n",res),0;
	}
	return 0;
}
