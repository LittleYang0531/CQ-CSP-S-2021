#include<iostream>
using namespace std;
int t,n;
string a[1000001];
bool sou(int l,int r,string s1,string s2) {
	if(l>r) {
		for(int i=0; i<s2.length()/2; i++) if(s2[i]!=s2[s2.length()-i-1]) return 0;
		cout<<s1<<endl;
		return 1;
	}
	if(sou(l+1,r,s1+"L",s2+a[l])) return 1;
	if(sou(l,r-1,s1+"R",s2+a[r])) return 1;
	return 0;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int i=1; i<=t; i++) {
		scanf("%d",&n);
		for(int j=1; j<=n*2; j++) cin>>a[j];
		if(sou(2,2*n,"L",a[1])) continue;
		if(sou(1,2*n-1,"R",a[n])) continue;
		printf("-1\n");
	}
}
