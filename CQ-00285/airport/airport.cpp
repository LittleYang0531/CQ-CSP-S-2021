#include<bits/stdc++.h>
using namespace std;
int n,na,nb,to,cnt,ans,p,l,r,mid;
int sa[100001],sb[100001],ca[100001],cb[100001],suma[100001],sumb[100001];
bool visa[100001],visb[100001];
pair<int,int> a[100001],b[100001];
priority_queue<int> qua,qub;
void init()
{
	for(int i=1;i<=na;i++)scanf("%d%d",&a[i].first,&a[i].second);sort(a+1,a+1+na);
	for(int i=1;i<=nb;i++)scanf("%d%d",&b[i].first,&b[i].second);sort(b+1,b+1+nb);
}
void dfsa(int k,int fr)
{
	visa[k]=1,ca[fr]++;while(sa[k]>0&&sa[k]<=na&&visa[sa[k]]) sa[k]++;if(sa[k]>0&&sa[k]<=na)dfsa(sa[k],fr);
}
void dfsb(int k,int fr)
{
	visb[k]=1,cb[fr]++;while(sb[k]>0&&sb[k]<=nb&&visb[sb[k]]) sb[k]++;if(sb[k]>0&&sb[k]<=nb)dfsb(sb[k],fr);
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&na,&nb);
if(n<=1000)
{
init();
for(int i=0;i<=n;i++)
{
p=cnt=0,to=i;
for(int j=1;j<=na;j++)
{
	while(!qua.empty()&&-qua.top()<=a[j].first) {
		qua.pop(),cnt--;
	}
	if(cnt<to) {
		qua.push(-a[j].second);
		cnt++,p++;
	}
}
cnt=0,to=n-i;
for(int j=1;j<=nb;j++)
{
	while(!qub.empty()&&-qub.top()<=b[j].first) {
		qub.pop(),cnt--;
	}
	if(cnt<to) {
		qub.push(-b[j].second);
		cnt++,p++;
	}
}
ans=max(ans,p);
}
printf("%d",ans);
return 0;
}
else
{
init();
for(int i=1;i<=na;i++)
{
l=0,r=na+1;
while(l+1<r)
{
	mid=l+r>>1;
	if(a[mid].first>a[i].second) r=mid;
	else l=mid;
}
mid=l+r>>1;if(a[mid].first<a[i].second) mid++;
sa[i]=mid;
}
for(int i=1;i<=nb;i++)
{
l=0,r=nb+1;
while(l+1<r)
{
	mid=l+r>>1;
	if(b[mid].first>b[i].second) r=mid;
	else l=mid;
}
mid=l+r>>1;if(b[mid].first<b[i].second) mid++;
sb[i]=mid;
}
for(int i=1;i<=na;i++)if(!visa[i]) dfsa(i,i);
for(int i=1;i<=nb;i++)if(!visb[i]) dfsb(i,i);
for(int i=1;i<=na;i++)suma[i]=suma[i-1]+ca[i];
for(int i=1;i<=nb;i++)sumb[i]=sumb[i-1]+cb[i];
for(int i=0;i<=n;i++)
{
	p=suma[i]+sumb[n-i];
	ans=max(ans,p);
}
printf("%d",ans);
return 0;
}
return 0;
}
