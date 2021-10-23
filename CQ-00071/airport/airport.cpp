#include<bits/stdc++.h>
using namespace std;
struct node{
	int t;
	bool ca1;int i;bool ca2;
}ls[200005];
int tot,cnt;
bool cmp(node x,node y){return x.t<y.t;}

struct node2{
	int ar,lv;
}tim[2][100005];
bool cmp2(node2 x,node2 y){return x.ar<y.ar;}

int n,m[2];
int chafen[2][100005];
int lsttim[100005];

int tree[600005];
int maxn=0x7f7f7f7f;
void add(int i,int l,int r,int pos,int d){
	if(l==r) {tree[i]=d;return;}
	int mid=(l+r)>>1;
	if(pos<=mid) add(i*2,l,mid,pos,d);
	if(pos>mid) add(i*2+1,mid+1,r,pos,d);
	tree[i]=min(tree[i*2],tree[i*2+1]);
}
int find(int i,int l,int r,int pos){
	if(r<=pos) return tree[i];
	int mid=(l+r)>>1;
	if(pos<=mid) return find(i*2,l,mid,pos);
	else return min(tree[i*2],find(i*2+1,mid+1,r,pos));	
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m[0]>>m[1];
	for(int i=1;i<=m[0];i++) cin>>tim[0][i].ar>>tim[0][i].lv;
	for(int i=1;i<=m[1];i++) cin>>tim[1][i].ar>>tim[1][i].lv;
	
	for(int i=1;i<=m[0];i++) {
		ls[++tot]=(node){tim[0][i].ar,0,i,0};
		ls[++tot]=(node){tim[0][i].lv,0,i,1};
	}
	
	for(int i=1;i<=m[1];i++){
		ls[++tot]=(node){tim[1][i].ar,1,i,0};
		ls[++tot]=(node){tim[1][i].lv,1,i,1};
	}
	
	sort(ls+1,ls+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		if(ls[i].t!=ls[i-1].t) cnt++;
		if(!ls[i].ca2) tim[ls[i].ca1][ls[i].i].ar=cnt;
		else tim[ls[i].ca1][ls[i].i].lv=cnt;
	}
	
	sort(tim[0]+1,tim[0]+m[0]+1,cmp2);
	sort(tim[1]+1,tim[1]+m[1]+1,cmp2);
	
	for(int j=0;j<=1;j++){
		memset(tree,0x7f,sizeof(tree));
		int top=0;
		for(int i=1;i<=m[j];i++){
			int ans=find(1,1,cnt+1,tim[j][i].ar);
			if(ans==maxn) {
				chafen[j][++top]++;
				lsttim[top]=tim[j][i].lv;
				add(1,1,cnt+1,tim[j][i].lv,top);
			}
			else{
				chafen[j][ans]++;
				add(1,1,cnt+1,lsttim[ans],maxn);
				lsttim[ans]=tim[j][i].lv;
				add(1,1,cnt+1,tim[j][i].lv,ans);
			}
		}
		for(int i=1;i<=n;i++) chafen[j][i]+=chafen[j][i-1];
	}
	
	int ans=0;
	for(int i=0;i<=n;i++) ans=max(ans,chafen[0][i]+chafen[1][n-i]);
	
	cout<<ans;
	
	return 0;
}

