#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct jjy{
	int a,b;
	bool operator < (const jjy& c)const{
		return a==c.a ? (b<c.b) : a<c.a; 
	}
};

jjy gn[100005],gw[100005];
jjy zy[100005];
int main(){
	ios::sync_with_stdio(0);
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)gn[i].a=read(),gn[i].b=read();
	for(int i=1;i<=m2;i++)gw[i].a=read(),gw[i].b=read();
	sort(gn+1,gn+1+m1);
	sort(gw+1,gw+1+m2);
	int ans=0;
	for(int i=0;i<=n;i++){
		int gnn=i,gww=n-i;
		memset(zy,0,sizeof(zy));
		//zy.clear();
		int s=0;
		for(int j=1;j<=m1;j++){
			for(int k=1;k<=gnn;k++){
				if(zy[k].b<gn[j].a){
					zy[k]=gn[j];
					s++;
					break;
				}
			}
		}
		memset(zy,0,sizeof(zy));
		for(int j=1;j<=m2;j++){
			for(int k=1;k<=gww;k++){
				if(zy[k].b<gw[j].a){
					zy[k]=gw[j];
					s++;
					break;
				}
			}
		}
		if(s>ans)ans=s;
	}
	cout<<ans<<'\n';
	return 0;
}
