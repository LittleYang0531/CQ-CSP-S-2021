#include<bits/stdc++.h>
using namespace std;
namespace ljh{
	template<typename T>
	void read(T&x){
		x=0;
		char ch;
		bool some=0;
		while((ch=getchar())<'0'||ch>'9')some|=ch=='-';
		while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	}template<typename T,typename...Args>
	void read(T&x,Args&...args){read(x),read(args...);}
	template<typename T>
	void write(T x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10);
		putchar(x%10+48);
	}template<typename T,typename...Args>
	void write(T x,Args...args){write(x),putchar(' '),write(args...);}
}using namespace ljh;
const int inf=1e5+10;
int n,m1,m2,sum1[inf],sum2[inf],tot,q1,q2;
struct node{
	int num,k;
}e[inf*2];
struct fj{
	int l,r;
}a[inf],b[inf];
int check(int x){
	int tot=0;
	memset(sum1,0,sizeof(sum1));
	memset(sum2,0,sizeof(sum2));
	for(int i=1;i<=m1;i++){
		bool flag=0;
		for(int j=a[i].l;j<=a[i].r;j++)if(sum1[j]>=x){
			flag=1;
			break;
		}if(!flag){
			for(int j=a[i].l;j<=a[i].r;j++)sum1[j]++;
			tot++;
		}
	}for(int i=1;i<=m2;i++){
		bool flag=0;
		for(int j=b[i].l;j<=b[i].r;j++)if(sum2[j]>=n-x){
			flag=1;
			break;
		}if(!flag){
			for(int j=b[i].l;j<=b[i].r;j++)sum2[j]++;
			tot++;
		}
	}
	return tot;
}int f(int l,int r){
	if(l>=r)return l;
	int mid=(l+r)>>1,ans1=check(mid),ans2=check(mid+1);
	if(ans1>ans2)return f(l,mid);
	return f(mid+1,r);
}bool cmp1(node x,node y){return x.num<y.num;}
bool cmp2(node x,node y){return x.k<y.k;}
bool cmp3(fj x,fj y){return x.l<y.l;}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n,m1,m2);
	for(int i=1;i<=m1;i++){
		int a,b;
		read(a,b),e[2*i-1].k=2*i-1,e[2*i-1].num=a,e[2*i].k=2*i,e[2*i].num=b;
	}sort(e+1,e+1+2*m1,cmp1);
	int bef=0;
	for(int i=1;i<=2*m1;i++){
		if(e[i].num!=bef)bef=e[i].num,e[i].num=++q1;
		else e[i].num=q1;
	}sort(e+1,e+1+2*m1,cmp2);
	for(int i=1;i<=m1;i++)a[i].l=e[2*i-1].num,a[i].r=e[2*i].num;
	sort(a+1,a+1+m1,cmp3);
	for(int i=1;i<=m2;i++){
		int a,b;
		read(a,b),e[2*i-1].k=2*i-1,e[2*i-1].num=a,e[2*i].k=2*i,e[2*i].num=b;
	}sort(e+1,e+1+2*m2,cmp1);
	bef=0;
	for(int i=1;i<=2*m2;i++){
		if(e[i].num!=bef)bef=e[i].num,e[i].num=++q2;
		else e[i].num=q2;
	}sort(e+1,e+1+2*m2,cmp2);
	for(int i=1;i<=m2;i++)b[i].l=e[2*i-1].num,b[i].r=e[2*i].num;
	sort(b+1,b+1+m2,cmp3);
	write(check(f(0,n+1)));
	return 0;
}
