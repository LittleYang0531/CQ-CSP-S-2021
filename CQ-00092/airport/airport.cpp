#include <bits/stdc++.h>
using namespace std;
#define lc (u<<1)
#define rc (u<<1|1)

const int N=2e5+10;

int n,m1,m2;
vector<pair<int,int> >z1,z2;
vector<pair<int,int> >st;
vector<pair<int,int> >::iterator it;
vector<pair<int,pair<int,int> > >g1,g2;
bool flag1[N],flag2[N];
int ans;
int sum1[N],sum2[N];

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}

struct node{
	int l,r;
}p1[N],p2[N];

struct ST{
	struct node{
		int l,r;
		int len;
		int sum;
	}tree[N*4];
	void pushup(int u){tree[u].sum=tree[lc].sum+tree[rc].sum;}
	void build(int u,int l,int r){
		tree[u].l=l;tree[u].r=r;
		tree[u].len=r-l+1;
		tree[u].sum=0;
		if(l==r)return;
		int mid=l+r>>1;
		build(lc,l,mid);build(rc,mid+1,r);
	}
	void ins(int u,int p,int k){
		if(tree[u].l==p&&tree[u].r==p){
			tree[u].sum+=k;
			return;
		}
		int mid=tree[u].l+tree[u].r>>1;
		if(p<=mid)ins(lc,p,k);
		else ins(rc,p,k);
		pushup(u);
	}
	int get(int u){
		if(tree[u].sum==tree[u].len)return -1;
		if(tree[u].l==tree[u].r)return tree[u].l;
		if(tree[lc].sum<tree[lc].len)return get(lc);
		else get(rc);
	}
}T;

void deal1(int l,int r){
	vector<pair<int,int> >f;
	it=upper_bound(st.begin(),st.end(),make_pair(l,r));
	if(it==st.begin()){
		int p=T.get(1);
		if(p==-1)return;
		sum1[p]+=1;
		T.ins(1,p,1);
		st.insert(lower_bound(st.begin(),st.end(),make_pair(r,p)),make_pair(r,p));
	}
	else{
		int len=(it-st.begin())-1;
		for(int i=0;i<=len;++i){
			f.push_back(make_pair(st[i].first,st[i].second));
		}
		for(int i=0;i<f.size();++i){
			T.ins(1,f[i].second,-1);
			st.erase(lower_bound(st.begin(),st.end(),make_pair(f[i].first,f[i].second)));
		}
		int p=T.get(1);
		if(p==-1)return;
		sum1[p]+=1;
		T.ins(1,p,1);
		st.insert(lower_bound(st.begin(),st.end(),make_pair(r,p)),make_pair(r,p));
	}
}

void deal2(int l,int r){
	vector<pair<int,int> >f;
	it=upper_bound(st.begin(),st.end(),make_pair(l,r));
	if(it==st.begin()){
		int p=T.get(1);
		if(p==-1)return;
		sum2[p]+=1;
//		printf("%d\n",p);
		T.ins(1,p,1);
		st.insert(lower_bound(st.begin(),st.end(),make_pair(r,p)),make_pair(r,p));
	}
	else{
		int len=(it-st.begin())-1;
		for(int i=0;i<=len;++i){
			f.push_back(make_pair(st[i].first,st[i].second));
		}
		for(int i=0;i<f.size();++i){
			T.ins(1,f[i].second,-1);
			st.erase(lower_bound(st.begin(),st.end(),make_pair(f[i].first,f[i].second)));
		}
		int p=T.get(1);
		if(p==-1)return;
//		printf("%d\n",p);
		sum2[p]+=1;
		T.ins(1,p,1);
		st.insert(lower_bound(st.begin(),st.end(),make_pair(r,p)),make_pair(r,p));
	}
}

int check1(int t){
	int cnt=0,res=0;
	for(int i=1;i<=m1;++i)flag1[i]=0;
	for(int i=0;i<g1.size();++i){
		int p=g1[i].first,op=g1[i].second.first,id=g1[i].second.second;
		if(op==-1&&flag1[id]){
			--cnt;
		}
		else if(op==1&&cnt<t){
			flag1[id]=1;
			++cnt;
			++res;
		}
	}
	return res;
}

int check2(int t){
	int cnt=0,res=0;
	for(int i=1;i<=m2;++i)flag2[i]=0;
	for(int i=0;i<g2.size();++i){
		int p=g2[i].first,op=g2[i].second.first,id=g2[i].second.second;
		if(op==-1&&flag2[id]){
			--cnt;
		}
		else if(op==1&&cnt<t){
			flag2[id]=1;
			++cnt;
			++res;
		}
	}
	return res;
}

void Main1(){
	for(int i=1;i<=m1;++i){
		p1[i].l=read();p1[i].r=read();
		g1.push_back(make_pair(p1[i].l,make_pair(1,i)));
		g1.push_back(make_pair(p1[i].r,make_pair(-1,i)));
	}
	for(int i=1;i<=m2;++i){
		p2[i].l=read();p2[i].r=read();
		g2.push_back(make_pair(p2[i].l,make_pair(1,i)));
		g2.push_back(make_pair(p2[i].r,make_pair(-1,i)));
	}
	sort(g1.begin(),g1.end());
	sort(g2.begin(),g2.end());
	for(int i=0;i<=n;++i){
//		printf("%d\n",check2(i));
//		printf("%d:%d+%d=%d\n",i,check1(i),check2(n-i),check1(i)+check2(n-i));
		ans=max(ans,check1(i)+check2(n-i));
	}
	printf("%d",ans);
}

void Main2(){
	for(int i=1;i<=m1;++i){
		p1[i].l=read();p1[i].r=read();
		z1.push_back(make_pair(p1[i].l,p1[i].r));
	}
	for(int i=1;i<=m2;++i){
		p2[i].l=read();p2[i].r=read();
		z2.push_back(make_pair(p2[i].l,p2[i].r));
	}
	sort(z1.begin(),z1.end());
	sort(z2.begin(),z2.end());
	st.clear();
	T.build(1,1,n);
	for(int i=0;i<z1.size();++i){
		deal1(z1[i].first,z1[i].second);
	}
	st.clear();
	T.build(1,1,n);
	for(int i=0;i<z2.size();++i){
		deal2(z2[i].first,z2[i].second);
	}
	
	for(int i=1;i<=n;++i)sum1[i]+=sum1[i-1];
	for(int i=1;i<=n;++i)sum2[i]+=sum2[i-1];
	for(int i=0;i<=n;++i)ans=max(ans,sum1[i]+sum2[n-i]);
	printf("%d",ans);
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	n=read();m1=read();m2=read();
	if(n<=5000&&m1+m2<=5000)Main1();
	else Main2();
	return 0;
}
