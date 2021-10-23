#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
using namespace std;
const int N=2e6+9;
bool ppp;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int T,n,top;
int a[N];
int o[N],last[N];
int sta[N];
int ans[N];
int tmp[N];
bool solve(int l1,int r1,int l2,int r2){
	if(l1>r1&&l2>r2)return true;
	int f=0;
	if(l1<r1&&a[l1]==a[r1])sta[++top]=0,f|=solve(l1+1,r1-1,l2,r2),top--;
	if(f)return f;
	if(l1<=r1&&l2<=r2&&a[l1]==a[l2])sta[++top]=0,f|=solve(l1+1,r1,l2+1,r2),top--;
	if(f)return f;
	if(l1<=r1&&l2<=r2&&a[r1]==a[r2])sta[++top]=1,f|=solve(l1,r1-1,l2,r2-1),top--;
	if(f)return f;
	if(l2<r2&&a[l2]==a[r2])sta[++top]=1,f|=solve(l1,r1,l2+1,r2-1),top--;
	if(f)return f;
	return f;
}
bool check(){
	rep(i,2*n){
		if(ans[i]<sta[i])return false;
		if(ans[i]>sta[i])return true;
	}return false;
}
void getres(){
	int l=1,r=n*2;
	rep(i,n){
		if(sta[i])tmp[i]=a[r--];
		else tmp[i]=a[l++];
	}
	Rof(i,n,1){
		if(a[l]==tmp[i])sta[n+(n-i)+1]=0,l++;
		else sta[n+(n-i)+1]=1,r--;
	}
	if(check())rep(i,2*n)ans[i]=sta[i];
}
bool pppp;
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();while(T--){
		n=read();top=0;rep(i,2*n)last[i]=o[i]=0,ans[i]=100;
		rep(i,2*n)a[i]=read();	
		rep(i,2*n)
			if(!last[a[i]])last[a[i]]=i;
			else o[i]=last[a[i]],o[last[a[i]]]=i;
		sta[++top]=0;if(solve(2,o[1]-1,o[1]+1,2*n))getres();top--;
		top=0;
		sta[++top]=1;if(solve(1,o[2*n]-1,o[2*n]+1,2*n-1))getres();top--;
		if(ans[1]==100)puts("-1");
		else{
			rep(i,2*n)putchar(ans[i]?'R':'L');puts("");
		}
	}
	return 0;
}

