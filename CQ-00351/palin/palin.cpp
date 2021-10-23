#include<bits/stdc++.h>
using namespace std;
int t,n,a[200100],b[200200],l,r;
string ans;
char Dert[200100];
void Deal(int x)
{
	int yy=x-1;
	if(x>n+1&&b[yy]!=b[2*n+1-yy]) return;
//	cout<<l<<" "<<r<<endl;
	if(x==2*n+1)
	{
		string pp;
	//	cout<<endl;
		for(int i=1;i<=2*n;i++)
		{
	//		cout<<b[i]<<" ";
			if(b[i]!=b[2*n+1-i]) return;
			pp+=Dert[i];
		}
	//	cout<<pp<<endl;
		ans=min(ans,pp);
		return;
	}
	b[x]=a[l];
	Dert[x]='L';
	l++;
	Deal(x+1);
	l--;
	
	b[x]=a[r];
	Dert[x]='R';
	r--;
	Deal(x+1);
	r++;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++) 
		{
			cin>>a[i];
			ans+='Z';
		}
		l=1,r=2*n;
		Deal(1);
		if(ans[1]!='Z')cout<<ans<<endl;
		else cout<<-1<<endl;
		ans="";
	}
	
}
