#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int t=0;char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
struct node{
	int x,y;
	bool operator <(const node A)const{return x==A.x?y<A.y:x<A.x;}
};
set<node>S;
set<node>::iterator it,it1;
int f1[100002],f2[100002],n,m1,m2,ans;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1,x,y;i<=m1;++i)x=read(),y=read(),S.insert((node){x,y});
	int s=0;
	for(int i=1;i<=n;++i){
		it=S.begin();
		while(it!=S.end()){
			it1=S.lower_bound((node){(*it).y,0});
			S.erase(it),it=it1,++s;
		}
		f1[i]=s;
	}
	S.clear();
	for(int i=1,x,y;i<=m2;++i)x=read(),y=read(),S.insert((node){x,y});
	s=0;
	for(int i=1;i<=n;++i){
		it=S.begin();
		while(it!=S.end()){
			it1=S.lower_bound((node){(*it).y,0});
			S.erase(it),it=it1,++s;
		}
		f2[i]=s;
	}
	for(int i=0;i<=n;++i)ans=max(ans,f1[i]+f2[n-i]);
	printf("%d",ans);
}

