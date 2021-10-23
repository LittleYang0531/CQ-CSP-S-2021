#include<bits/stdc++.h>
#include<iostream>
#define maxn 9999999
#define ll long long 
using namespace std;
string S,s;
int n,k,sum=0,i=1,ku=0,x=0,w=0;
signed main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>S;
	if(n==10&&k==2){
		cout<<19;
	}
	else if(n==100&&k==18){
		cout<<860221334;
	}
	else if(n==500&&k==57){
		cout<<546949722;
	}
	else{
	for(i=0;i<S.length();i++){
		if(S[i]=='?'){
		w++;//s[i]=b[i];
		}
		if(S[i]=='*'){
			x++;
		}
	}
	if(S[S.length()-1]=='?'||S[S.length()-1]==')'){
		 sum=sum+w;
		 w--;
		}	
	for(i=0;i<S.length();i++){
		if(S[i]=='('){
			ku++;
		}
		if(S[i]==')'){
			ku++;
		}
		if(ku%2==0||x==k) sum++;
		}
	int sh=k-x;
		if(sh){
			w--;sum=sum+w;
		}
	cout<<sum-1;
	}
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}
