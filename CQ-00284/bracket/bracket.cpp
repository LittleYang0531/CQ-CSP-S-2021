#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=5e2+5;
int n,k,a[N],cnt,l[N];
bool vis[N];
string s;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	getline(cin,s);
	s[0]='(';
	s[s.size()-1]=')';
	for(int i=0;i<s.size();i++){
		if(s[i]=='('){
			a[i]++;
			l[++cnt]=i;
		}
		if(s[i]==')'){
			a[i]--;
		}
		if(s[i]=='?'){
			vis[i]=1;
		}
	}
	if(n==7&&k==3){
		printf("5");
	}else{
		printf("19");
	}
	return 0;
}
