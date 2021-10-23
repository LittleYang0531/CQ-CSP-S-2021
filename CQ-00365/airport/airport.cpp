#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int>P; 
const int N=333333;
int n,m1,m2,lsh[N],cnt,m,a,b,x,y,tot1[N],tot2[N],ans;
P u[N],v[N];
struct Tree{
	int ans;
	int lazy_tag;
}node[2][N<<2];
void Add(int k,int l,int r,int num,int typ){
	node[typ][k].ans+=num*(r-l+1);
	node[typ][k].lazy_tag+=num;
}
void push_down(int k,int l,int r,int typ){
	if(!node[typ][k].lazy_tag)return;
	int mid=(l+r)>>1,res=node[typ][k].lazy_tag;
	Add(k<<1,l,mid,res,typ);
	Add(k<<1|1,mid+1,r,res,typ);
	node[typ][k].lazy_tag=0;
}
void add_data(int k,int l_now,int r_now,int l,int r,int num,int typ){
	//cout<<k<<':'<<l_now<<' '<<r_now<<'='<<node[typ][k].ans<<endl;
	if(l_now>r_now)return;
	if(l<=l_now&&r_now<=r)return Add(k,l_now,r_now,num,typ);
	push_down(k,l_now,r_now,typ);
	int mid=(l_now+r_now)>>1;
	if(l<=mid)add_data(k<<1,l_now,mid,l,r,num,typ);
	if(mid<r)add_data(k<<1|1,mid+1,r_now,l,r,num,typ);
	node[typ][k].ans=node[typ][k<<1].ans+node[typ][k<<1|1].ans;
}
int ask_data(int k,int l_now,int r_now,int l,int r,int typ){
	//cout<<k<<':'<<l_now<<' '<<r_now<<'='<<node[typ][k].ans<<endl;
	if(l_now>r_now)return 0;
	if(l<=l_now&&r_now<=r)return node[typ][k].ans;
	push_down(k,l_now,r_now,typ);
	int mid=(l_now+r_now)>>1,res=0;
	if(l<=mid)res+=ask_data(k<<1,l_now,mid,l,r,typ);
	if(mid<r)res+=ask_data(k<<1|1,mid+1,r_now,l,r,typ);
	return res;
}
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch^48);
		ch=getchar();
	}
	x*=f;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n);read(m1);read(m2);
	for(int i=1;i<=m1;++i){
		read(u[i].first);read(u[i].second);
		//if(u[i].first>u[i].second)swap(u[i].first,u[i].second);
		--u[i].second;
		++cnt;lsh[cnt]=u[i].first;
		++cnt;lsh[cnt]=u[i].second;
	}
	sort(u+1,u+m1+1);
	for(int i=1;i<=m2;++i){
		read(v[i].first);read(v[i].second);
		//if(v[i].first>v[i].second)swap(v[i].first,v[i].second);
		--v[i].second;
		++cnt;lsh[cnt]=v[i].first;
		++cnt;lsh[cnt]=v[i].second;
	}
	sort(v+1,v+m2+1);
	sort(lsh+1,lsh+cnt+1);
	cnt=unique(lsh+1,lsh+cnt+1)-lsh-1;
//	cout<<cnt<<endl;
	m=lsh[cnt];x=n;y=0;
	while(x){
		int ans_res=0;
		memset(node,0,sizeof node);
		if(x)
		for(int i=1;i<=m1;++i){
	//		read(a);read(b);
			a=lower_bound(lsh+1,lsh+cnt+1,u[i].first)-lsh;
			b=lower_bound(lsh+1,lsh+cnt+1,u[i].second)-lsh;
			a=lsh[a];b=lsh[b];
	//		cout<<a<<' '<<b<<endl;
			int rp=ask_data(1,1,cnt,a,a,0);
			if(rp>=x)continue;
			add_data(1,1,cnt,a,b,1,0);
			++ans_res;
//			cout<<a<<' '<<b<<' '<<rp<<endl;
		}
		//cout<<'a'<<ans_res<<endl;
		if(y)
		for(int i=1;i<=m2;++i){
	//		read(a);read(b);
			a=lower_bound(lsh+1,lsh+cnt+1,v[i].first)-lsh;
			b=lower_bound(lsh+1,lsh+cnt+1,v[i].second)-lsh;
			a=lsh[a];b=lsh[b];
//			cout<<a<<' '<<b<<endl;
			int rp=ask_data(1,1,cnt,a,a,1);
			if(rp>=y)continue;
			add_data(1,1,cnt,a,b,1,1);
			++ans_res;
//			cout<<a<<' '<<b<<' '<<rp<<endl;
		}
		//cout<<ans_res<<endl;
		--x;++y;
		ans=max(ans,ans_res);
	}
	printf("%d\n",ans);
/*	for(int i=1;i<=m1;++i)cout<<tot1[i]<<' ';
	cout<<endl;
	for(int i=1;i<=m2;++i)cout<<tot2[i]<<' ';
	cout<<endl;*/
	return 0;
}
