#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=2000005;
const int inf=0x3f3f3f3f;

int n;
int a[maxn];
int pre[maxn];
int suf[maxn];
int vis[maxn];

string calc(int flag) {
	int l=2,r=2*n,sum=1,nowl=suf[1],nowr=suf[1];
	string s,t;
	s+='L',t+='L';
	while(sum<n) {
		if(flag==0) {
			if(a[l]==a[nowr+1]&&l<nowl) {
				s+='L',t+='R';
				nowr++,l++;
			} else if(a[l]==a[nowl-1]&&l<nowl-1) {
				s+='L',t+='L';
				nowl--,l++;
			} else if(a[r]==a[nowr+1]&&r>nowr+1) {
				s+='R',t+='R';
				nowr++,r--;
			} else if(a[r]==a[nowl-1]&&r>nowr) {
				s+='R',t+='L';
				nowl--,r--;
			}  else {
				return "!";
			}
		} else {
			if(a[r]==a[nowl-1]&&r>nowr) {
				s+='R',t+='L';
				nowl--,r--;
			} else if(a[r]==a[nowr+1]&&r>nowr+1) {
				s+='R',t+='R';
				nowr++,r--;
			} else if(a[l]==a[nowl-1]&&l<nowl-1) {
				s+='L',t+='L';
				nowl--,l++;
			} else if(a[l]==a[nowr+1]&&l<nowl) {
				s+='L',t+='R';
				nowr++,l++;
			}  else {
				return "!";
			}
		}
		sum++;
	}
	reverse(t.begin(),t.end());
	return s+t;
}

signed main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1; i<=2*n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<=n; i++) {
			vis[i]=0;
		}
		for(int i=1; i<=2*n; i++) {
			if(vis[a[i]]) {
				pre[i]=vis[a[i]];
				suf[vis[a[i]]]=i;
			}
			vis[a[i]]=i;
		}
		string s=calc(0);
		reverse(a+1,a+2*n+1);
		for(int i=1; i<=n; i++) {
			vis[i]=0;
		}
		for(int i=1; i<=2*n; i++) {
			if(vis[a[i]]) {
				pre[i]=vis[a[i]];
				suf[vis[a[i]]]=i;
			}
			vis[a[i]]=i;
		}
		string t=calc(1);
		if(t!="!") {
			for(char &ch:t) {
				ch=(ch=='L'?'R':'L');
			}
			t[t.length()-1]='L';
		}
		if(s=="!"&&t=="!") {
			cout<<"-1\n";
		} else if(s=="!") {
			cout<<t<<"\n";
		} else {
			cout<<s<<"\n";
		}
	}
}
