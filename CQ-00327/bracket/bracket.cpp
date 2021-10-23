#include<bits/stdc++.h>
using namespace std;
const int M=1e5+1,MAX=0x7fffffff/2;
//priority_queue<int, vector<int>, greater<int> > q;
int n,k;
string s;
int bj,ans;
int len;
int check1(int x) {
	for(int i=x-1; i!=-1; i--) {
		if(s[i]=='(') {
			if((x-i)<=k) bj=1;
			break;
		}
	}
	for(int i=x+1; i<len; i++) {
		if(s[i]==')') {
			if((i-x-1)<=k) bj=3;
		}
	}
	return bj;
}
int check2(int x) {
	for(int i=x-1; i!=-1; i--) {
		if(s[i]=='?'||s[i]==')') {
			if((x-i-1)<=k) bj=2;
//			else if((x-i-1>k)) bj=2;
		}
	}
	return bj;
}
int check3(int x) {
	for(int i=x-1; i!=-1; i--) {
		if(s[i]=='?'||s[i]=='(') {
			if((x-i-1>k)) bj=3;
		}
	}
	for(int i=x+1; i<len; i++) {
		if(s[i]=='?') {
			if((i-x-1)<=k) bj=3;
		}
	}
	return bj;
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	cin>>s;
	len=s.length();
	if(s[0]=='?') s[0]='(',ans++;
	if(s[len-1]=='?') s[0]=')',ans++;
	for(int i=0; i<len; i++) {
		if(s[i]=='?') {
			if(check1(i)==1) ans++,s[i]='*';
			if(check2(i)==2) ans++,s[i]='(';
			if(check3(i)==3) ans++,s[i]=')';
		}
	}
	printf("%d",ans-3);
	return 0;
}

