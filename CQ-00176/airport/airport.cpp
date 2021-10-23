// MDR±£””£¨M99±£””£¨Ô±µ∂±£””£¨ayame±£””£¨ø‰∏Á±£”” 
#include<bits/stdc++.h>
using namespace std;
int p1=1000000,p2=0;
char buf[1000005],wb[1000005];
int gc(){
	if(p1==1000000)fread(buf,1,1000000,stdin),p1=0;
	return buf[p1++];
}
#define gc getchar
#define Loli true
long long getint(){
	long long ret=0;
	int c=gc();
	bool flg=0;
	while(c<48||c>57)flg=c=='-',c=gc();
	while(c>=48&&c<=57)ret=(ret<<3)+(ret<<1)+(c^48),c=gc();
	return flg?-ret:ret;
}
void pc(int x){
	if(p2==1000000)fwrite(wb,1,1000000,stdout),p2=0;
	wb[p2++]=x;
}
void wrt(long long x){
	if(x==0)pc(48);
	if(x<0)pc('-'),x=-x;
	int c[32]={0};
	while(x)c[++c[0]]=x%10,x/=10;
	while(c[0])pc(c[c[0]--]^48);
}
long long base=(1ll<<32)-1;
int n,m1,m2;
struct node{
	int l,r;
	bool operator <(const node b)const{return l<b.l;}
}p[100005];
int num1[100005],num2[100005],ans;
int sum1[100005],sum2[100005];
set< long long > s;
int solve(){
	if(!s.size())return 0;
	long long st=*s.begin();
	int ret=0;
	while(s.lower_bound((st&base)<<32)!=s.end()){
		s.erase(st),st=*s.lower_bound((st&base)<<32),++ret;
	}
	s.erase(st),++ret;
	return ret;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
//	n=getint(),m1=getint(),m2=getint();
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&p[i].l,&p[i].r);
//		p[i].l=getint(),p[i].r=getint();
		s.insert( (p[i].l+0ll)<<32|p[i].r );
	}
	for(int i=1;i<=n;i++)
		num1[i]=num1[i-1]+solve();
	while(s.size())s.erase(s.begin());
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&p[i].l,&p[i].r);
//		p[i].l=getint(),p[i].r=getint();
		s.insert( (p[i].l+0ll)<<32|p[i].r );
	}
	for(int i=1;i<=n;i++)
		num2[i]=num2[i-1]+solve();
	for(int i=0;i<=n;i++){
		ans=max(ans,num1[i]+num2[n-i]);
	}
	cout<<ans<<'\n';
//	fwrite(wb,1,p2,stdout);
	return 0;
}
