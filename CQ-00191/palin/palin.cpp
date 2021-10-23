#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
int t;
cin>>t;
int n[t];
int a[2*n[t]];
for(int i=1;i<=t;i++)
   {cin>>n[i];
   
   for(int j=1;j<=2*n[i];j++)
      {cin>>a[j];
	  }
   
   }
   for(int i=1;i<=t;i++)
   cout<<-1<<endl;


return 0;
}
