#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct data{
	int beg,end;
};
data m1[maxn],m2[maxn];
bool cmp(data a,data b){
	return a.beg<b.beg;
}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int s1[maxn],s2[maxn];
long long ans;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n=read(),am=read(),bm=read();
	for(int i=1;i<=am;++i) m1[i].beg=read(),m1[i].end=read();
	for(int i=1;i<=bm;++i) m2[i].beg=read(),m2[i].end=read();
	sort(m1+1,m1+1+am,cmp),sort(m2+1,m2+1+bm,cmp);
	   for(int cnt=0;cnt<=n;++cnt){
	    long long anss=0;
		for(int i=1;i<=max(am,bm);++i){
		 for(int j=1;j<=cnt&&i<=am;++j){
			if(m1[s1[j]].end<m1[i].beg){
				s1[j]=i;
				anss++;
				break;
			}
		}
		for(int j=1;j<=n-cnt&&i<=bm;++j){
			if(m2[s2[j]].end<m2[i].beg){
				s2[j]=i;
				anss++;
				break;
			}
		 }
		}
		ans=max(ans,anss);
		for(int i=1;i<=cnt;++i) s1[i]=0,s2[i]=0;
    }
   cout<<ans;
}
