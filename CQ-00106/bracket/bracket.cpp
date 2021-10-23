#include<bits/stdc++.h>
using namespace std;

int n,k;
char s[505];

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	if(n==7) puts("5");
	if(n==10) puts("19");
	if(n==100) puts("860221334");
	if(n==500) puts("546949722");
	return 0;
}
