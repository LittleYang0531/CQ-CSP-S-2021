#include<bits/stdc++.h>
using namespace std;
const long long MAX_N=100000+5;
long long n,m1,m2,n1,n2;
struct air{
	long long in,out;
}a[MAX_N],b[MAX_N];
long long q1[MAX_N],q2[MAX_N];
long long ans=-INT_MAX,tot1,tot2;
bool cmp(air x,air y)
{
	return x.in<y.in;
}
bool cmp1(long long x,long long y)
{
	if(a[x].out<a[y].out) return true;
	return false;
}
bool cmp2(long long x,long long y)
{
	if(b[x].out<b[y].out) return true;
	return false;
}
void home()
{
	long long h=1,t=1,len=0;
	if(n1==0) return;
	for(long long i=1;i<=m1;i++){
		if(len==n1&&a[q1[h]].out>a[i].in) continue;
		while(len!=0&&a[q1[h]].out<=a[i].in){
			t--;
			len--;
			tot1++;
		}
		q1[t++]=i;
		len++;
		sort(q1+1,q1+len+1,cmp1);
//		for(int i=1;i<=len;i++){
//			cout<<a[q1[i]].in<<" "<<a[q1[i]].out<<endl;
//		}
//		cout<<endl;
	}
	tot1+=len;
}
void abroad()
{
	long long h=1,t=1,len=0;
	if(n2==0) return;
	for(long long i=1;i<=m2;i++){
		if(len==n2&&b[q2[h]].out>b[i].in) continue;
		while(len!=0&&b[q2[h]].out<=b[i].in){
			t--;
			len--;
			tot2++;
		}
		q2[t++]=i;
		len++;
		sort(q2+1,q2+len+1,cmp2);
	}
	tot2+=len;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for(long long i=1;i<=m1;i++){
		scanf("%lld%lld",&a[i].in,&a[i].out);
	}
	for(long long i=1;i<=m2;i++){
		scanf("%lld%lld",&b[i].in,&b[i].out);
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
//	cout<<endl;
//	for(int i=1;i<=m1;i++){
//		cout<<a[i].in<<" "<<a[i].out<<endl;
//	}
//	for(int i=1;i<=m2;i++){
//		cout<<b[i].in<<" "<<b[i].out<<endl;
//	}
	for(long long i=0;i<=n;i++){
		n1=i;
		n2=n-i;
		home();
		abroad();
		ans=max(ans,tot1+tot2);
        memset(q1,0,sizeof(q1));
        memset(q2,0,sizeof(q2));
        tot1=tot2=0;
	}
	printf("%lld\n",ans);
	return 0;
}
