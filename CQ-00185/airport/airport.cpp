#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
//#define int long long
using namespace std;
inline int read() {
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return s*f;
}
inline void write(int x) {
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
int n,m1,m2,mina,minb,ans,n1[100001],n2[100001];
int bi[100001],bj[100001],vsta[100001],vstb[100001];
int heada[100001],headb[100001],suma[100001],sumb[100001];
struct A {
	int x,y;
} a[100001];
struct B {
	int x,y;
} b[100001];
signed main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),mina=m1=read(),minb=m2=read();
	if(n>=m1+m2) {
		cout<<m1+m2<<endl;
		return 0;
	}
	for(int i=1; i<=m1; i++)
		a[i].x=read(),a[i].y=read();
	for(int i=1; i<=m2; i++)
		b[i].x=read(),b[i].y=read();
		
	for(int i=1; i<=m1; i++)
		for(int j=i+1; j<=m1; j++)
			if(a[i].y<=a[j].x&&bi[i]==0)bi[i]=j,vsta[j]=1,j=m1,mina--;
			
	for(int i=1; i<=m2; i++)
		for(int j=i+1; j<=m2; j++)
			if(b[i].y<=b[j].x&&bj[i]==0)bj[i]=j,vstb[j]=1,j=m2,minb--;
	if(n>=mina+minb) {
		cout<<m1+m2<<endl;
		return 0;
	}
	int p=0,q=0;
	for(int i=1; i<=m1; i++)
		if(!vsta[i])heada[++p]=i;
	for(int i=1; i<=m2; i++)
		if(!vstb[i])headb[++q]=i;
		
	for(int i=1; i<=p; i++)
		for(int j=heada[i]; j; j=bi[j])
			n1[i]++;
	for(int i=1; i<=q; i++)
		for(int j=headb[i]; j; j=bj[j])
			n2[i]++;

	for(int i=1; i<=p; i++)
		suma[i]=suma[i-1]+n1[i];
	for(int i=1; i<=q; i++)
		sumb[i]=sumb[i-1]+n2[i];
		
	for(int i=0; i<=n; i++)
		ans=max(ans,suma[i]+sumb[n-i]);
		
//	cout<<p<<" "<<q<<endl;
//	
//	for(int i=1; i<=p; i++)
//		cout<<n1[i]<<" ";
//	putchar('\n');
//	for(int i=1; i<=q; i++)
//		cout<<n2[i]<<" ";
//	putchar('\n');
//	
//	for(int i=1; i<=p; i++)
//		cout<<suma[i]<<" ";
//	putchar('\n');
//	for(int i=1; i<=q; i++)
//		cout<<sumb[i]<<" ";
//	putchar('\n');
	
	write(ans);
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*//*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
