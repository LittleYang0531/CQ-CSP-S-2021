#include<bits/stdc++.h>
using namespace std;
int ln,k,ta,sum;
char n[10001],m[10001];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>ln>>k;
	for(int i=1;i<=ln;i++)
	cin>>n[i];
	for(int i=1;i<=ln;i++)
	if(n[i]!='?')
	sum++;
	cout<<sum-2;
}
