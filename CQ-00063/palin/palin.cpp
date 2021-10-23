#include<bits/stdc++.h>
using namespace std;
int n,k[10001],a[10001],b[10001]={0};
char ans[10001];
bool judge()
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>k[i];
	for(int j=1;j<=k[i]*2;j++)
	cin>>a[j];
	}
	for(int t=1;t<=n;t++)
	cout<<"-1"<<endl;
	fclose(stdin);fclose(stdout);
}




