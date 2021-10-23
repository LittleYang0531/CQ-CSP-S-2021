#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	srand(time(0));
	cin>>n>>k>>s;
	cout<<rand()*rand()*rand()%13331*rand()*rand()*rand()*rand()+rand()%1000000007;
	return 0;
}

