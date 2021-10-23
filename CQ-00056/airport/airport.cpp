#include<bits/stdc++.h>
#define N 100005
#define M 100005
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	int tmp=x<0?-x:x,cnt=0;char f[200];
	if(x<0)
		putchar('-');
	if(!x)
		putchar('0');
	while(tmp){
		f[cnt++]=tmp%10+'0';
		tmp/=10;
	}
	while(cnt)
		putchar(f[--cnt]);
}
int n,m,mm,res,ans,maxans=0;
bool c[M];
struct node{
	int x,id;
	bool operator<(const node &y){
		return x<y.x;
	}
} a[M],b[M],aa[M],bb[M];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m=read();mm=read();
	for(int i=1;i<=m;i++){
		a[i]=(node){read(),i};
		b[i]=(node){read(),i};
	}
	sort(a+1,a+1+m);
	sort(b+1,b+1+m);
	for(int i=1;i<=mm;i++){
		aa[i]=(node){read(),i};
		bb[i]=(node){read(),i};
	}
	sort(aa+1,aa+1+mm);
	sort(bb+1,bb+1+mm);
	for(int i=0;i<=n;i++){
		ans=res=0;
		memset(c,0,sizeof c);
		for(int j=1,k=1;j<=m;){
			if(a[j].x<b[k].x){
				if(res<i){
					res++;
					ans++;
				}
				else
					c[a[j].id]=1;
				j++;
			}
			else{
				if(!c[b[k].id])
					res--;
				k++;
			}
		}
		memset(c,0,sizeof c);
		res=0;
		for(int j=1,k=1;j<=m;){
			if(aa[j].x<bb[k].x){
				if(res<n-i){
					res++;
					ans++;
				}
				else
					c[aa[j].id]=1;
				j++;
			}
			else{
				if(!c[bb[k].id])
					res--;
				k++;
			}
		}
		maxans=max(maxans,ans);
	}
	write(maxans);
	return 0;
}
