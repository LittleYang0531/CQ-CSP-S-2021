#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int t,n,arr[MAXN*2],l[MAXN],r[MAXN];
int l1,l2,r1,r2;
string ans,nya,ret;
string check1() {
	ans="L",nya="L";
	l1=2,r1=2*n,l2=r[arr[1]],r2=r[arr[1]];
	int cnt=n-1;
	while(cnt--) {
		if(r[arr[l1]]==l2-1) {
			ans+="L";
			nya+="L";
			++l1;--l2;
			continue;
		}
		if(r[arr[l1]]==r2+1) {
			ans+="L";
			nya+="R";
			++l1;++r2;
			continue;
		}
		if(l[arr[r1]]==l2-1) {
			ans+="R";
			nya+="L";
			--r1;--l2;
			continue;
		}
		if(l[arr[r1]]==r2+1) {
			ans+="R";
			nya+="R";
			--r1;++r2;
			continue;
		}
		return "fuck";
	}
	for(int i=n-1;i>=0;--i) ans+=nya[i];
	return ans;
}
string check2() {
	ans="R",nya="L";
	l1=1,r1=2*n-1,l2=l[arr[2*n]],r2=l[arr[2*n]];
	int cnt=n-1;
	while(cnt--) {
		if(r[arr[l1]]==l2-1) {
			ans+="L";
			nya+="L";
			++l1;--l2;
			continue;
		}
		if(r[arr[l1]]==r2+1) {
			ans+="L";
			nya+="R";
			++l1;++r2;
			continue;
		}
		if(l[arr[r1]]==l2-1) {
			ans+="R";
			nya+="L";
			--r1;--l2;
			continue;
		}
		if(l[arr[r1]]==r2+1) {
			ans+="R";
			nya+="R";
			--r1;++r2;
			continue;
		}
		return "fuck";
	}
	for(int i=n-1;i>=0;--i) ans+=nya[i];
	return ans;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i) {
			scanf("%d",&arr[i]);
			l[arr[i]]=r[arr[i]];
			r[arr[i]]=i;
		}
		string ret=check1();
		if(ret!="fuck") cout<<ret<<endl;
		else {
			ret=check2();
			if(ret!="fuck") cout<<ret<<endl;
			else printf("-1\n");
		}
	}
	return 0;
}
/*
4 18 2 9 9 19 10 6 8 7 14 20 5 4 1 13 17 18 12 15 11 2 16 3 3 16 11 15 12 19 17 10 13 1 5 6 20 14 7 8
x x            o o o o o  o  o o o o  o  o                                    x x  x  x x x x  x  x x
*/
