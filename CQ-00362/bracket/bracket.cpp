#include<bits/stdc++.h>
using namespace std;
int n,k,r,ans,sum,t[510],d,e,f;
char a[510];
void find(int x) {
	if(r==1&&x!=n){
		d=0;
	}
	if(r<0) {
		return;
	}
	if(sum>k) {
		return;
	}
	if(x==n&&r==1) {
		ans=(ans+1)%1000000007;
		for(int i=1;i<=n;i++){
			cout<<a[i];
		}
		cout<<endl;
		return;
	}
	if(x==n) return;
	if(a[x]=='?') {
		a[x]='(';
		find(x);
		a[x]=')';
		find(x);
		a[x]='*';
		find(x);
		a[x]='?';
	}
	if(a[x]=='(') {
		r++;
		t[x]=sum;
		sum=0;
		find(x+1);
		r--;
		sum=t[x];
	}
	if(a[x]==')') {
		r--;
		t[x]=sum;
		sum=0;
		find(x+1);
		sum=t[x];
		r++;
	}
	if(a[x]=='*') {
		sum++;
		d++;
		find(x+1);
		sum--;
		d--;
	}
	return;
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0; i<=n; i++) {
		scanf("%c",&a[i]);
	}
	a[1]='(';
	a[n]=')';
	find(1);
	printf("%d",ans);
	return 0;
}
