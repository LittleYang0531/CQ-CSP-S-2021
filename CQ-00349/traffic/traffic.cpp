# include<bits/stdc++.h>
//# define _DEBUG
# ifdef _DEBUG
# endif
# define _INOUT
# ifdef _INOUT
# endif
using namespace std;
int n,m,T;
int main()
{
 	# ifdef _INOUT
 	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	# endif
	cin>>T;
	for(register int i=1;i<=T;i++)
		cout<<rand()<<endl;
	return 0;
}

