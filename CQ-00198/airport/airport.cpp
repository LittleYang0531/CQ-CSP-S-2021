#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXN 200005
template<typename _T>
void read(_T &x){
	_T f=1;x=0;char s=getchar();
	while('0'>s||s>'9'){if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x*=f;
}
int n,m1,m2,dif1[MAXN],dif2[MAXN],val1[MAXN],val2[MAXN],tot;
int sum1[MAXN],sum2[MAXN],ans;
struct ming{int a,b;}s1[MAXN],s2[MAXN];
struct tann{int t,opt,id;}s[MAXN];
priority_queue<int,vector<int>,greater<int> >q;
bool cmp(tann x,tann y){return x.t<y.t;}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n);read(m1);read(m2);
	for(int i=1;i<=m1;i++)read(s1[i].a),read(s1[i].b);
	for(int i=1;i<=m2;i++)read(s2[i].a),read(s2[i].b);
	for(int i=1;i<=m1;i++)q.push(i);
	for(int i=1;i<=m1;i++)s[++tot]=(tann){s1[i].a,1,i},s[++tot]=(tann){s1[i].b,0,i};
	sort(s+1,s+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		if(s[i].opt==1)
			val1[s[i].id]=q.top(),q.pop(),dif1[val1[s[i].id]]++;
		else q.push(val1[s[i].id]);
	}
	//for(int i=1;i<=m1;i++)printf("inside %d value %d\n",i,val1[i]);
	for(int i=1;i<=n;i++)sum1[i]=sum1[i-1]+dif1[i];
	while(!q.empty())q.pop();
	for(int i=1;i<=m2;i++)q.push(i);tot=0;
	for(int i=1;i<=m2;i++)s[++tot]=(tann){s2[i].a,1,i},s[++tot]=(tann){s2[i].b,0,i};
	sort(s+1,s+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		if(s[i].opt==1)
			val2[s[i].id]=q.top(),q.pop(),dif2[val2[s[i].id]]++;
		else q.push(val2[s[i].id]);
	}
	for(int i=1;i<=n;i++)sum2[i]=sum2[i-1]+dif2[i];
	for(int i=0;i<=n;i++)ans=max(sum1[i]+sum2[n-i],ans);
	printf("%d\n",ans);
	return 0;
}
