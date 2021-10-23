#include<bits/stdc++.h>
using namespace std;
int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
const int maxn = 1e6+10;
int n,a[maxn],ned[maxn];
char slv(vector<int>v1,vector<int>v2) {
	int l1=0,r1=v1.size()-1;
	int l2=0,r2=v2.size()-1;
	for(int i=2;i<=n/2;i++) {
		if(l1<r1&&				v1[l1]==v1[r1]) ++l1,--r1;
		else if(l1<=r1&&l2<=r2&&v1[l1]==v2[r2]) ++l1,--r2;
		else if(l2<r2&&			v2[l2]==v2[r2]) ++l2,--r2;
		else if(l1<=r1&&l2<=r2&&v2[l2]==v1[r1]) ++l2,--r1;
		else return 0;
	}
	return 1;
}
void ccp(vector<int>v1,vector<int>v2) {
	int l1=0,r1=v1.size()-1;
	int l2=0,r2=v2.size()-1;
	for(int i=2;i<=n/2;i++) {
		if(l1<r1&&				v1[l1]==v1[r1]) ned[n-i+1]=v1[l1],++l1,--r1,cout<<'L';
		else if(l1<=r1&&l2<=r2&&v1[l1]==v2[r2]) ned[n-i+1]=v1[l1],++l1,--r2,cout<<'L';
		else if(l2<r2&&			v2[l2]==v2[r2]) ned[n-i+1]=v2[l2],++l2,--r2,cout<<'R';
		else if(l1<=r1&&l2<=r2&&v2[l2]==v1[r1]) ned[n-i+1]=v2[l2],++l2,--r1,cout<<'R';
	}
	int n1=v1.size(),n2=v2.size();
	for(int i=n/2+1;i<n;i++) {
		if(l1<n1&&v1[l1]==ned[i]) ++l1,cout<<'L';
		if(l2<n2&&v2[l2]==ned[i]) ++l2,cout<<'R';
	}
}
signed main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int csa=read();
	while(csa--) {
		n=read()<<1;
		for(int i=1;i<=n;i++) a[i]=read();
		
		vector<int>v1,v2;int c=-1;
		v1.clear(),v2.clear();
		for(int i=2;i<=n;i++) if(a[i]==a[1]) c=i;
		for(int i=2;i<c;i++) v1.push_back(a[i]);
		for(int i=n;i>c;i--) v2.push_back(a[i]);
		if(slv(v1,v2)) {
			cout<<'L';
			ccp(v1,v2);
			cout<<"L\n";
			continue;
		}
		
		v1.clear(),v2.clear();
		for(int i=1;i<n;i++) if(a[i]==a[n]) c=i;
		for(int i=1;i<c;i++) v1.push_back(a[i]);
		for(int i=n-1;i>c;i--) v2.push_back(a[i]);
		if(slv(v1,v2)) {
			cout<<'R';
			ccp(v1,v2);
			cout<<"L\n";
			continue;
		}
		cout<<"-1\n";
	}
	return 0;
}
