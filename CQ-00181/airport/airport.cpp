#include<algorithm>
#include<cstdio>
const int maxn=1e5+5;
const int maxm=maxn;
struct plane{
	int l;
	int r;
	friend bool operator<(plane now,plane oth){
		return now.l==oth.l?now.r<oth.r:now.l<oth.l;}
	friend bool operator<=(plane now,plane oth){
		return now<oth||(now.l==oth.l&&now.r==oth.r);}
	friend bool operator!=(plane now,plane oth){
		return now.l!=oth.l||now.r!=oth.r;}
	friend bool operator==(plane now,plane oth){
		return now.l==oth.l&&now.r==oth.r;}
};
struct phs{
	struct node{
		int l;
		int r;
		plane val;
		int key;
		int size;
	}fhq[maxn];
	int cnt,root;
	unsigned long long seed;
	int x,y,z;
	void init(){
		seed=1ull;
		return;
	}
	int newnode(plane val){
		fhq[++cnt].val=val;
		fhq[cnt].size=1;
		fhq[cnt].key=(int)(seed*=20070509);
		return cnt;
	}
	void update(int now){
		fhq[now].size=fhq[fhq[now].l].size+fhq[fhq[now].r].size+1;
		return;
	}
	void split(int now,plane val,int &x,int &y){
		if(!now)x=y=0;
		else{
			if(fhq[now].val<=val){
				x=now;
				split(fhq[now].r,val,fhq[now].r,y);
			}
			else{
				y=now;
				split(fhq[now].l,val,x,fhq[now].l);
			}
			update(now);
		}
		return;
	}
	int merge(int x,int y){
		if(!x||!y)return x+y;
		if(fhq[x].key>fhq[y].key){
			fhq[x].r=merge(fhq[x].r,y);
			update(x);
			return x;
		}
		else{
			fhq[y].l=merge(x,fhq[y].l);
			update(y);
			return y;
		}
		return -1;
	}
	void ins(plane val){
		split(root,val,x,y);
		root=merge(x,merge(newnode(val),y));
		return;
	}
	void del(plane val){
		split(root,val,x,z);
		split(x,(plane){val.l,val.r-1},x,y);
		y=merge(fhq[y].l,fhq[y].r);
		root=merge(x,merge(y,z));
		return;
	}
	plane qmin(){
		int now=root;
		while(fhq[now].l)now=fhq[now].l;
		return fhq[now].val;
	}
	plane qmax(){
		int now=root;
		while(fhq[now].r)now=fhq[now].r;
		return fhq[now].val;
	}
	plane nxt(plane val){
		split(root,(plane){val.r,val.r},x,y);
		int now=y;
		while(fhq[now].l)now=fhq[now].l;
		plane ret=fhq[now].val;
		root=merge(x,y);
		return ret;
	}
}ltr,rtr;
int k,n,m;
int ltot[maxn],rtot[maxm];
void go(int wz){
	int ans=0;
	if(ltr.fhq[ltr.root].size){
		plane lef=ltr.qmin();
		ans=1;
		while(true){
			plane nx=ltr.nxt(lef);
			ltr.del(lef);
			if(!nx.l)break;
			ans++;
			lef=nx;
		}
	}
	ltot[wz]=ltot[wz-1]+ans;
	ans=0;
	if(rtr.fhq[rtr.root].size){
		plane rig=rtr.qmin();
		ans=1;
		while(true){
			plane nx=rtr.nxt(rig);
			rtr.del(rig);
			if(!nx.r)break;
			ans++;
			rig=nx;
		}
	}
	rtot[wz]=rtot[wz-1]+ans;
	return;
}
signed main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&k,&n,&m);
	ltr.init(),rtr.init();
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ltr.ins((plane){x,y});
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		rtr.ins((plane){x,y});
	}
	for(int i=1;i<=k;i++)go(i);
	int ans=0;
	for(int i=0;i<=k;i++)ans=std::max(ans,ltot[i]+rtot[k-i]);
	printf("%d",ans);
	return 0;
}
/*
I've done my best.
*/
