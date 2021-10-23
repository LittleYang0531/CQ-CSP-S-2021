#include <bits/stdc++.h>
using namespace std;
int qr(){
	int x=0,f=0;
	char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?~(x-1):x;
}
int n,m1,m2,Max=0,Maxx=0,tot=0,ans,Ans;
struct node{
	int x,y;
	bool operator<(const node p)const{
		return x<p.x;
	}
}a[100005],b[100005],op[100005];
void cleanup(){
	tot=0;
}
void Up(int x){
	while(x>1){
//	cout << tot << endl;
		if(op[x].y<op[x>>1].y){
			swap(op[x].y,op[x>>1].y);
			x>>=1;
		}else{
			break;
		}
	}
}
void Down(int x){
	while((x<<1)<=tot){
		if(op[x].y>op[x<<1].y&&((x<<1|1)>tot||op[x<<1].y<op[x<<1|1].y)){
			swap(op[x],op[x<<1]);
			x<<=1;
		}else if((x<<1|1)<=tot&&op[x].y>op[x<<1|1].y&&op[x<<1|1].y<op[x<<1].y){
			swap(op[x],op[x<<1|1]);
			x=x<<1|1;
		}else{
			break;
		}
	}
}
void add(node x){
	swap(op[++tot],x);
	Up(tot);
}
void del(){
	swap(op[1],op[tot]);
	--tot;
	Down(1);
}
node get(){
	return op[1];
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=qr(),m1=qr(),m2=qr();
	for(int i=1;i<=m1;++i){
		a[i].x=qr(),a[i].y=qr();
	}
	sort(a+1,a+m1+1);
	cleanup();
	for(int i=1;i<=m1;++i){
		while(tot&&get().y<a[i].x) del();
		add(a[i]);
		Max=max(Max,tot);
	}
	for(int i=1;i<=m2;++i){
		b[i].x=qr(),b[i].y=qr();
	}
	sort(b+1,b+m2+1);
	cleanup();
	for(int i=1;i<=m2;++i){
		while(tot&&get().y<b[i].x) del();
		add(b[i]);
		Maxx=max(Maxx,tot);
	}
	for(int i=0;i<=min(Max,n);++i){
		cleanup();
		ans=0;
		for(int j=1;j<=m1;++j){
			if(i==Max) {
				ans+=m1;
				break;
			}
			while(tot&&get().y<a[j].x) del();
			if(tot<i) add(a[j]),++ans;
		}
//		cout << ans << " ";
		cleanup();
		for(int j=1;j<=m2;++j){
			if(n-i>=Maxx) {
				ans+=m2;
				break;
			} 
//			cout << tot << " ";
			while(tot&&get().y<b[j].x) del();
			if(tot<n-i) add(b[j]),++ans;
		}
//		cout << ans << " " << i << endl;
		Ans=max(Ans,ans);
	}
	cout << Ans;
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

*/
