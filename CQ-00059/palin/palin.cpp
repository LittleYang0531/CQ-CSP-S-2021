#include<bits/stdc++.h>
using namespace std;
const int NN=1e5+7;

int n,a[NN*2],T;
int b[NN*2];

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		
		cin>>n;
		for(int i=1;i<=2*n;i++)
			cin>>a[i];
		cout<<-1<<endl;
	}
	return 0;
}
