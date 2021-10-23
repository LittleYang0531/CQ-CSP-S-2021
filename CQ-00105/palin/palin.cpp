#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;

int n,a[1000005],b[1000005],ans[1000005],to[1000005],p[1000005];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int check(int s)
{
	int l=1,r=n,tot=0;
	for(int i=n;i>=1;i--){
//		cout<<(s&(1<<(i-1)))<<"  "<<l<<" "<<r<<" "<<tot<<"\n";
		if(s&(1<<(i-1))){
			b[++tot]=a[r];r--;
		}
		else{
			b[++tot]=a[l];l++;
		}
	}
	for(int i=1;i<=n;i++)
		if(b[i]!=b[n-i+1])return 0;
//	for(int i=1;i<=n;i++)cout<<b[i]<<" ";
//	cout<<"^\n";
	return 1;
}
void shuc(int s)
{
	for(int i=n;i>=1;i--){
		if(s&(1<<(i-1)))cout<<"R";
		else cout<<"L";
	}
	cout<<"\n";
}
int bj=0;
void sss()
{
	int l=1,r=2*n,tot=0;
	int asl=n+n,asr=1;
	for(int i=1;i<=n;i++)if(ans[i]==1)cout<<"L";else cout<<"R";
	for(int i=1;i<=n;i++){
		if(ans[i]==1){
			b[++tot]=to[l];
			asl=min(asl,to[l]);
			l++;
		}
		else{
			b[++tot]=to[r];
			asr=max(asr,to[r]);
			r--;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(b[i]==asl){
			cout<<"L";asl++;
		}
		else if(b[i]==asr){
			cout<<"R";asr--;
		}
	}
	cout<<"\n";
}
void dfs(int k,int l,int r,int ql,int qr)
{
	if(bj)return;
	if(k==n+1){
		sss();bj=1;return;
	}
	if(!ql&&!qr){
		ans[k]=1;
		dfs(k+1,l+1,r,to[l],to[l]);
	}
	if(ql&&qr&&(to[l]==qr+1||to[l]==ql-1)){
		ans[k]=1;
		dfs(k+1,l+1,r,min(to[l],ql),max(to[l],qr));
	}
	if(!ql&&!qr){
		ans[k]=2;
		dfs(k+1,l,r-1,to[l],to[l]);
	}
	if(ql&&qr&&(to[r]==qr+1||to[r]==ql-1)){
		ans[k]=1;
		dfs(k+1,l,r-1,min(to[r],ql),max(to[r],qr));
	}
}
void solve()
{
	n=read();
	for(int i=1;i<=2*n;i++)a[i]=read();
	if(n<=10){
		n*=2;
//		check(157);
		for(int i=0;i<(1<<n);i++){
			if(check(i)){
				shuc(i);
//				cout<<i<<"&&&\n";
				return;
			}
		}
		cout<<-1<<"\n";return;
	}
	else{
		bj=0;
		for(int i=1;i<=n*2;i++)to[i]=0;
		for(int i=1;i<=n*2;i++)p[i]=0;
		for(int i=1;i<=n;i++){
			if(p[a[i]])to[i]=p[a[i]];
			else p[a[i]]=i;
		}
		for(int i=1;i<=n*2;i++)to[i]=0;
		for(int i=1;i<=n*2;i++)p[i]=0;
		for(int i=n;i>=1;i--){
			if(p[a[i]])to[i]=p[a[i]];
			else p[a[i]]=i;
		}
		dfs(1,1,2*n,0,0);
		if(!bj){
			cout<<"-1\n";return;
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=read();
	while(T--)
	{
		solve();
	}
	return 0;
}
